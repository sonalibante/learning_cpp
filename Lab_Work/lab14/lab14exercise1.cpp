//lab 14
//exercise 1
//fall 2018
//js236

#include <iostream>
using namespace std;

//#1
void pattern (int x) {
    for (int row=1; row <=x; row++) {
        for (int col=1; col<=x; col++)
            if (col < row)
                cout << '+';
            else if (col==row)
                cout << '$';
            else
                cout << '-';
        cout << endl;
    }
}

int main() {
    pattern(5);
    cout << endl;
    pattern(9);
}
