/* 
   Name: Kobiljonov Davlatbek 
   Id: U2210118
   Assignment #7
*/

#include<iostream>
#include<string>
using namespace std;
#include<math.h>
//Program 1
class Publication {
protected:
	string title;
	float price;
public:
	void SetData() {
		cout << "Enter the name of the book. ";
		getline(cin, title);
		cout << "Enter the price of the book. ";
		cin >> price;
	}
	void GetData() {
		cout << "Title: " << title << endl;
		cout << "Price: " << price << endl;
	}
};

class Book : public Publication {
protected:
	int page_count;
public:
	void SetData() {
		Publication::SetData();
		cout << "Enter the number of pages. "; cin >> page_count;
	}
	void GetData() {
		Publication::GetData();
		cout << "Number of pages: " << page_count << endl;
	}
};

class Tape: public Publication {
protected:
	float playing_time;
public:
	void SetData() {
		cin.ignore();
		Publication::SetData();
		cout << "Enter the playing time of the book: "; cin >> playing_time;
	}
	void GetData() {
		Publication::GetData();
		cout << "Playing time: " << playing_time << endl;
	}
};

//Program 2
class Account {
protected:
	string customer_name;
	int accout_number;
	char type_of_accout;
public:
	void Set_Data() {
		cout << "Enter your name: "; cin>> customer_name;
		cout << "Enter your account number: "; cin >> accout_number;
		cout << "What is your account type?: write C for currrent acc and S for saving acc: "; cin >> type_of_accout;
	}
	
};

class Current_Account : public Account {
protected:
	int amount_of_money_for_deposit;
	int penalty = 2;
	int balance;
public:
	void Set_Data() {
		Account::Set_Data();
		cout << "Enter the starting amount of money in your balance.\nNote that you will be panalized by $2 if your balance is less than $100. "; cin >> balance;
		if (balance < 100) {
			Current_Account::Penalty();
		}
	}
	void Deposit() {
		cout << "\nEnter the amount of money to deposit." << endl;
		cin >> amount_of_money_for_deposit;
		balance += amount_of_money_for_deposit;
		cout << "Success!" << endl;
	}
	void Balance() {
		cout << "Your current balance:  $" << balance <<endl;
	}
	void Withdraw() {
		int withdraw_amount;
		
		cout << "Enter the withdraw amount. "; cin >> withdraw_amount;
		if (withdraw_amount <= balance && withdraw_amount > 0) {
			balance -= withdraw_amount;
			cout << "Whithdraw completed. " << endl;
		}
		else if (withdraw_amount > balance) {
			cout << "Impossible to withdraw due to lack of money in balance." << endl;
		}
	}
	void Penalty() {
		if (amount_of_money_for_deposit < 100 && amount_of_money_for_deposit >= 0) {
			amount_of_money_for_deposit -= penalty;
			cout << "You've been panalized by by $2 due to having balance less than $100";
		}
	}
	
};

class Saving_Account : public Account {
protected:
	int amount_of_money_for_deposit;
	int balance;
public:
	void Set_Data() {
		Account::Set_Data();
		cout << "Enter your starting balance."; cin >> balance;
	}
	void Deposit() {
		cout << "\nEnter the amount of money to deposit." << endl;
		cin >> amount_of_money_for_deposit;
		balance += amount_of_money_for_deposit;
		cout << "Success!" << endl;
	}
	void Balance() {
		cout << "Your current balance is $" << balance << endl;
	}
	void Withdraw() {
		int withdraw_amount;
		while (true) {
			cout << "\nEnter the withdraw amount. "; cin >> withdraw_amount;
			if (withdraw_amount <= balance && withdraw_amount > 0) {
				balance -= withdraw_amount;
				cout << "Whithdraw completed. " << endl;
				break;
			}
			else if (withdraw_amount <= 0) {
				cout << "Invalid input\nTry again! " << endl;
			}
		}
	}
	void Compute_Interest() {
		cout << "\nComputed Interest: based on rate 4% per annum. " << endl;
		int A;
		A = balance * pow((1 + 0.04 / 12), 12 * 1);
		cout << "\nYour final balance in a year will be $" << A << endl;
	}
	
};

int main() {
	system("COLOR 0B");
	Book O;
	O.SetData();
	O.GetData();
	Tape F;
	F.SetData();
	F.GetData();
	

	int choice;
	Current_Account* f;
	Saving_Account* d;
	
	do {
		cout << "Chose the type of your account.\n" << endl;
		cout << "1. Current account\n";
		cout << "2. Saving account.\n";
		cout << "3. Exit the program.\n";
		cin >> choice;
		if (choice == 1) {
			f = new Current_Account;
			f->Set_Data();
			do {
				cout << "\nChoose what operations would you like to perform.\n" << endl;
				cout << "1. Deposit money.\n";
				cout << "2. Withdraw money.\n";
				cout << "3. Display balance.\n";
				cout << "4. Exit from current acc.\n";
				cout << "Enter your choice: "; cin >> choice;
				switch (choice) {
				case 1: {
					f->Deposit();
					break;
				}
				case 2: {
					f->Withdraw();
					break;
				}
				case 3: {
					f->Balance();
					break;
				}
				}
			} while (choice != 4);
		}
		else if (choice == 2) {
			d = new Saving_Account;
			d->Set_Data();
			do {
				cout << "Choose what operations would you like to perform.\n" << endl;
				cout << "1. Deposit money.\n";
				cout << "2. Withdraw money.\n";
				cout << "3. Display balance.\n";
				cout << "4. Compute interest\n";
				cout << "5. Exit from current acc.\n";
				cout << "Enter your choice: "; cin >> choice;
				switch (choice) {
				case 1: {
					d->Deposit();
					break;
				}
				case 2: {
					d->Withdraw();
					break;
				}
				case 3: {
					d->Balance();
					break;
				}
				case 4: {
					d->Compute_Interest();
				}
				}
			} while (choice != 5);
		}
	} while (choice != 3);


	return 0;
}