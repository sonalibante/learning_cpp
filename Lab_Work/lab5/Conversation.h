// Lab 5 exercise 2, header file
// Fall 2018
// js236

#include "TextMessage.h"

class Conversation {
    
private:
    TextMessage Messages[100];
    int count;          //count of messages added
public:
    Conversation();
    void add(TextMessage);
    int getCount();
    int getSenderCount(string);
    void displayAll();
    string *getParticipants();
    int getTotalMemory();
};
