// Quiz 6
// Fall 2018

#include <iostream>
using namespace std;

class Length {
private:
    int feet;       // always >=0
    float inches;   // always >=0 and <12
public:
    Length() {feet=0; inches=0.0; }
    Length(int f, float i) {feet=f; inches=i; }
    int getFeet() {return feet;}
    void setFeet(int f) {feet = f;}
    float getInches() { return inches;}
    void setInches(float i) {inches = i;}
    void display() { cout << feet << "\'-" << inches << '\"';}
    
    bool operator<(Length);    // not part of answer
    Length operator+(Length);  // not part of answer
};

bool Length::operator< (Length right) {
    if (feet == right.feet)
        return inches < right.inches;
    else
        return feet < right.feet;
}
// for operator< you could have computed the total inches of the left and
//   the right and returned (totalLeft < totalRight)

Length Length::operator+(Length right) {
    int f = feet + right.feet;        //add the feet
    float i = inches + right.inches;  //add the inches
    if(i >= 12.0) {                   //if total exceeds 12.0,
        i -= 12.0;                    //then decrease inches by 12.0 and
        f++;                          //increase feet by 1
    }
    return Length(f,i);
}

int main() {
    Length l1(4,3.0);
    Length l2(32,9.5);
    cout << boolalpha << (l2<l1) << endl;
    cout << boolalpha << (l1<l2) << endl;

    Length l3 = l1+l2;
    l3.display();
    cout << endl;
}
