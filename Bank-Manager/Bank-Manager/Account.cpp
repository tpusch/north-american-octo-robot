#include "Account.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

//method to add transactions to vector
void Account::addTransaction(const Transaction* newTran)
{
    transactions.push_back(newTran);
}

//method to sort transactions vector
void Account::sortTransactions()
{
    sort(transactions.begin(), transactions.end());
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
        output << transactions[i];        
        
        //add to balance
        if (transactions[i]->getType() == 'd' || transactions[i]->getType() == 'D')
        {
            balance += transactions[i]->getAmount();
        }
        
        //check for overdraft and update balance
        if (transactions[i]->getType() == 'w' || transactions[i]->getType() == 'W')
        {
            if (balance >= transactions[i]->getAmount())
            {
                balance -= transactions[i]->getAmount();
            }
            //if withdrawal exceeds balance, print overdraft message and remove 25 from balance
            else
            {
                output << "Failed!\n" << transactions[i]->getDate();
                output << " Overdraft Fee, $25.00 to bank. ";
                balance -= 25;
            }
        }
        
        //print current balance
        output << "Balance: $" << balance << "\n";
    }
}

void Account::save(ostream& output){

}