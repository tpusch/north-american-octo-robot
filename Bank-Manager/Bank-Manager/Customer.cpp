#include "Customer.h"
#include "Account.h"

#include <sstream>

using namespace std;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

Customer::Customer(string fname, string lname, int id, string ss){
    firstName = fname;
    lastName = lname;
    customerID = id;
    ssn = ss;
}

void Customer::addAccount(Account* account){
    myAccounts.push_back(account);
}

//Print all accounts associated with customer
void Customer::printAccount(ostream& os){
    os << "\nCustomer: " << firstName << " " << lastName;
    if (!myAccounts.empty()){
        //Loop from 0 to size of accountNums vector. Prints corresponding accounts
        for (unsigned i = 0; i < myAccounts.size(); i++){
            os << "\nAccount ID: " << myAccounts.at(i)->getID();
        }
    }
    else{
        os << "\nCustomer has no accounts";
    }
}

//overload <<
ostream& operator<< (ostream& os, const Customer& customer){
    os << customer.firstName << " " << customer.lastName << " " << customer.customerID 
       << " " << customer.ssn << " " << customer.address;
    return os;
}

//overload >>
istream& operator>> (istream& is, Customer* customer){
    string line;
    string input;

    getline(is, line);
    istringstream row(line);

    row >> customer->firstName >> customer->lastName >> customer->customerID >> customer->ssn;
    while (row>>input){
        if (input == "account:"){
            //TODO this
            int accountNum;
            row >> accountNum;
            customer->accountNums.push_back(accountNum);
        }
        if (input == "address:"){
            getline(row, customer->address);
        }
    }
    return is;
}

//saves to text file
void Customer::save(ostream& output){
    output << firstName << " " << lastName << " " << customerID << " " << ssn << " ";
    //Loop from 0 to size of accountNums vector, saves info to text file in input format
    for (int i = 0; i < myAccounts.size(); i++){
        output << "account: " << myAccounts.at(i)->getID() << " ";
    }
    output << "address: "<< address;
}