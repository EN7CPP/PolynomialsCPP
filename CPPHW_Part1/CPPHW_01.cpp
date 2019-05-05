#include <iostream>
#include <string>
using namespace std;



int main()
{
	int n, sum = 0;
	cout << "Please enter the number: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 1) {
			sum += i;
		}
	}
	cout << "The sum is: " << sum << endl;

}