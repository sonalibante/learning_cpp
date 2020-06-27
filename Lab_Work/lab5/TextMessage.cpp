// Lab 5 exercise 1, implementation file
// Fall 2018
// js236

#include <iostream>
#include <iomanip>
using namespace std;

#include "TextMessage.h"

TextMessage ::TextMessage () {
    message ="";
    sender="";
    time = "";
}
TextMessage ::TextMessage (string amessage , string ansender, string atime) {
    message  = amessage ;
    sender = ansender;
    time = atime;
}

string TextMessage ::getMessage () {
    return message ;
}
void TextMessage ::setMessage (string amessage ) {
    message  = amessage ;
}

string TextMessage ::getSender() {
    return sender;
}
void TextMessage ::setSender(string asender) {
    sender = asender;
}

string TextMessage ::getTime() {
    return time;
}
void TextMessage ::setTime(string atime) {
    time = atime;
}

int TextMessage ::getMemory() {
    return message.size()*2;
}

void TextMessage ::display() {
    cout << sender << " at " << time << ":" << endl;
    cout << "=> " << message << endl;
}
