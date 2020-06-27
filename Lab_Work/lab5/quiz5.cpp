// Quiz 5
// Fall 2018

#include <iostream>
using namespace std;

class LabGrade
{
private:
    string name;
    int correctness;
    int style;
public:
    LabGrade (string n, int c, int s) {name=n; correctness=c; style=s; }
    void setName(string n) { name = n; }
    void setCorrectness(int c) {correctness = c; }
    void setStyle(int s) {style = s; }
    string getName() { return name; }
    int getCorrectness() { return correctness; }
    int getStyle() { return style; }
    int totalScore() { return correctness+style; }
    void display()   {
        cout << name << " " << correctness << " " << style << " " <<
        totalScore() << endl;
    }
};

int main()
{
    LabGrade students[3] =  {
        LabGrade("Smith", 80, 15),
        LabGrade("Jones", 65, 18),
        LabGrade("Brown", 75, 20)
    };
    for (int i=0; i<3; i++) {
        students[i].display();
    }
}




