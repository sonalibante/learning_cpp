// Quiz 7
// Fall 2018

#include <iostream>
using namespace std;

class Content {
private:
    string title;
public:
    Content(string t) { title = t; }
    string getTitle() { return title; }
    virtual double getPrice() = 0;
};

class Song : public Content{
public:
    Song(string t): Content(t) { };
    double getPrice() { return 1.29; }
};

class Movie : public Content {
private:
    double size;
public:
    Movie(string t, double s): Content(t) { size = s;}
    double getPrice() { return 5.99+(0.005*size); }
};

int main () {
    
    Content * items[3] = { new Movie("Sing",950),  new Song("Under Pressure"),
        new Song("I'm Still Standing")};
    
    for (int i = 0; i < 3; i++)
        cout << items[i] -> getTitle() << " "
        << items[i] -> getPrice() << endl;
}

