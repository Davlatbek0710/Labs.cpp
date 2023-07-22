#include<iostream>
#include<fstream>
using namespace std;

// The calendar of 2025
int main() {
	system("COLOR 0B");
	int c = 0;
	string month[12] = { "January", "February", "March", "April", "May", "Jun", "July", "August", "September", "October", "November", "December" };
	int number_of_days_in_a_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string weeks[8] = { "  ", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
	int first_day;
	for (int d = 0; d <= 11; d++) {
		cout << "\n           " + month[d] + "          " << endl;
		first_day = c + 1;
		if (first_day == 1) {
			cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;
			cout << "---------------------------------" << endl;
			cout << " ";
			for (int j = 1; j <= number_of_days_in_a_month[d]; j++) {
				c += 1;
				if (j >= 1 && j < 10) {
					cout << j << "    ";
					if (j % 7 == 0) {
						cout << endl;
						cout << " ";
					}
				}
				if (j >= 10) {
					cout << j << "   ";
					if (j % 7 == 0) {
						cout << endl;
						cout << " ";
					}
				}
				if (c == 7) {
					c = 0;
				}
			}
		}
		else if (first_day >= 2 && first_day <= 7) {
			cout << "Mon  Tue  Wed  Thu  Fri  Sat  Sun" << endl;
			cout << "---------------------------------" << endl;
			for (int i = 1; i < first_day; i++) {
				cout << "     ";
			}
			cout << " ";
			for (int j = 1; j <= number_of_days_in_a_month[d]; j++) {
				c += 1;
				if (j >= 1 && j < 10) {
					cout << j << "    ";
					if (j % 7 == 8 - first_day) {
						cout << endl;
						cout << " ";
					}
				}
				if (j >= 10) {
					cout << j << "   ";
					if (j % 7 == 8 - first_day) {
						cout << endl;
						cout << " ";
					}
				}
				if (c == 7) {
					c = 0;
				}
			}
		}
		cout << endl;
	}
	

	

	


	return 0;
}