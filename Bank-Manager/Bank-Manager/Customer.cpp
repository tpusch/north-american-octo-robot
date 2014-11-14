#include "Customer.h"

using std::istream;
using std::ostream;


Customer::Customer()
{
}


Customer::~Customer()
{
}

void Customer::listAccounts(){

};

void Customer::printCheckingValue(){

};
void Customer::printSavingsValue(){

};
void Customer::printCDValue(){

};


ostream& operator<< (ostream& os, const Customer& customer){
	os << customer.firstName << " " << customer.lastName;
	return os;
}

istream& operator>> (istream& is, Customer& customer){
	is >> customer.firstName >> customer.lastName;
	return is;
}