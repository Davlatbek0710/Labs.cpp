#include<iostream>
#include<string>
using namespace std;

class Your_Father {
	// secrets of your father:
private:
	int amout_of_money_he_has;
	string bissness;
protected:
	string family_name;
	int members_in_family;
public:
	string character = "Very friendly";
	int number_of_his_friends;
};

//You are protected memeber in is family;
class You : protected Your_Father
{

};



int main() {
	You h;
	

	return 0;
}