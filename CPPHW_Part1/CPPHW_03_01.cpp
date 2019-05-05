#include "iostream"
#include "string"
using namespace std;

string printAsterisk(int n) {
	string toBeReturned = "";
	for (int i = 0; i<n; i++) {
		toBeReturned += "*";
	}
	return toBeReturned;
}
string printSpace(int n) {
	string toBeReturned = "";
	for (int i = 0; i<n; i++) {
		toBeReturned += " ";
	}
	return toBeReturned;
}

int main()
{
	int n = -2;
	while (n % 2 != 1) {
		cout << "Please enter an odd number : ";
		cin >> n;
	}
	int l = n / 2;
	for (int i = 1; i <= n; i += 2) {
		cout << printSpace(l);
		cout << printAsterisk(i) << endl;
		l--;
	}
	l = 1;
	for (int i = n - 2; i >= 1; i -= 2) {
		cout << printSpace(l);
		cout << printAsterisk(i) << endl;
		l++;

	}

	return 0;
}