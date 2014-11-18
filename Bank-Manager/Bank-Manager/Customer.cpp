#include "Customer.h"

using namespace std;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

Customer::Customer()
{
}

Customer::Customer(string line)
{
}


Customer::~Customer()
{
}

void Customer::listAccounts(){
//    for (unsigned i = 0; i < accountsPtr.size(); i++)
//    {
//        cout << getAccounts()[i];
//    }
};

void Customer::printCheckingValue(){
    
};
void Customer::printSavingsValue(){

};
void Customer::printCDValue(){

};

ostream& operator<< (ostream& os, const Customer& customer){
	os << customer.firstName << " " << customer.lastName << " " << customer.customerID << " " << customer.ssn << " " << customer.address;
	return os;
}

istream& operator>> (istream& is, Customer& customer){
	is >> customer.firstName >> customer.lastName >> customer.customerID >> customer.ssn >> customer.address;
	return is;
}
