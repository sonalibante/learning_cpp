// File Name: PasswordManager.h
// Author: Sonali Bante
// Date: 3/25/2019
// Assignment Number: 4
// CS 5301.255 Spring 2019
// Instructor: Jill Seaman
/* C++  program that will Tests the password manager: password creation
and encryption. */

#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include "string"
#include "ctime"

using namespace std;

class PasswordManager
{
private:
    string userName;               // Username of the account
    string ePassword;              // Encrypted password of the account
    string encrypt(string);        // function to Encrypt string
    bool meetsCriteria(string);    // to verify password requirements

public:
    PasswordManager();             // default constructor
    void setUsername(string);      // assign username
    string getUsername();          // return username
    void setEncryptedPassword(string); // assign Encrypted password
    string getEncryptedPassword();     // return Encrypted password
    bool setNewPassword(string);//assign new password, returns if it did or not
    bool authenticate(string);         // check the old password is same or not
};

#endif // PASSWORDMANAGER_H
