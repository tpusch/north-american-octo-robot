#include "Customer.h"

using namespace std;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;

Customer::Customer()
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

ostream& operator<< (ostream& os, const Customer& customer){
	os << customer.firstName << " " << customer.lastName << " " << customer.customerID << " " << customer.ssn << " " << customer.address;
	return os;
}

istream& operator>> (istream& is, Customer& customer){
	string input;
	is >> customer.firstName >> customer.lastName >> customer.customerID >> customer.ssn;
	cerr << customer.firstName << customer.lastName << customer.customerID << customer.ssn;
	is >> input;
	while (input != "end"){
		cerr << input << endl;
		if (input == "accountID:"){
			//TODO this
			cout << "got an acct" << endl;
		}
		if (input == "address:"){
			is >> customer.address;
		}
		is >> input;
	}
	return is;
}

void Customer::save(ostream& output){
	output << firstName << " " << lastName << " " << customerID << " " << ssn << " " << address; 
}