/*
  Full Name: Kobiljonov Davlatbek 
  Id: u2210118
  Assignment # 4
 */
#include<iostream>
using namespace std;


//Program 1
class DayTime {
private:
	int hour, minute, second;
public:
	DayTime(int hour, int minute, int second) {
		//Logic for seconds
		while (true) {
			if (second < 0) {
				cout << "Invalid input!\nTry Again! " << endl;
				cin >> second;
				continue;
			}
			else if (second >= 60) {
				minute += (second - second % 60) / 60;
				second %= 60;
			}
			else {
				break;
			}
		}
		this->second = second;
		// Logic for minutes
		while (true) {
			if (minute < 0) {
				cout << "Invalid input!\nTry Again! " << endl;
				cin >> minute;
				continue;
			}
			//turning the minutes to hours and addind to the absolute value of hour.
			else if (minute >= 60) {
				hour += (minute - minute % 60) / 60;
				minute %= 60;
			}
			else {
				break;
			}
		}
		this->minute = minute;
		// Logic for Hours
		while (true) {
			if (hour < 0) {
				cout << "Invalid input!\nHour range -> (0,24)\nTry Again! " << endl;
				cin >> hour;
				continue;
			}
			else if (hour > 24) {
				hour = 0;
			}
			else {
				break;
			}
		}
		this->hour = hour;
		//DayTime only in seoncds
	}
	int getHour() const { return hour; }
	int getMinute() const { return minute; }
	int getSecond() const { return second; }
	int asSeconds() const { return second + minute * 60 + hour * 3600; }
	
	//increment operator overloading to increase the value of seconds
	void operator++() {
		//here we should only increment seconds
		second = second + 1;
		while (true) {
			if (second >= 60) {
				minute += (second - second % 60) / 60;
				second %= 60;
			}
			else {
				break;
			}
		}
		this->second = second;
		cout << "\nSeconds have been incremented! " << endl;
	}
	//decrement operator overloading to reduce the value of minutes
	void operator--() {
		minute = minute - 1;
		cout << "\nMinutes have been decremented! " << endl;
	}
};
//Program 2
class Dollar {
private:
	float currency, mktrate, offrate;
public:
	float getDollar() {
		return currency;
	}
	float getMarketSoums() {
		return currency * mktrate;
	}
	float getOfficialSoums() {
		return currency * offrate;
	}
	void SetRates() {
		cout << "Input the currency of USD: ";
		cin >> currency;
		cout << "Input current date market and official rates.\n";
		cout << "Input market rate: ";
		cin >> mktrate;
		cout << "Input official rate: ";
		cin >> offrate;
	}
	friend void operator<<(ostream&, Dollar&);
};


void operator<<(ostream & c, Dollar & d) {
	c << "Currency of USD: " << d.getDollar() << endl;
	c << "Official rate in Uzbekistan soums: ";
	c << d.getDollar() << " USD$ -> " << d.getOfficialSoums() <<" soums" << endl;
	c << "Market rate in Uzbekistan soums: ";
	c << d.getDollar() << " USD$ -> " << d.getMarketSoums() << " soums"<<endl;
}


int main() {


	//Program 1
	int h, m, s;
	int choice;

	cout << "Enter the daytime in this form 00:00:00" << endl;
	cout << "hours: "; cin >> h;
	cout << "minutes: "; cin >> m;
	cout << "seconds: "; cin >> s;
	DayTime  d(h, m, s);

	do {
		cout << "\n--------------Menu---------------\n";
		cout << "1. Display Time.\n2. Display Time in seconds.\n3. Increment seconds\n4. Decrement minutes\n0. Exit." << endl;
		cout << "Enter your option: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "\nCurrent daytime: ";
			cout << d.getHour() << ":" << d.getMinute() << ":" << d.getSecond() << endl;
			break;
		case 2:
			cout << "\nAll number of seconds Time: " << d.asSeconds() << endl;
			break;
		case 3:
			++d;
			cout << "Current daytime: ";
			cout << d.getHour() << ":" << d.getMinute() << ":" << d.getSecond() << endl;
			break;
		case 4:
			--d;
			cout << d.getMinute();
			break;
		case 0:
			cout << "\nYou exited program!" << endl;
		default: 
			break;
		}
	} while (choice != 0);


	//Program 2
	Dollar cur;
	cur.SetRates();
	cout << cur;
	
	
	


	
	
	return 0;
}