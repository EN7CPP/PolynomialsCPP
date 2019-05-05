#include <iostream>
#include <math.h>
using namespace std;



int main()
{
	double pi=0;
	for (int k = 0; k<1000; k++) {
		pi += pow(-1, k) * 4 / (2 * k + 1);
		cout << "Element N" << k+1 << ": " << pi << endl;
	}

	return 0;
}