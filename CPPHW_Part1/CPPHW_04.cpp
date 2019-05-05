#include "iostream"
#include "string"
using namespace std;

int tripleByValue(int n) {
	n *= 3;
	return n;
}
int tripleByReference(int &n) {
	n *= 3;
	return n;
}

int main() {
	int count = 3;
	tripleByValue(count);
	cout << count << endl;//Here the value of count is 3 i.e. not changed as it was passed by value and the operations in the function were done on the copy of it
	tripleByReference(count);
	cout << count << endl;// Here the value of count is 9 i.e. changed as it was passed by reference and the operations in the function were done on original variable as it was accessed by address

}