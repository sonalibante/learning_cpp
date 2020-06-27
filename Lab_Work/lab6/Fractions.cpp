//Lab 6 Exercise 1: FunctionType
//Fall 2018
//js236

#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

class FractionType
{
private:
    int numerator; // for numerator of fraction
    int denominator; // for denominator of fraction
    
public:
    //default constructor
    FractionType();
    FractionType(int,int); // parameterized constructor
    // getter and setter
    int getNumerator() ;
    int getDenominator() ;
    void setNumerator(int n);
    void setDenominator(int d);
    // overloading functions for arithametic operators
    FractionType operator + ( FractionType );
    FractionType operator * ( FractionType );
    // overloading functions of relational operators
    bool operator == ( FractionType );
    bool operator < ( FractionType );
    
};


// initilize default values for numerator and denominator variables
FractionType ::FractionType()
{
    numerator=0;
    denominator=1;
}

// assign passed values to the member variables
FractionType ::FractionType(int n,int d)
{
    assert (d!=0);
    numerator=n;
    denominator=d;
}

// getter and setter 

int FractionType ::getNumerator()
{
    return numerator;
}
int FractionType ::getDenominator()
{
    return denominator;
}
void FractionType ::setNumerator(int n)
{
    numerator=n;
}
void FractionType ::setDenominator(int d)
{
    denominator=d;
}
// arithametic operators overloading
FractionType FractionType::operator + ( FractionType right)
{
    int n  = (numerator*right.denominator)+(denominator*right.numerator);//ad+bc
    int d = denominator*right.denominator; //b*d
    FractionType tmp(n,d);
    return (tmp);
}

FractionType FractionType::operator * (  FractionType right)
{
    int ac = numerator*right.numerator;     //a*c
    int bd = denominator*right.denominator; //b*d
    FractionType tmp(ac,bd);
    return (tmp);
}

//relational operators overloading functions
bool FractionType::operator < ( FractionType right)
{
    int ad = numerator * right.denominator;
    int bc = denominator * right.numerator;
    
    return (ad < bc);
}

bool FractionType::operator == ( FractionType right)
{
    int ad= numerator * right.denominator;
    int bc= denominator * right.numerator;
    
    return (ad == bc);
}


int main()
{
    FractionType x(2,2),y(5,10),z; //objects of FractionType Class
    
    z=x+y;
    cout<<"x+y  = " << z.getNumerator()<<"/"<<z.getDenominator()<<endl;
    
    z=x*y;
    cout<<"x*y  = " <<z.getNumerator()<<"/"<<z.getDenominator()<<endl;

    cout <<"x<y  = " << boolalpha << (x<y) << endl;
    
    cout <<"x==y = " << boolalpha << (x==y) << endl;
    
    FractionType w(1,2);
    cout <<"w==y = " << boolalpha << (w==y) << endl;

    return 0;
}
/*
 expected output:
 x+y  = 30/20
 x*y  = 10/20
 x<y  = false
 x==y = false
 w==y = true
 
 */
