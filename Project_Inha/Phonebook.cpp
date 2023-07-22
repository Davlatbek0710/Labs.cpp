#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Phonebook.h"
using namespace std;
string file_path = "Phonebook.bin";
void Menu() {
	/*cout << "\n          Menu         " << endl;
	cout << "-----------------------";
	cout << "\n1. Add some records.\n2. Search by name\n3. Search by number.\n4. Diplay all records\n5. Delete a record.\n6. Edit a record\n. Exit." << endl;*/
	cout << endl;
	cout << "|-------------------------------|\n";
	cout << "|----------My Phonebook---------|\n";
	cout << "|-------------------------------|\n";
	cout << "|     1. Add some records       |\n";
	cout << "|     2. Search by name         |\n";
	cout << "|     3. Search by nunber       |\n";
	cout << "|     4. Display all records    |\n";
	cout << "|     5. Delete a record        |\n";
	cout << "|     6. Edit a record          |\n";
	cout << "|     7. Delete all records     |\n";
	cout << "|     8. Exit                   |\n";
}

int main() {
	system("COLOR 0B");
	Phonebook d;
	int choice;
	do {
		Menu();
		cout << "\nEnter your choice : "; cin >> choice;
		switch (choice) {
		case 1: {
			ofstream fout;
			string name, number;
			fout.open("Phonebook.bin", ios::binary | ios::app);
			cout << "Enter a name: "; cin.ignore();  getline(cin, name);
			cout << "Enter a telephone number: "; cin >> number;
			d.Set_Name(name);
			d.Set_Number(number);
			fout.write((char*)&d, sizeof(d));
			fout.close();
			cout << "\nThe record has been saved." << endl;
			break;
		}
		case 2: {
			ifstream fin("Phonebook.bin", ios::in | ios::binary);
			string name;
			cout << "\nEnter name to search his / her number : "; cin >> name;
			bool t = false;
			while (fin.read((char*)&d, sizeof(d))) {
				if (d.Get_Name() == name) {
					cout << "\nName: " << d.Get_Name() << endl;
					cout << "Tel-number: " << d.Get_Number() << endl;
					t = true;
				}
			}
			if (!t) {
				cout << "No results found for " << name << endl;
			}
			break;
		}
		case 3: {
			ifstream fin("Phonebook.bin", ios::in | ios::binary);
			int number;// <- actual number
			string temp; // <- for validation check
			bool check = true;
			cout << "Enter a telephone number: "; cin.ignore(); getline(cin, temp);
			number = Validation_check_for_num(temp);
			//converting str number into int number;
			/*number = converting(temp);*/
			bool t = false;
			while (fin.read((char*)&d, sizeof(d))) {
				if (d.Get_Number() == number) {
					cout << "\nName: " << d.Get_Name() << endl;
					cout << "Tel-number: " << d.Get_Number() << endl;
					t = true;
				}
			}
			if (!t) {
				cout << "No results found for " << number << endl;
			}
			break;
		}
		case 4: {
			ifstream all("Phonebook.bin", ios::binary | ios::in);
			if (all.peek() != -1) {
				cout << "\n   All Records: " << endl;
				cout << left << setw(16) << "Name: " << setw(15) << "Tel-number:" << endl;
				cout << "---------------------------" << endl;
				while (all.read((char*)&d, sizeof(d))) {
					d.Display_all();
				}
				all.close();
			}
			else {
				cout << "\nThe file is empty" << endl;
			}
			break;
		}
		case 5: {
			string ism;
			cin.ignore();
			cout << "\nEnter the name of the contact that you want to delete: "; getline(cin, ism);
			ofstream temp("temp.bin", ios::binary | ios::out);
			ifstream obj1("Phonebook.bin", ios::binary | ios::in);
			bool check = false;
			while (obj1.read((char*)&d, sizeof(d))) {
				if (d.Get_Name() != ism) {
					temp.write(reinterpret_cast<char*>(&d), sizeof(d));
				}
				else {
					check = true;
				}
			}
			temp.close();
			obj1.close();
			remove("Phonebook.bin");
			rename("temp.bin", "Phonebook.bin");
			if (check) {
				cout << "\nThe record named " << ism << " has been successfully deleted.\n" << endl;
			}
			else {
				cout << "\nNo result found for " << ism << endl;
			}
			break;
		}
		case 6: {
			string n;
			bool check = false;
			cout << "\nEnter the name of the cotact that you want to edit. ";
			cin >> n;
			ifstream obj("Phonebook.bin", ios::binary | ios::in);
			ofstream obj1("temp.bin", ios::out | ios::binary);
			while (obj.read((char*)&d, sizeof(d))) {
				if (d.Get_Name() != n) {
					obj1.write((char*)&d, sizeof(d));
				}
				else if (d.Get_Name() == n) {
					check = true;
					string name, number;
					cin.ignore();
					cout << "\nOld name: " << d.Get_Name() << endl;
					cout << "Old number: " << d.Get_Number() << endl;
					cout << "\nEnter a new name: "; getline(cin, name);
					d.Set_Name(name);
					cout << "Enter a new number: "; cin >> number;
					d.Set_Number(number);
					obj1.write((char*)&d, sizeof(d));
				}
			}
			if (check) {
				cout << "Contact has beem updated. " << endl;
			}
			else {
				cout << "\nNo result found for " << n << endl;
			}
			obj.close();
			obj1.close();
			remove("Phonebook.bin");
			rename("temp.bin", "Phonebook.bin");
			break;
		}
		case 7: {
			remove("Phonebook.bin");
			fstream open("Phonebook.bin", ios::binary | ios::app);
			cout << "\nAll records deleted" << endl;
			break;
		}
		case 8: {
			cout << "Goodbye!" << endl;
			exit(1);
		}
		default: {
			cout << "\nInvalid choice. Please try again. " << endl;
		}
		}
	} while (choice != 8);
	

	
	return 0;

}
