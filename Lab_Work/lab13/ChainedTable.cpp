//Chained Hash Table
//Lab 13
//Fall 2018
//js236

#include <iostream>
#include <cassert>

using namespace std;

class ChainedTable  {
private:
    int SIZE;  //number of chains
    struct Node {
        int key;
        Node *next;
    };
    Node** table;     // pointer to array of pointers to Nodes
    int hash(int);    // maps key to position in array

public:
    ChainedTable (int size);     //initialize all pointers to NULL
    ~ChainedTable();     //destructor, provided
    
    bool find(int);       //return true if int in table
    void insert (int);    //add int to table, no duplicates, provided
    void display();       //show elements in table
    int count();          //return number of elements

    bool operator<=(ChainedTable &);  //subset
    bool operator==(ChainedTable &);  //equality
    void remove(int);     //remove int from the table

};

// insert, provided
void ChainedTable::insert(int x) {
    
    // Do not add x if it's already in the table.
    if (find(x))
        return;
    
    Node *newNode = new Node;
    newNode->key = x;
    
    // this inserts at the front of the list.
    int pos = hash(x);
    newNode->next = table[pos];
    table[pos] = newNode;
}

// destructor, provided
ChainedTable::~ChainedTable() {
    for (int i=0; i<SIZE; i++) {
        Node *p = table[i];
        Node *n;
        while (p) {
            n = p->next;
            delete p;
            p = n;
        }
    }
}



//Add your function definitions here:

ChainedTable::ChainedTable(int size) {
    SIZE = size;
    table = new Node* [SIZE];
    for (int i=0; i<SIZE; i++)
        table[i] = NULL;
}

int ChainedTable::hash(int key) {
    return key % SIZE;
}

bool ChainedTable::find(int key) {
    int pos = hash(key);
    Node *p = table[pos];
    while (p) {
        if (p->key==key)
            return true;
        p = p->next;
    }
    return false;
}

void ChainedTable::display() {
    for (int i=0; i<SIZE; i++) {
        Node *p = table[i];
        while (p) {
            cout << p->key << " ";
            p = p->next;
        }
    }
    cout << endl;
}

int ChainedTable::count() {
    int count = 0;
    for (int i=0; i<SIZE; i++) {
        Node *p = table[i];
        while (p) {
            count++;
            p = p->next;
        }
    }
    return count;
}

bool ChainedTable::operator<=( ChainedTable & that) {
    for (int i=0; i<SIZE; i++) {
        Node *p = table[i];
        while (p) {
            if (!that.find(p->key))
                return false;
            p = p->next;
        }
    }
    return true;
}

bool ChainedTable::operator==( ChainedTable & that) {
    return operator<=(that) && count()==that.count();
}

// remove
void ChainedTable::remove(int x) {
    int pos = hash(x);
    bool find = false;
    Node *p = table[pos];
    Node *n;
    while (p && p->key != x) {
        n = p;
        p = p->next;
    }
    
    if(p != NULL){
        if (p==table[pos]) {
            table[pos] = p->next;
        } else {
            n->next = p->next;
        }
        delete p;
    }
}

int main ()
{
    ChainedTable s(5);
    s.insert(3);
    s.insert(10);
    s.insert(13);
    
    cout << "Set s: ";
    s.display();
    
    if (s.find(3))
        cout << "s contains 3" << endl;
    else
        cout << "s does not contain 3" << endl;
    if (s.find(13))
        cout << "s contains 13" << endl;
    else
        cout << "s does not contain 13" << endl;
    if (s.find(7))
        cout << "s contains 7" << endl;
    else
        cout << "s does not contain 7" << endl;

    cout << "Set d: ";
    ChainedTable d(8);
    cout << "d has " << d.count() << " elements." << endl;
    d.insert(15);
    cout << "d has " << d.count() << " elements." << endl;
    d.insert(1);
    cout << "d has " << d.count() << " elements." << endl;
    d.insert(9);
    cout << "d has " << d.count() << " elements." << endl;
    d.insert(15);
    cout << "d has " << d.count() << " elements." << endl;
    d.insert(13);
    cout << "d has " << d.count() << " elements." << endl;
    cout << "Set d: ";
    d.display();

    ChainedTable b(12);
    b.insert(1);
    b.insert(9);
    b.insert(15);
    cout << "Set b: ";
    b.display();
    
    if (b <=  d)
        cout << "b <= d" << endl;
    else
        cout << "b is not a subset of d" << endl;
    
    b.insert(27);
    cout << "Set b: ";
    b.display();
    cout << "Set d: ";
    d.display();

    if (b <= d)
        cout << "after insert, b <= d" << endl;
    else
        cout << "after insert, b is not a subset of d" << endl;
    
    ChainedTable c(7);
    c.insert(1);
    c.insert(9);
    c.insert(15);
    cout << "Set c: ";
    c.display();
    cout << "Set b: ";
    b.display();

    if (b ==  c)
        cout << "b == c" << endl;
    else
        cout << "b != c" << endl;

    c.insert(28);
    if (b ==  c)
        cout << "b == c" << endl;
    else
        cout << "b != c" << endl;

    ChainedTable e(6);
    e.insert(28);
    e.insert(1);
    e.insert(9);
    e.insert(15);
    if (c ==  e)
        cout << "c == e" << endl;
    else
        cout << "c != e" << endl;

    cout << "Set d: ";
    d.display();
    d.remove(13);
    cout << "Set d: ";
    d.display();
    d.remove(1);
    cout << "Set d: ";
    d.display();
    d.remove(19);
    cout << "Set d: ";
    d.display();
    d.remove(15);
    cout << "Set d: ";
    d.display();
    d.remove(9);
    cout << "Set d: ";
    d.display();
};

/*
 Set s: 10 13 3
 s contains 3
 s contains 13
 s does not contain 7
 Set d: d has 0 elements.
 d has 1 elements.
 d has 2 elements.
 d has 3 elements.
 d has 3 elements.
 d has 4 elements.
 Set d: 9 1 13 15
 Set b: 1 15 9
 b <= d
 Set b: 1 27 15 9
 Set d: 9 1 13 15
 after insert, b is not a subset of d
 Set c: 15 1 9
 Set b: 1 27 15 9
 b != c
 b != c
 c == e
 Set d: 9 1 13 15
 Set d: 9 1 15
 Set d: 9 15
 Set d: 9 15
 Set d: 9
 Set d:
 
 */
