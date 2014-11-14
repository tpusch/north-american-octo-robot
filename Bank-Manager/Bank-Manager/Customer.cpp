#include "Customer.h"

using std::istream;
using std::ostream;


Customer::Customer()
	:firstName("John"),
	lastName("Doe"),
	customerID(666)
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

void Customer::save(std::ostream& out){

}

ostream& operator<< (ostream& os, const Customer& customer){
	os << customer.firstName << " " << customer.lastName;
	return os;
}

istream& operator>> (istream& is, Customer& customer){
	is >> customer.firstName >> customer.lastName;
	return is;
}