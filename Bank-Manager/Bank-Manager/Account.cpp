#include "Account.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

//method to add transactions to vector
void Account::addTransaction(Transaction* newTran){
    transactions.push_back(newTran);
}

void Account::addCustomer(Customer* newCust){
    customers.push_back(newCust);
}

//method to sort transactions vector
void Account::sortTransactions(){
    sort(transactions.begin(), transactions.end(), compare);
}

//overload >>
istream& operator>>(istream& input, Account& account){
    input >> account.type >> account.accountID >> account.dateOpened >> account.balance;
    return input;
}

//overload <<
ostream& operator<<(ostream& output, const Account& account){
    output << "Account #: " << account.accountID << "  Date Opened: " << account.dateOpened;
    if (account.type == "c" || account.type == "C"){
        output << "  Type: Checking  Balance: ";
    }
    else if (account.type == "s" || account.type == "S"){
        output << "  Type: Savings  Balance: ";
    }
    else if (account.type == "cd" || account.type == "CD"){
        output << "  Type: Certificate of Deposit  Balance: ";
    }
    output << account.balance << "\n";
    return output;
}

//get total value for an account
double Account::getValue(){
    double value = balance;
    sortTransactions();
    //Loop from 0 to size of transactions vector. Uses update balance method to update value of account
    for (unsigned i = 0; i < transactions.size(); i++){
        value = updateBalance(transactions.at(i), value);
    }
    return value;
}

//time saver, just updates balance based on transaction type
double Account::updateBalance(Transaction* transaction, double value){
    if (transaction->getType() == 'd' || transaction->getType() == 'D'){
        value += transaction->getAmount();
    }
    //check for overdraft and update balance
    if (transaction->getType() == 'w' || transaction->getType() == 'W' ||
        transaction->getType() == 'f' || transaction->getType() == 'F'){
        if (value >= transaction->getAmount()){
            value -= transaction->getAmount();
        }
        //if withdrawal exceeds balance, print overdraft message and remove 25 from balance
        else{
            value -= 25;
        }
    }
    if (transaction->getType() == 'c' || transaction->getType() == 'C'){
        value += transaction->getAmount();
    }
    return value;
}

//will generate monthly report, prints accountID, customers associated, gets
void Account::generateMonthlyReport(ostream& output, int month, int year){
    sortTransactions();
    double cumulativeBalance = balance;  
    
    //output account and customers associated
    output << "\nAccount ID: " << accountID << "\n";
    //Loop from 0 to size of customers vector. Prints all customers associated with account
    for (unsigned i = 0; i < customers.size(); i++){
        output << "CustomerID: " << customers.at(i)->getID();
        output << " Name: " << customers.at(i)->getFirstName() << " " << customers.at(i)->getLastName() << "\n";
    }
    //Loop from 0 to size of transactions vector. Prints transactions that occurred in month
    for (unsigned i = 0; i < transactions.size(); i++){
        //check if transaction is in month desired and add it to output
        if (transactions.at(i)->getDate().getMonth() == month &&
            transactions.at(i)->getDate().getYear() == year){   
            //print transaction
            output << *transactions.at(i);

            //add to balance
            if (transactions.at(i)->getType() == 'd' || transactions.at(i)->getType() == 'D'){
                cumulativeBalance += transactions.at(i)->getAmount();
            }

            //check for overdraft and update balance
            if (transactions.at(i)->getType() == 'w' || transactions.at(i)->getType() == 'W' ||
                transactions.at(i)->getType() == 'f' || transactions.at(i)->getType() == 'F'){
                if (cumulativeBalance >= transactions.at(i)->getAmount()){
                    cumulativeBalance -= transactions.at(i)->getAmount();
                }
                //if withdrawal exceeds balance, print overdraft message and remove 25 from balance
                else{
                    output << "Failed!\n" << transactions.at(i)->getDate();
                    output << " Overdraft Fee, $25.00 to bank. ";
                    cumulativeBalance -= 25;
                }
            }
            if (transactions.at(i)->getType() == 'c' || transactions.at(i)->getType() == 'C'){
                cumulativeBalance += transactions.at(i)->getAmount();
            }
            output << "Balance: $" << cumulativeBalance << endl;
        }
        //if transaction isn't in desired month, simply update balance
        else{
            cumulativeBalance = updateBalance(transactions.at(i), cumulativeBalance);
        }
    }
}

//print report method with correct precision for better display of dollars/cents
void Account::generateReport(ostream& output)
{
    sortTransactions();
    //print account/customer info & opening balance
    output << "Account ID: " << accountID << "\n";
    //Loop from 0 to size of customers vector
    for (unsigned i = 0; i < customers.size(); i++){
        output << "CustomerID: " << customers[i]->getID();
        output << "Name: " << customers[i] << "\n";
    }
    output << "Opening Balance: $" << fixed << setprecision(2) << balance << "\n";

    //loop that will go through transactions vector starting at index 0, 
    //adding 1 to i after each iteration, and continuing
    //until it has reached the end of the vector.
    for (unsigned i = 0; i < transactions.size(); i++)
    {
        //print transaction
        output << *transactions.at(i);

        //add to balance
        if (transactions.at(i)->getType() == 'd' || transactions.at(i)->getType() == 'D'){
            balance += transactions.at(i)->getAmount();
        }

        //check for overdraft and update balance
        if (transactions.at(i)->getType() == 'w' || transactions.at(i)->getType() == 'W' ||
            transactions.at(i)->getType() == 'f' || transactions.at(i)->getType() == 'F'){
            if (balance >= transactions.at(i)->getAmount()){
                balance -= transactions.at(i)->getAmount();
            }
            //if withdrawal exceeds balance, print overdraft message and remove 25 from balance
            else{
                output << "Failed!\n" << transactions.at(i)->getDate();
                output << " Overdraft Fee, $25.00 to bank. ";
                balance -= 25;
            }
        }
        if (transactions.at(i)->getType() == 'c' || transactions.at(i)->getType() == 'C'){
            balance += transactions.at(i)->getAmount();
        }

        //print current balance
        output << "Balance: $" << balance << "\n";
    }
}