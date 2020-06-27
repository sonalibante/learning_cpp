// Numbers
// Lab 7 exercise 2
// Fall 2018
// js236

#include <iostream>
#include <cmath>
using namespace std;

class Number {

public:
    Number() {}
    virtual void display() = 0;
    virtual void addInt(int n) = 0;
};


class Integer : public Number {
private:
    int value;
public:
    Integer (int i) {
        value = i;
    }
    void display() {
        cout << value;
    }
    void addInt(int n) {
        value+=n;
    }
};

class Fraction : public Number {
private:
    int numerator;
    int denomenator;
public:
    Fraction (int n, int d) {
        numerator = n;
        denomenator = d;
    }
    void display() {
        cout << numerator << "/" << denomenator;
    }
    void addInt(int n) {
        numerator = numerator + (denomenator*n);
    }
};

class Fixed2 : public Number {
private:
    int value;
public:
    Fixed2(int v)  {
        value = v;
    }
    void display() {
        cout << value/100 << "." << value%100;
    }
    void addInt(int n) {
        value += n*100;
    }
};

// provided:
int main () {
    Number *collection[] = {
        new Integer(60),
        new Fraction(3,5),
        new Fixed2(3152)
    };

    for (int i=0; i<3; i++) {
        collection[i]->display();
        cout << " ";
    }
    cout << endl;
    for (int i=0; i<3; i++) {
        collection[i]->addInt(5);
    }
    for (int i=0; i<3; i++) {
        collection[i]->display();
        cout << " ";
    }
    cout << endl;
}
/*
 Expected output:
 60 3/5 31.52
 65 28/5 36.52
*/
