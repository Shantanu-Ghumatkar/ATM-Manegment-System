// C++ program to implement the ATM
// ATM Management System
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

bool check_number(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
class Bank
{

    // Private variables used inside class
private:
    string name;
    int accnumber;
    string cardnumber;
    int amount;
    int Balance = 0;
    int pin;
    // Public variables
public:
    Bank()
    {
        this->accnumber = 0;
        this->pin = 0;
        this->name = "na";
    }
    // parameterized constructor
    Bank(int accnumber, string cardnumber, int pin, string name)
    {
        this->accnumber = accnumber;
        setCardnumber(cardnumber);
        this->pin = pin;
        this->name = name;
    }
    // Function to set the person's data
    void setvalue()
    {
        cout << "Enter name\n";
        cin.ignore();

        // To use space in string
        getline(cin, name);
    }
    void setpin()
    {
        cout << "Enter New Pin\n";
        cin >> pin;
    }
    void setCardnumber(string cardnumber)
    {
        int i;
        if (cardnumber.length() == 16)
        {
            if (check_number(cardnumber))
            {
                this->cardnumber = cardnumber;
            }
            else
            {
                cout << "Invalid Card Number\n";
            }
        }
        else
        {
            cout << "Invalid Card Number\n";
        }
    }
    string getCardnumber()
    {
        return cardnumber;
    }
    int getPin()
    {
        return pin;
    }
    // Function to display the required data
    void showDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Account No:" << accnumber << endl;
        cout << "Balance:" << Balance << endl;
    }

    // Function to deposit the amount in ATM
    void deposit()
    {
        cout << "\nEnter amount to be Deposited\n";
        cin >> amount;
        Balance = amount + Balance;
        showBalance();
    }

    // Function to show the balance amount
    void showBalance()
    {
        cout << "\nBalanceal balance is: " << Balance;
    }

    // Function to withdraw the amount in ATM
    void withdrawl()
    {
        cout << "Enter amount to withdraw\n";
        cin >> amount;
        if (amount > Balance)
        {
            cout << "Account Balance is low\n";
        }
        else
        {
            Balance = Balance - amount;
        }
        cout << "Available Balance is " << Balance << endl;
    }
};

Bank atm(Bank b)
{

    int choice;
    while (1)
    {
        cout << "\n****************************"
             << "****************************"
             << "******WELCOME******************"
             << "****************************"
             << "***************\n\n";
        cout << "Enter Your Choice\n";
        cout << "\t1. Change Details\n";
        cout << "\t2. Details\n";
        cout << "\t3. Deposit Money\n";
        cout << "\t4. Show Balanceal balance\n";
        cout << "\t5. Withdraw Money\n";
        cout << "\t6. Change Pin\n";
        cout << "\t7. Cancel\n";

        cin >> choice;

        // Choices to select from
        switch (choice)
        {
        case 1:
            b.setvalue();
            break;
        case 2:
            b.showDetails();
            break;
        case 3:
            b.deposit();
            break;
        case 4:
            b.showBalance();
            break;
        case 5:
            b.withdrawl();
            break;
        case 6:
            b.setpin();
            break;

        case 7:
            exit(0);
            break;
        default:
            cout << "\nInvalid choice\n";
        }
    }
    return b;
}
Bank createAcc()
{

    int accnumber;
    string cardnumber;
    int pin;
    string name;
    cout << "Enter name\n";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Account Number\n";
    cin >> accnumber;
    cout << "Enter card Number\n";
    getline(cin, cardnumber);
    cout << "Enter Pin\n";
    cin >> pin;
    // Object of class
    Bank b(accnumber, cardnumber, pin, name);
    return b;
}
// Driver Code
int main()
{
    Bank b(1, "1234567890123456", 1234, "Shantanu");
    // b = createAcc(); // here we are creating single account
    string cardnumber;
    int pin;
    int count = 0;
    while (count != 3)
    {
        cout << "\n************Enter card Number**************\n";
        getline(cin, cardnumber);
        if (cardnumber != b.getCardnumber())
        {
            cout << "Wrong Card Number";
            count++;
            continue;
        }

        else
        {
            //        	if user enter wrong password more than  3 we will send messege to user and block card for 24 hour but here we will exit code
            count = 0;
            while (count != 3)
            {
                cout << "\n*********Enter Pin*************\n";
                cin >> pin;
                if (pin != b.getPin())
                {
                    cout << " Wrong Pin";
                    count++;
                    continue;
                }
                else
                {
                    b = atm(b);
                }
            }
        }
    }
}
