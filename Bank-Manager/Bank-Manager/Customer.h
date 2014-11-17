#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>

class Account;

using namespace std;
using std::list;
using std::string;
using std::vector;

class Customer
{
	
public:
    //constructor/destructor
    Customer();
    Customer(string);
    ~Customer();

    //accessors/setters
    int getID(){ return customerID; }
    void setID(const int id){ customerID = id; }

    string getFirstName(){ return firstName; }
    void setFirstName(const string& fname){ firstName = fname; }

    string getLastName(){ return lastName; }
    void setLastName(const string& lname){ lastName = lname; }

    string getAddress(){ return address; }
    void setAddress(const string& add){ address = add; }

    string getSSN(){ return ssn; }
    void setSSN(const string& social){ ssn = social; }

    void listAccounts();

    void printCheckingValue();
    void printSavingsValue();
    void printCDValue();

    //returns a pointer to a list of account pointers
    vector<Account*> getAccounts(){ return accountsPtr; }

    //TODO: overload >> and <<
    friend std::ostream& operator<< (std::ostream&, const Customer&);
    friend std::istream& operator>> (std::istream&, Customer&);


protected:
    int customerID;

    string firstName;
    string lastName;

    string address;
    string ssn;

    //A list of pointers, pointing to accounts
    vector<Account*> accounts;
    //A pointer pointing to a list of account pointers
    //This is a single pointer
    vector<Account*> accountsPtr;
};

