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
    void setAddress(string a){ address = a; }
    void setFirstName(string fname){ firstName = fname; }
    void setLastName(string lname){ lastName = lname; }
    void setSSN(string s){ ssn = s; }
    void setUName(string u){ uname = u; }
    void setPass(string p){ pass = p; }
    void setID(int i){ customerID = i; }

    //Simple getters
    int getID(){ return customerID; }
    string getFirstName(){ return firstName; }
    string getLastName(){ return lastName; }
    string getAddress(){ return address; }
    string getSSN(){ return ssn; }
    string getUName(){ return uname; }
    string getPass(){ return pass; }
    vector<Account*> getAccounts(){return myAccounts;}
    
    vector<int> accountNums;
    
protected:
    //Member variables
    int customerID;
    string firstName, lastName, address, ssn, uname, pass;

    //A list of pointers, pointing to accounts
    vector<Account*> myAccounts;    
};