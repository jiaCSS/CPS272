#pragma once
#include <stdexcept>
#include <iostream>
#include<iomanip>
#include <fstream>
#include<map>
#include "hashtb1.cpp"
using namespace std;

struct Password
{
    void setKey(string newKey) { username = newKey; }
    string getKey() const { return username; }

    //this hash converts a string to an integer
    int hash(const string str) const
    {
        int val = 0;

        for (unsigned int i = 0; i < str.length(); i++)
            val += str[i];
        return val;
    }
   
    string username,
        password;
};

int  main()
{
    HashTbl<Password, string> passwords(10);
    Password tempPass;
    string name;      // user-supplied name
    string pass;      // user-supplied password
     
    
        //*********************************************************
        // Step 1: Read in the password file
        //*********************************************************
    ifstream passFile("password.txt");

    if (!passFile)
    {
        cout << "Unable to open 'password.txt'!" << endl;
        exit(0);
    }
    while (!passFile.eof() && !passwords.isFull())
    {
       
        passFile >> tempPass.username;
        passFile >> tempPass.password;
        passwords.insert(tempPass);//not sure
    }

    cout << "Printing the hash table:..." << endl;
   
    passwords.showStructure();

    //*********************************************************
    // Step 2: Prompt for a Login and Password and check if valid
    //*********************************************************
    cout << "\nLogin: ";
    while (cin >> name)  // to quit, type CTRL Z in Visual C++
    {
        cout << "Password: ";
        cin >> pass;
        
        if(passwords.retrieve(name, tempPass)) {
            // check if passowrd maches what was entered
            if (tempPass.password == pass && tempPass.username == name) {
                cout << "Authentication successful" << endl;
            }
            else {
                cout << "Authentication failure" << endl;
            }

        }
        else {
            cout <<name<< " is not found in hash table." << endl;
        }
        
      
        cout << "\nLogin: ";
    }
    cout << endl;
    passFile.close();

    return 0;
}
