// Lab 5 exercise 1, header file
// Fall 2018
// js236

#include <string>
using namespace std;

class TextMessage  {
    
private:
    string message;
    string sender;
    string time;

public:
    TextMessage();
    TextMessage(string,string,string);
    string getMessage();
    void setMessage(string);
    string getSender();
    void setSender(string);
    string getTime();
    void setTime(string);
    int getMemory();
    void display();
};
