#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <vector>
//#include "Account.h"

class Account;

using namespace std;
using std::list;
using std::string;
using std::vector;

class Customer
{	
public:
    //constructor/destructor
    Customer(){};
    Customer(string, string, int, string);
    ~Customer(){};

    //prototypes
    void listAccounts();
    void printAccount(ostream&);
    void addAccount(Account*);
    void save(ostream&);
	void printAccountValues(ostream& os);

    //overloaded operators
    friend std::ostream& operator<< (std::ostream&, const Customer&);
    friend std::istream& operator>> (std::istream&, Customer*);
    
    //Simple setters
    void setAddress(string a){ address = a; };

    //Simple getters
    int getID(){ return customerID; }
    string getFirstName(){ return firstName; }
    string getLastName(){ return lastName; }
    string getAddress(){ return address; }
    string getSSN(){ return ssn; }	
    vector<int> accountNums;
    
protected:
    //Member variables
    int customerID;
    string firstName;
    string lastName;
    string address;
    string ssn;

    //A list of pointers, pointing to accounts
    vector<Account*> myAccounts;
    
};