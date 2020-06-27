// File Name: PasswordManager.cpp
// Author: Sonali Bante
// Date: 3/25/2019
// Assignment Number: 4
// CS 5301.255 Spring 2019
// Instructor: Jill Seaman
/* C++  program that will Tests the password manager: password creation
and encryption. */
#include "PasswordManager.h"
#include "string"
#include "ctime"

using namespace std;

/************************************************************************
* function name: PasswordManager - Function to set default value        *
************************************************************************/
PasswordManager::PasswordManager()
{
    userName = "";
    ePassword = "";
}

/******************************************************************************
* function name: encrypt - encrypt the entered password string                *
* param-1: password  - un-encrypt password                                    *
* returns: result - returns the encrypted password                            *
******************************************************************************/
string PasswordManager:: encrypt(string password)
{
    string ePassword;
    for (int i=0; i< password.length(); i++)
    {
        ePassword += (((int)password[i] - 33) + 25) % 94 + 33;
    }
    return (ePassword);
}

/******************************************************************************
* function name: meetCriteria-check if entered password meet required criteria*
* param-1: password  - un-encrypt password                                    *
* returns: result - returns the if password changed or not                    *
******************************************************************************/
bool PasswordManager:: meetsCriteria(string password)
{
    bool flag1= false, flag2=false, flag3=false, flag4=false;

    if(password.length()>=8)
        flag1=true;

    for (int i=0; i< password.length(); i++)
    {
        if(isupper(password[i]))
        {
            flag2=true;
            break;
        }
    }

    for (int i=0; i< password.length(); i++)
    {
        if(islower(password[i]))
        {
            flag3=true;
            break;
        }
    }

    for (int i=0; i< password.length(); i++)
    {
        if(isdigit(password[i]))
        {
            flag4=true;
            break;
        }
    }

    return (flag1 && flag2 && flag3 && flag4);
}

/******************************************************************************
* function name: setUsername -check if entered password meet required criteria*
* param-1: name  - it is entered username                                     *
******************************************************************************/
void PasswordManager:: setUsername(string name)
{
    userName = name;
}

/******************************************************************************
* function name: getUsername - to get username stored in member function      *
* returns: userName - returns username                                        *
******************************************************************************/
string PasswordManager:: getUsername()
{
    return userName;
}

/******************************************************************************
* function name: setEncryptedPassword - set encrypted password to member      *
                 function                                                     *
* param-1: password  - un-encrypt password                                    *
******************************************************************************/
void PasswordManager:: setEncryptedPassword(string password)
{
    ePassword = password;
}

/******************************************************************************
* function name: getEncryptedPassword - returns encripted password member     *
* returns: ePassword - returns value of member function ePassword             *
******************************************************************************/
string PasswordManager:: getEncryptedPassword()
{
    return ePassword;
}

/******************************************************************************
* function name: setEncryptedPassword - set encrypted password to member      *
                 function                                                     *
* param-1: password  - un-encrypt password                                    *
******************************************************************************/
bool PasswordManager:: setNewPassword(string password)
{
    if(meetsCriteria(password))
    {
        setEncryptedPassword(encrypt(password));
        return true;
    }
    else
        return false;
}

/******************************************************************************
* function name: authenticate - set encrypted password to member              *
                 function                                                     *
  param-1: password  - un-encrypt password                                    *
* param-1: booleen value  - if entered password matches the actual password   *
******************************************************************************/
bool PasswordManager:: authenticate(string password)
{
    return ePassword == encrypt(password);
}
