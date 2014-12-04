#include "Certificate_of_Deposit.h"

using namespace std;

istream& operator>>(istream& input, Certificate_of_Deposit& cod){
    input >> cod.accountID >> cod.dateOpened >> cod.balance >> cod.interestRate >> cod.maturityDate;
    return input;
}

//creates a number of Monthly Compounding transactions and adds them to transactions vector
void Certificate_of_Deposit::monthlyChores(int numMonths){
    int theMonth = dateOpened.getMonth() + 1;
    int theYear = dateOpened.getYear();
    int theDay = dateOpened.getDay();
    //Loop from 0 to numMonths. Creates new transactions for each monthly compound and pushes them back
    for (int i = 0; i < numMonths; i++){
        Transaction* action = new Transaction();
        action->setAccountID(accountID);
        action->setAmount(balance * interestRate);
        action->setLocation("bank");
        action->setType('c');
        if (theMonth == 13){
            theMonth = 1;
            theYear++;
        }
        Date date;
        date.setDate(theMonth, theDay, theYear);
        action->setDate(date);
        transactions.push_back(action);
    }
}

void Certificate_of_Deposit::save(ostream& output){
    output << type << " " << accountID << " " << dateOpened <<  " " << balance << " " << interestRate << " " << maturityDate;
}