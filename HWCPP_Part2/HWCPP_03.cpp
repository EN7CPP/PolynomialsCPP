#include "iostream"
using namespace std;

struct Circle {
	const double PI = 3.14;
	double radius;
	void printCircumference() {
		cout << 2 * PI*radius<<endl;
	}
	void printArea() {
		cout << PI*radius*radius << endl;
	}
};

int main() {
	Circle one;
	cout << "Enter the radius:";
	cin >> one.radius;
	one.printCircumference();
	one.printArea();
	return 0;
}