#include "iostream"
#include "string"
using namespace std;


int calculateFare(int , int , int tip=0 );
int splitAndCalculate(int dist,string s) {
	size_t ind1 = s.find_first_of(' ');// as we are sure of valid input I'm not checking ind!=string::npos
	size_t ind2 = s.find_last_of(' ');
	int ppk = stoi(s.substr(0, ind1));
	if (ind1 == ind2) {
		if (s.substr(ind1 + 1, 4) != "NONE") {
			cout << "Wrong input!" << endl;
			return -1;
		}
		else {
			return calculateFare(ppk, dist);
		}
	}
	else {
		
		if (s.substr(ind1 + 1, 3) != "TIP") {
			cout << "Wrong input!" << endl;
			return -1;
		}
		else {
			int tip = stoi(s.substr(ind2 + 1, s.size() - 1));
			return calculateFare(ppk, dist,tip);
		}
	
	}
	

}
int calculateFare(int ppk, int dist,int tip) {
	if (tip != 0) {
		return ppk*dist + tip;
	}
	else {
		return ppk*dist;
	}
	
}


int main() {

	int faresComputed[3];
	int distance;
	int min;
	int indOfMin=0;
	string arr[3];

	for (int i = 0; i < 3; i++) {
		getline(cin, arr[i]);
	}
	cin >> distance;
	min = splitAndCalculate(distance, arr[0]);
	for (int i = 1; i <=2; i++) {
		int fare = splitAndCalculate(distance, arr[i]);
		if (fare!=-1 && fare< min) {
			min = fare;
			indOfMin = i;
		}
	}
	cout << min << "  " << indOfMin + 1 << endl;
	



	return 0;
}