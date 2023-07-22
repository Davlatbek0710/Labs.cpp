/*
   Name: Kobiljonov Davlatbek
   Id: U2210118
   Spring semester
   Assignment № 1
*/
#include<iostream>
#include<string>
using namespace std;
using std::cout;
using std::cin;
using std::endl;


// Global scope for object choice of int class we will need this while some askings whether user wants to exit program
int choice;


class Student {
private:
	// Data about student - data members
	string student_id, name;
	// Subjects - data members
	double oop2_score = 0, math_score = 0, english_score = 0;
public:
	// following below is all are the data member functions
	void set_name() {
		cout << "Please enter your name: ";
		getline(cin, name);
		cout << "Your name was successfully registered!\n" << endl;
	}
	void get_name() {
		cout << "Student name: " + name << endl;
	}
	void set_id() {
		cout << "Please enter your student id: ";
		getline(cin, student_id);
		cout << "Your student ID was successfully registered!\n" << endl;
	}
	void get_id() {
		cout << "Your student ID: " + student_id << endl;;
	}
	void set_oop2_score() {
		cout << "Please enter your OOP2 grade:\nRanage of points from 1 up to 30: ";
		cin >> oop2_score;
		while (true) {
			if (oop2_score >= 1 and oop2_score <= 30) {
				cout << "Your OOP2 grade was successfully registered!\n" << endl;
				break;
			}
			else {
				cout << "Invalid points.\nRanage of points from 1 up to 30\nTry Again! ";
				cin >> oop2_score;
				cout << endl;
			}
		}
	}
	void get_oop2_score() {
		cout << "Your OOP2 score: ";
		cout<< oop2_score <<endl;
	}
	void set_math_score() {
		cout << "Please enter your MATH grade:\nRanage of points from 1 up to 100: ";
		cin >> math_score;
		while (true) {
			if (math_score >= 1 and math_score <= 100) {
				cout << "Your MATH grade was successfully registered!\n" << endl;
				break;
			}
			else {
				cout << "Invalid points.\nRanage of points from 1 up to 100\nTry Again! ";
				cin >> math_score;
				cout << endl;
			}
		}
	}
	void get_math_score() {
		cout << "Your MATH score: ";
		cout << math_score << endl;
	}
	void set_english_score() {
		cout << "Please enter your Academic English 1 grade:\nRanage of points from 1 up to 75:  ";
		cin >> english_score;
		while (true) {
			if (english_score >= 1 and english_score <= 100) {
				cout << "   =-=-=-=-=-= ALL DONE =-=-=-=-=-= \n" << endl;
				break;
			}
			else {
				cout << "Invalid points.\nRanage of points from 1 up to 75\nTry Again! ";
				cin >> english_score;
				cout << endl;
			}
		}
	}
	void get_english_score() {
		cout << "Your AE1 score: ";
		cout << english_score << endl;
	}
	double get_avarage_score() {
		double avg = 0;
		avg = (oop2_score + math_score + english_score) / 3;
		cout << "Your avarage score: ";
		return avg;
	}
	double get_total_score() {
		double tot = 0;
		tot = (oop2_score + math_score + english_score);
		cout << "Your total score: ";
		return tot;
	}
};


int main() {
	double avg = 0, tot = 0;
	// Creating the object of Class Student.
	Student data;
	cout << "=-=-=-=-=-= FIRST OF ALL =-=-=-=-=-=" << endl;
	cout << "STORE ALL OF YOUR STUDENT INFORMATION!"<<endl;
	data.set_name();
	data.set_id();
	data.set_oop2_score();
	data.set_math_score();
	data.set_english_score();
	cout << "NOW CHOOSE ONE NUMBER TO GET YOUR INFO:\n " << endl;
	cout << "THE LIST OF YOUR STUDENT DATA:\n" << endl;
	//Let's maka the initial value of opt N not to repeat the process infinitely
	string opt = "N";
	do {
		cout << "1. GET STUDENT NAME.\n2. GET STUDENT ID.\n3. GET OOP2 score.\n4. GET MATH score.\n5. GET AE1 score.\n6. GET Overall avarage score.\n7. GET TOTAL SCORE.\n0. EXIT.\n"<<endl;
		cout << "COME ON: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
			case 1: {
				data.get_name();
				cout << endl;
				break;
			}
			case 2: {
				data.get_id();
				cout << endl;
				break;
			}
			case 3: {
				data.get_oop2_score();
				cout << endl;
				break;
			}
			case 4: {
				data.get_math_score();
				cout << endl;
				break;
			}
			case 5: {
				data.get_english_score();
				cout << endl;
				break;
			}
			case 6: {
				avg = data.get_avarage_score();
				cout << avg << endl;
				cout << endl;
				break;
			}
			case 7: {
				tot = data.get_total_score();
				cout << tot << endl;
				cout << endl;
				break;
			}
			case 0: {
				cout << "You exited the program." << endl;
				cout << endl;
				break;
			}
		}
		if (choice <= 7 and choice >= 1) {
			cout << "Do you want to know anything else from what you stored just know? 😂\n";
			cout << "Enter Y or N to continue:\nY - Yes, N - No: ";
			std::cin >> opt;
			cout << endl;
		}
		else if (choice == 0) {
			opt = "No";
		}
		/*else {
			cout << "Invalid Input!\n*. Back" << endl;
			cin>>something that returns the menus....
				I could not find a way to solve this condition could you please help to deal with or explain me on Q&A on e class?.
				I mean I did the recursion but that was not so accurate code, it excounters some errors, when I code it.
				EXAMPLE:
				When you want to check your tariff having the BEELINE SIM, Inputting *111# there will be options, and if you press the button which is out of the list of options, it shows you Invalid Input, 
				*. Back, and when you send * , it backs to menu again, This is what I mean.
				* whould be glad and grateful for your help on e-class.
		}*/
	} while (opt == "Y" or opt == "y" or opt == "Yes" or opt == "YES" or opt == "yes");
	if (choice != 0) {
		cout << "You exited the program." << endl;
	}
		
	system("pause");
	return 0;
}