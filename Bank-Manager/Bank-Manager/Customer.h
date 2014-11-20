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
    Customer();
    ~Customer();

    void listAccounts();
	void printAccount(ostream&);
	void addAccount(int);
	void save(ostream&);

    //returns a pointer to a list of account pointers
    //vector<Account*> getAccounts(){ return accountsPtr; }

    //overloaded operators
    friend std::ostream& operator<< (std::ostream&, const Customer&);
    friend std::istream& operator>> (std::istream&, Customer&);

	//Simple getters
	int getID(){ return customerID; }
	string getFirstName(){ return firstName; }
	string getLastName(){ return lastName; }
	string getAddress(){ return address; }
	string getSSN(){ return ssn; }

	

protected:

    int customerID;

    string firstName;
    string lastName;

    string address;
    string ssn;

	vector<int> accountNums;
    //A list of pointers, pointing to accounts
    vector<Account*> myAccounts;
    //A pointer pointing to a list of account pointers
    //This is a single pointer
    vector<Account>* accountsPtr;
};

