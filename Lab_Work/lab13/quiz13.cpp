// Quiz 13: Sets and hash tables
// Fall 2018
#include <iostream> 
using namespace std;

//given:
class IntSet  {
private:
    int intSet[100];  //array of elements
    int count;        //number of elements currently in array
public:
    IntSet () { count = 0; }
    void insert(int);  //assume this is already implemented
    bool member(int);
    IntSet operator+(IntSet);
    IntSet operator-(IntSet);
    void display(); //for testing
};
void IntSet::insert(int x) {
    if (!member(x) && count<100) {
        intSet[count] = x;
        count++;
    }
}
void IntSet::display() {
    for (int i=0; i<count; i++)
        cout << intSet[i] << " ";
    cout << endl;
}
// solution below
bool IntSet::member(int x) {
    for (int i=0; i<count; i++) {
        if (intSet[i]==x)
            return true;
    }
    return false;
}

IntSet IntSet::operator+(IntSet rhs) {
    IntSet newSet;
    for (int i=0; i<count; i++)
        newSet.insert(intSet[i]);
    for (int i=0; i<rhs.count; i++)
        newSet.insert(rhs.intSet[i]);
    return newSet;
}

IntSet IntSet::operator-(IntSet rhs) {
    IntSet newSet;
    for (int i=0; i<count; i++)
        if (!rhs.member(intSet[i]))
           newSet.insert(intSet[i]);
    return newSet;
}



int main () {
    IntSet a;
    a.insert(5);
    a.insert(7);
    
    IntSet b;
    b.insert(7);
    b.insert(8);
    b.insert(10);
    
    if (b.member(7)) cout << "7 is a member of b" << endl;
    else cout << "7 is not a member of b" << endl;
    
    IntSet c = b-a;
    c.display();
    
    IntSet d = a-b;
    d.display();
    
    IntSet e = a+b;
    e.display();
    
}
