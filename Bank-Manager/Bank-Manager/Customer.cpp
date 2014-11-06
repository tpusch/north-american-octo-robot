#include "Customer.h"

using std::istream;
using std::ostream;


Customer::Customer()
{
}


Customer::~Customer()
{
}

void Customer::printName(ostream& os){
	os << firstName << " " << lastName << " ";
}
