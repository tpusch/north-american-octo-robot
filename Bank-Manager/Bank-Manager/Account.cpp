#include "Account.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

//method to add transactions to vector
void Account::addTransaction(Transaction newTran)
{
	transactions.push_back(newTran);
}

//method to sort transactions vector
void Account::sortTransactions()
{
	sort(transactions.begin(), transactions.end());
}

istream& operator>>(istream& input, Account& account)
{
	input >> account.dateOpened >> account.type >> account.accountID >> account.balance;
	return input;
}

//print report method with correct precision for better display of dollars/cents
void Account::generateReport(ostream& output)
{
	//print account/customer info & opening balance
	output << "Account ID: " << accountID << "\n";
	for (unsigned i = 0; i < customers.size(); i++)
	{
		output << "CustomerID: " << customers[i]->getID();
		output << "Name: " << customers[i];
	}
	output << "Opening Balance: $" << fixed << setprecision(2) << balance << "\n";

	//loop that will go through transactions vector starting at index 0, 
	//adding 1 to i after each iteration, and continuing
	//until it has reached the end of the vector.
	for (unsigned i = 0; i < transactions.size(); i++)
	{
		//print transaction
		output << transactions.at(i);

		//add to balance
		if (transactions.at(i).getType() == 'd' || transactions.at(i).getType() == 'D')
		{
			balance += transactions.at(i).getAmount();
		}

		//check for overdraft and update balance
		if (transactions.at(i).getType() == 'w' || transactions.at(i).getType() == 'W' ||
			transactions.at(i).getType() == 'f' || transactions.at(i).getType() == 'F')
		{
			if (balance >= transactions.at(i).getAmount())
			{
				balance -= transactions.at(i).getAmount();
			}
			//if withdrawal exceeds balance, print overdraft message and remove 25 from balance
			else
			{
				output << "Failed!\n" << transactions.at(i).getDate();
				output << " Overdraft Fee, $25.00 to bank. ";
				balance -= 25;
			}
		}
		if (transactions.at(i).getType() == 'c' || transactions.at(i).getType() == 'C')
		{
			balance += transactions.at(i).getAmount();
		}

		//print current balance
		output << "Balance: $" << balance << "\n";
	}
}

void Account::save(ostream& output){
	output << dateOpened << " " << type << " " << accountID << " " << balance;
}