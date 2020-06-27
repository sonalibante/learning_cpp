// File Name: PasswordDriver.cpp
// Author: Sonali Bante
// Date: 3/25/2019
// Assignment Number: 4
// CS 5301.255 Spring 2019
// Instructor: Jill Seaman
/* C++  program that will Tests the password manager: password creation
and encryption. */

#include "PasswordManager.h"
#include <iostream>
#include <fstream>
using namespace std;

/******************************************************************************
* function name: main - Function will allow the user to change their password.*
******************************************************************************/

int main ()
{
    PasswordManager pwMan[3];  //array of 3 instances of PasswordManager class
    ifstream fileInput("passwords.txt");  //using passwords.txt file
    string netID, oldP, newP;  // variables to store user response

    if(!fileInput)                       // prints error if file not found.
    {
        cout << "Error! Password File Not Found"<< endl;
        return 0;
    }

    for(int i=0; i<3; i++)            // reading the input file into variables
    {
        //variables to store values from input file into class members
        string ID,PASSWORD;
        fileInput >> ID;
        pwMan[i].setUsername(ID);
        fileInput >> PASSWORD;
        pwMan[i].setEncryptedPassword(PASSWORD);
    }

    fileInput.close();                   //Closing the input file here!

    cout<< "Critera for password:\nIt is at least 8 characters long, ";
    cout<< "it contains at least one uppercase letter, one lowercase letter";
    cout<< "and one digit"<< endl;

    cout<< "Please enter your username: ";
    cin>> netID;
    cout<< "Please enter your old password: ";
    cin>> oldP;
    cout<< "Please enter your new password: ";
    cin>> newP;

    //Checking if netID exist in input file
    int index;          // index of perticular member function in class
    bool flag=false;    // flag variable to check when it becomes true
    for(int i=0; i<3; i++)
    {
        if(pwMan[i].getUsername() == netID)
        {
            flag=true;
            index=i;
            break;
        }
    }

    if(!flag)
        cout<< "NetID is invalid, password not changed."<< endl;

    // authenticating if old password is correct
    else if(!pwMan[index].authenticate(oldP))
        cout<< "Old password is incorrect."<< endl;

    // checking if new password meets criteria and changing password if true
    else if(pwMan[index].setNewPassword(newP)== true)
    {
        cout << "Password has been changed for netID: ";
        cout << pwMan[index].getUsername()<< endl;
    }
    else
        cout << "New Password does not meet criteria.";

    /*outputing the three encrypted passwords to the file “password.txt”,
    (overwriting anything that was previously in the file)*/
    ofstream outputFile("passwords.txt");
    for(int i=0; i<3; i++)
    {
        outputFile << pwMan[i].getEncryptedPassword()<< endl;
    }
    outputFile.close();
}
