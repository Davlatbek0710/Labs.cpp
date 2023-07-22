#include<iostream>
#include<string>
using namespace std;


class FullName {
private:
	string f_name, m_name, l_name;
public:
	FullName(){
		f_name = "Not Specified";
		m_name = "Not Specified";
        l_name = "Not Specified";
	}
	void Setf_name(string f_name) {
		this->f_name = f_name;
	}
	void Setm_name(string m_name) {
		this->m_name = m_name;}
	void Setl_name(string l_name) {
		this->l_name = l_name;}
	string getf_name() { return f_name; }
	string getm_name() { return m_name; }
	string getl_name() { return l_name; }
};


class Player {
private:
	FullName full_name;
	string id;
	int played_matches, goals_scored;
public:
	//Default constructor
	Player() {
		full_name.Setf_name("Not Specified");
		full_name.Setm_name("Not Specified");
		full_name.Setl_name("Not Specified");
		id = "Not specified";
		played_matches = 0;
		goals_scored = 0;
	}
	void set_player_name(FullName n) {
		full_name = n;
	}
	void set_id(string id) {
		this->id = id;
	}
	void set_matches(int p) {
		played_matches = p;
	}
	void set_goals_scored(int s) {
		goals_scored = s;
	}
	void get_id() {
		cout << "Player Id: " + id << endl;
	}
	void get_matches() {
		cout << "Matches Played: " << played_matches << endl;
	}
	void get_goals_scores() {
		cout << "Goals scored: " << goals_scored << endl;
	}
	void get_player_name() {
		string f_name, m_name, l_name;
		f_name = full_name.getf_name();
		cout << "First name: " << f_name << endl;
		m_name = full_name.getm_name();
		cout << "Middle name: " << m_name << endl;
		l_name = full_name.getl_name();
		cout << "Last name: " << l_name << endl;
	}
	friend int Increase_Goals_scored(Player &p,  int c);
};


int Increase_Goals_scored(Player &s, int x) {
	s.goals_scored += x;
	cout << endl;
	cout << "The score increased by " << x << "."<<endl;
}


int main() {
	FullName* n = new FullName;
	Player* p = new Player;
	string f_name, m_name, l_name, id;
	int matches, goals_scored;
	int x, choice;
	
	do {
		cout << endl;
		cout << "-------------Menu------------\n" << endl;
		cout << "1. Add player ditails. " << endl;
		cout << "2. Display player ditails. " << endl;
		cout << "3. Increase player goal scored. " << endl;
		cout << "4. delete player from memory." << endl;
		cout << "0. Exit the program.\n" << endl;
		cout << "Enter your choice: ";
		cin >> choice; cout << endl << endl;;
		switch (choice) {
			case 1: {
				cout << "Enter first name: "; cin >> f_name;
				cout << "Enter middle name: "; cin >> m_name; 
				cout << "Enter last name: "; cin >> l_name;
				n->Setf_name(f_name);
				n->Setm_name(m_name);
				n->Setl_name(l_name);
				p->set_player_name(*n);
				cout << "Enter player ID: "; cin >> id; 
				p->set_id(id);
				cout << "Enter the number of matches played: "; cin >> matches;
				p->set_matches(matches);
				cout << "Enter the number of goals scored: "; cin >> goals_scored;
				p->set_goals_scored(goals_scored);
				break;
			}
			case 2:{
				p->get_player_name();
				p->get_id();
				p->get_matches();
	      		p->get_goals_scores();
				cout << endl;
				break;
			}
			case 3: {
				cout << "Enter the number of goals to increase: "; cin >> x;
				Increase_Goals_scored(*p, x);
				break;
			}
			case 4: {
				cout << "Player ditails have been successfully deleted. " << endl;
				delete p, n;
				break;
			}
			case 0: {
				cout << "\nYou exited the program." << endl;
			}
		}
	}while (choice != 0);
	
	

	return 0;
}

