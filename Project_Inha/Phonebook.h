#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int Validation_check_for_num(string n);
//int converting(string n);


class Person {
protected:
	string name;
	int number;
};
class Phonebook : public Person {
public:
	void Set_Name(string name) {
		this->name = name;
	}
	void Set_Number(string num) {
		number = Validation_check_for_num(num);
	}
	string Get_Name() {
		return name;
	}
	int Get_Number() {
		return number;
	}
	void Display_all() {
		cout << left << setw(16) << name << setw(12) << number << endl;
	}
};

int Validation_check_for_num(string num) {
	// 1St Step is to get the valid set of integers only, i.e for tel-number in a string form for validation, just in case.
	bool check = true;
	while (true) {
		for (int i = 0; i < num.length(); i++) {
			if (!(num[i] >= 48 && num[i] <= 57)) {
				cout << "Invalid input, try again, input only with integers! "; cin.ignore(); cin >> num;
				check = false;
				break;
			}
			if (num.length() >= 10) {
				cout << "You exceeded the range! enter a number consisting of 9 digits: "; cin.ignore(); cin >> num;
				break;
			}
		}

		if (check) {
			break;
		}
		else {
			check = true;
			continue;
		}
	}
	int res;
	stringstream t;
	t << num;
	t >> res;
	return res;
	// 2nd step. converting the string type into integer
	//return converting(num);
}

//int converting(string n) {
//	int result = 0;
//	for (int i = 0; i < n.length(); i++) {
//		// for example: str x = "67" -> to integer. 
//		// first x[0] -> '6', in Ascii: '6' == 54. and '0' == 48. 
//		// and then, 54 - 48 = 6. 
//		// and store 6 using the simple formula given below.
//		result = 10 * result + (n[i] - '0');
//	}
//	// Now we store actual number; 
//	return result;
//}