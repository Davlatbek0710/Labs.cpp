/*/
\*\ Student Name: Kobiljonov Davlatbek
/*/
/*/ id: u2210118
\*\ Assignment # 9
/*/

#include<iostream>
using namespace std;

class shape {
protected:
	double x, y;
public:
	void get_data(double x, double y){
		this->x = x;
		this->y = y;
	}
	void get_data(double radius) {
		x = radius;
	}
	virtual void display_area() = 0;
};

class Triangle : public shape {
public:
	void display_area() {
		cout << "\nThe area of the trianlge: " << (x * y) / 2 << endl;
	}
};

class Rectangle : public shape {
public:
	void display_area() {
		cout << "\nThe area of the rectangle: " << x * y << endl;
	}
};

class Circle :public shape {
public:
	void display_area() {
		cout << "\nThe area of a circle: " << 3.14 * x * x << endl;;
	}
};
int main() {
	system("color 0B");
	int choice;
	double x, y;
	cout << "\nIn this program you are able to compute the area of :\n" << endl;
	do {
		cout << "1. a triangle " << endl;
		cout << "2. a rectangle " << endl;
		cout << "3. a circle " << endl;
		cout << "4. Exit." << endl;
		cout << "\nEnter your choice: "; cin >> choice;
		switch (choice) {
		case 1: {
			shape *t = new Triangle;
			cout << "\nEnter the height of the trianlge: "; cin >> x;
			cout << "Enter the base of the triangle: "; cin >> y;
			t->get_data(x, y);
			t->display_area();
			cout << endl;
			break;
		}
		case 2:
		{
			shape *r = new Rectangle;
			cout << "\nEnter one side of the rectangle: "; cin >> x;
			cout << "Enter another side: "; cin >> y;
			r->get_data(x, y);
			r->display_area();
			cout << endl;
			break;
		}
		case 3: {
			double radius;
			cout << "\nEnter the radius of a circle: "; cin >> radius;
			Circle circle;
			circle.get_data(radius);
			shape* ptr;
			ptr = &circle;
			ptr->display_area();	
			cout << endl;
			break;
		}
		case 4:{
			cout << "\nGoodbye!" << endl;
			break;
		}
		default: cout << "\nInvalid choice!\nTry again! " << endl;
		}
	} while (choice != 4);

	return 0;
}