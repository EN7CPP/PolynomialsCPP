#include "iostream"
#include "string"
using namespace std;

double dailyConv(double t) {
	return 1.8*t + 32;
}

void weeklyConv(double weekTemps[]) {
	for (int i = 0; i<7; i++) {
		weekTemps[i] = dailyConv(weekTemps[i]);
	}
}
double weeklyAverage(double weekTemps[]) {
	double sum = 0;
	for (int i = 0; i<7; i++) {
		sum += weekTemps[i];
	}
	return sum / 7;
}
int main() {
	int numOfWeeks;
	double value;
	cin >> numOfWeeks;
	double ** ptrToArrPtr = new  double *[numOfWeeks];
	for (int i = 0; i<numOfWeeks; i++) {
		ptrToArrPtr[i] = new double[7];
	}
	for (int i = 0; i<numOfWeeks; i++) {
		for (int z = 0; z<7; z++) {
			cin >> value;
			ptrToArrPtr[i][z] = value;
		}
		weeklyConv(ptrToArrPtr[i]);
	}

	for (int i = 0; i<numOfWeeks; i++) {
		for (int z = 0; z<7; z++) {
			cout << ptrToArrPtr[i][z] << " ";
		}
		cout << " average: ";
		cout << weeklyAverage(ptrToArrPtr[i]) << endl;
	}




}