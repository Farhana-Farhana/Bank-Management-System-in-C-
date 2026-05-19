#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    float balance;

public:

    // Create Account
    void createAccount() {

        cout << "\nEnter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Save Account to File
    void saveAccount() {

        ofstream file("bank.txt", ios::app);

        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;

        file.close();

        cout << "\nAccount Created Successfully!\n";
    }

    // Display All Accounts
    void displayAccounts() {

        ifstream file("bank.txt");

        int acc;
        string n;
        float bal;

        cout << "\n===== CUSTOMER RECORDS =====\n";

        while (file >> acc) {

            file.ignore();

            getline(file, n);

            file >> bal;

            file.ignore();

            cout << "\nAccount Number : " << acc;
            cout << "\nCustomer Name  : " << n;
            cout << "\nBalance        : " << bal << endl;
        }

        file.close();
    }

    // Deposit Money
    void depositMoney() {

        ifstream file("bank.txt");
        ofstream temp("temp.txt");

        int searchAcc;
        float amount;
        bool found = false;

        cout << "\nEnter Account Number: ";
        cin >> searchAcc;

        cout << "Enter Deposit Amount: ";
        cin >> amount;

        int acc;
        string n;
        float bal;

        while (file >> acc) {

            file.ignore();

            getline(file, n);

            file >> bal;

            file.ignore();

            if (acc == searchAcc) {

                bal += amount;

                found = true;

                cout << "\nAmount Deposited Successfully!\n";
            }

            temp << acc << endl;
            temp << n << endl;
            temp << bal << endl;
        }

        file.close();
        temp.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (!found)
            cout << "\nAccount Not Found!\n";
    }

    // Withdraw Money
    void withdrawMoney() {

        ifstream file("bank.txt");
        ofstream temp("temp.txt");

        int searchAcc;
        float amount;
        bool found = false;

        cout << "\nEnter Account Number: ";
        cin >> searchAcc;

        cout << "Enter Withdrawal Amount: ";
        cin >> amount;

        int acc;
        string n;
        float bal;

        while (file >> acc) {

            file.ignore();

            getline(file, n);

            file >> bal;

            file.ignore();

            if (acc == searchAcc) {

                found = true;

                if (amount <= bal) {

                    bal -= amount;

                    cout << "\nWithdrawal Successful!\n";
                }
                else {

                    cout << "\nInsufficient Balance!\n";
                }
            }

            temp << acc << endl;
            temp << n << endl;
            temp << bal << endl;
        }

        file.close();
        temp.close();

        remove("bank.txt");
        rename("temp.txt", "bank.txt");

        if (!found)
            cout << "\nAccount Not Found!\n";
    }

    // Balance Inquiry
    void checkBalance() {

        ifstream file("bank.txt");

        int searchAcc;
        bool found = false;

        cout << "\nEnter Account Number: ";
        cin >> searchAcc;

        int acc;
        string n;
        float bal;

        while (file >> acc) {

            file.ignore();

            getline(file, n);

            file >> bal;

            file.ignore();

            if (acc == searchAcc) {

                found = true;

                cout << "\n===== ACCOUNT DETAILS =====";
                cout << "\nAccount Number : " << acc;
                cout << "\nCustomer Name  : " << n;
                cout << "\nBalance        : " << bal << endl;
            }
        }

        file.close();

        if (!found)
            cout << "\nAccount Not Found!\n";
    }
};

int main() {

    BankAccount b;

    int choice;

    do {

        cout << "\n\n===== BANK MANAGEMENT SYSTEM =====";
        cout << "\n1. Create Account";
        cout << "\n2. Display All Accounts";
        cout << "\n3. Deposit Money";
        cout << "\n4. Withdraw Money";
        cout << "\n5. Check Balance";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                b.createAccount();
                b.saveAccount();
                break;

            case 2:
                b.displayAccounts();
                break;

            case 3:
                b.depositMoney();
                break;

            case 4:
                b.withdrawMoney();
                break;

            case 5:
                b.checkBalance();
                break;

            case 6:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
