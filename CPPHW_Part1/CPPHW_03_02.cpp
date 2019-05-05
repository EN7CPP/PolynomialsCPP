#include "iostream"
#include "string"
using namespace std;

string printAsterisk(string s, int n) {
	if (n <= 0) {
		return s;
	}
	return printAsterisk(s, n - 1) + "*";
}

string printSpace(string s, int n) {
	if (n <= 0) {
		return s;
	}
	return printSpace(s, n - 1) + " ";
}
void combineFirstHalf(int n1, int n2) {
	if (n1 <= 0) {
		return;
	}
	cout << printSpace("", n1 - 1) + printAsterisk("", n2) << endl;
	return combineFirstHalf(n1 - 1, n2 + 2);
}
void combineSecondHalf(int n1, int n2) {
	if (n2 <= 0) {
		return;
	}
	cout << printSpace("", n1 - 1) + printAsterisk("", n2) << endl;
	return combineSecondHalf(n1 + 1, n2 - 2);
}
int main()
{
	int n = 0;
	while (n % 2 != 1) {
		cout << "Please enter an odd number : ";
		cin >> n;
	}
	combineFirstHalf(n / 2 + 1, 1);
	combineSecondHalf(2, n - 2);
	return 0;
}