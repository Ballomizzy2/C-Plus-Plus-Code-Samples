//Michael Olaoye
//Program that calculates the charge for a phone call

#include <iostream>
#include <iomanip>

using namespace std;
const double FIXED_CHARGE = 1.15,
			 ADDITIONAL_CHARGE = 0.25;

int main(void) {
	//INPUT
	double lengthOfCall, totalCost;
	cout << "Please enter the length of the telephone call in minutes: ";
	cin >> lengthOfCall;
	//PROCESS
	if (lengthOfCall <= 3) {
		totalCost = FIXED_CHARGE;
	}
	else
		totalCost = FIXED_CHARGE + (lengthOfCall - 3) * ADDITIONAL_CHARGE;
	//OUTPUT
	cout << setprecision(2) << fixed << showpoint << endl << endl;
	cout << "The amount of $" << totalCost << 
			" will be charged to your telephone account for the " << setprecision(1) <<
			lengthOfCall << "-minute call\n";

	return 0;
}