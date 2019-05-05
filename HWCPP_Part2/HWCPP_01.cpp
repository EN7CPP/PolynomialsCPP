// CppHW.cpp : Defines the entry point for the console application.
//

#include "iostream"
#include "math.h"
#include "string"
using namespace std;

double funcResult(int * arrPtr, int length, double x) {
	double sum=0;
	for (int i = 0; i < length; i++) {
		sum += (arrPtr[i] * pow(x, i));
	}

	return sum;
}


int main()
{
	int n = -2;
	double x;
	double result;
	string s=" ";
	int * ptrToArr;
	while (n <= 0) {
		cout << "Please enter positive integer n:";
		cin >> n;
	}
	ptrToArr = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Enter coefficient number "<<i+1<<":";
		cin >> ptrToArr[i];
	}
	cin.ignore();
	while (true) {
		cout << "Enter the value of x (Real Number):";
		getline(cin, s);
		if (s != "" ) {        //it will throw an exception if any other character is entered except for numbers
			x = stod(s);
			cout << "f(x)=" << funcResult(ptrToArr, n, x) << endl;
		}
		else break;

	}
	

	
    return 0;
}

