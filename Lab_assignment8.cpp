/*/
\*\ Student Name: Kobiljonov Davlatbek
/*/ 
/*/ and id: u2210118
\*\ Assignment # 8
/*/

#include<iostream>
#include<string>
using namespace std;

//Program 1
class Staff {
protected:
	int code ;
	string name;
public:
	Staff() { name = "Not Specified"; code = 0; }
	Staff(string name, int code) {
		this->name = name;
		this->code = code;
	}
	void Set() {
		cout << "Enter the name of a teacher: "; getline(cin, name);
		cout << "Enter the id code of the teacher: "; cin >> code;
	}
	void Get() {
		cout << "Name: " << name << endl;
		cout << "Id Code: " << code << endl;
	}
};
class Teacher : public Staff {
protected:
	string subject;
	int Publication;
public:
	Teacher() { subject = "Not Specified"; Publication = 0; }
	Teacher(string s, int p, string name, int code) :subject(s), Publication(p), Staff(name, code) {}
	void Set() {
		this->Staff::Set();
		cin.ignore();
		cout << "Enter the teaching subject: "; getline(cin, subject);
		cout << "Enter the publication month: "; cin >> Publication;
	}
	void Get_All() {
		this->Staff::Get();
		cout << "TEACHING SUBJECT: " << subject << endl;
		cout << "Announced month: " << Publication << endl;
	}
};

class Officer : public Staff{
protected:
	string grade;
public:
	Officer() { grade = "Not Specified"; }
	Officer(string name, int code, string g) :Staff(name, code), grade(g){}
	void Set() {
		this->Staff::Set();
		cout << "Enter the rank of the officer: "; cin.ignore(); getline(cin, grade);
	}
	void Get(){
		this->Staff::Get();
		cout << "Degree: " << grade << endl;
	}
};

class Typist : public Staff {
protected:
	int speed;
public:
	Typist(string name, int code, int s) : Staff(name, code), speed(s) {}
	void Set() {
		this->Staff::Set();
		cout << "Enter the speed of typing in w/min: "; cin >> speed;
	}
	void Get() {
		this->Staff::Get();
		cout << "Speed of typing is " << speed << " w/min" << endl;
	}
};

class Regular : public Typist{
protected:
	int Monthly_salary;
public:
	Regular(string name, int code, int speed, int salary) : Monthly_salary(salary), Typist(name, code, speed) {}
	void Set() {
		this->Typist::Set();
		cout << "Enter the monthly salary of the typist in $: "; cin >> Monthly_salary;
	}
	void Get() {
		this->Typist::Get();
		cout << "Monthly Salary of " << Staff::name << " is $" << Monthly_salary << endl;
	}
};

class Casual:public Typist {
protected:
	int Daily_wages;
public:
	Casual(string name, int code, int speed, int wage) :Daily_wages(wage), Typist(name, code, speed) {}
	void Set() {
		this->Typist::Set();
		cout << "Enter the daily wages of the typist in $: "; cin >> Daily_wages;
	}
	void Get() {
		this->Typist::Get();
		cout << "Daily wages of " << Typist::name << " is $" << Daily_wages << endl;
	}
};

class Education: public virtual Teacher,  virtual public Officer {
protected:
	string Highest_professional_qualification;
public:
	Education() { Highest_professional_qualification = "Not Specified"; };
	//One Parametrized constructor is for declaring the data of a teacher 
	Education(string subject, int publication, string name, int code, string degree):Teacher(subject, publication, name, code), Highest_professional_qualification(degree){}

	//Other is for officer's one.
	Education(string name, int code, string grade, string degree):Officer(name, code, grade), Highest_professional_qualification(degree){}

	//Function for set and get also been created respectively for teacher and officer.
	void Set_Ditails_of_teacher() {
		this->Teacher::Set();
		//Here you have to specify the actual degree of the professor or teacher.
		cout << "Enter the highest proffecional qualification: "; cin.ignore(); getline(cin, Highest_professional_qualification);
	}
	void Set_Ditails_of_an_officer() {
		this->Officer::Set();
		//Here you have to specify the degree of the officer sergeant or mageor or whatever.
		cout << "Enter the highest proffecional qualification: "; cin.ignore(); getline(cin, Highest_professional_qualification);
	}
	void Get_Ditails_of_teacher() {
		Teacher::Get_All();
		cout << "Education\n|" << Highest_professional_qualification << endl;
	}
	void Get_Ditails_of_officer() {
		Officer::Get();
		cout << "Education\n| " << Highest_professional_qualification << endl;
	}
};

//Program 2
class Person {
protected: 
	string name;
	int code;
public:
	Person() { name = "Not specified"; code = 0; }
	Person(string n, int c) :name(n), code(c){}
	void Set() {
		cout << "\nEnter master's name: "; getline(cin, name);
		cout << "Enter the id code: "; cin >> code;
	}
	void Get() {
		cout << "\nName: " << name << endl;
		cout << "Id Code: " << code << endl;
	}
};
class Account : public Person{
protected:
	int pay;
public:
	Account() { pay = 0; }
	Account(string name, int code, int pay) : pay(pay), Person(name, code){}
	void Set() {
		cout << "Enter a pay for the master: "; cin >> pay;
	}
	void Get() {
		cout << "Pay for the master: $" << pay <<"\n"<<endl;
	}
};
class Admin : public Person{
protected:
	string experiaence;
public:
	Admin() { experiaence = "Not Specified"; }
	Admin(string name, int code, string ex) : Person(name, code), experiaence(ex){}
	void Set() {
		Person::Set();
		cout << "Write about master's experience: "; cin.ignore(), getline(cin, experiaence);
	}
	void Get() {
		Person::Get();
		cout << "Experience: " << experiaence << endl;
	}
};

class Master:virtual public Admin, public virtual Account {
public:
	Master(){}
	Master(string name, int code, string exp, int p) :Admin(name, code, exp), Account(name, code, pay){}
	void Set() {
		Admin::Set();
		Account::Set();
	}
	void Display() {
		Admin::Get();
		Account::Get();
	}
};


int main() {
	system("COLOR 0B");

	//Program 1
	Education d;
	d.Set_Ditails_of_teacher();
	d.Get_Ditails_of_teacher();
	d.Set_Ditails_of_an_officer();
	d.Get_Ditails_of_officer();
	Regular z("Name ", 33, 332, 423);
	z.Set();
	z.Get();


	//Program 2
	Master r;
	int choice;
	do {
		cout << "1. Create an Update\n2. Display everything.\n3. Exit the program";
		cout << "enter tour choice: "; cin >> choice;
		switch (choice) {
			case 1: {
				cin.ignore();
				r.Set();
				cout << "\nThe update created successfully!" << endl;
				break;
			}
			case 2: {
				r.Display();
				break;
			}
			case 3:
				cout << "\nGoodbye! " << endl; exit(1);
			default: {
				cout << "\nWrong choice!\nTry again.\n" << endl;
			}
		}
	}while (choice != 3);

	
	return 0;
}

