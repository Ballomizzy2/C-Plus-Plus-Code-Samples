// Michael Olaoye
// Program that calcuates speeding ticket charge

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {
	//Input
	double clockedSpeed, areaSpeedLimit, ticketCharge, amountOverLimit;
	string driverName;

	cout << "Enter Driver Name: ";
	getline(cin, driverName);

	cout << "Enter Clocked Speed (mph): ";
	cin >> clockedSpeed;
	
	cout << "Enter Area Speed Limit: ";
	cin >> areaSpeedLimit;

	//Process
	amountOverLimit = clockedSpeed - areaSpeedLimit;

	if (clockedSpeed >= 10 && clockedSpeed <= 20) {
		ticketCharge = 100;
	}
	else if (clockedSpeed > 20 && clockedSpeed <= 30) {
		ticketCharge = 200;
	}
	else if (clockedSpeed > 30 && clockedSpeed <= 40) {
		ticketCharge = 300;
	}
	else if (clockedSpeed > 40) {
		ticketCharge = 500;
	}
	else {
		cout << "Wrong input! Restart \n\n\n";
		return 0;
	}

	//Output
	cout << "\n\nSpeeding Ticket Charge for " << driverName << endl << endl;
	cout << "\tClocked Speed:         " << clockedSpeed << " mph\n";
	cout << "\tArea Speed Limit:      " << areaSpeedLimit << " mph\n";
	cout << "\tAmount Over Limit:     " << amountOverLimit << " mph\n\n";
	cout << setprecision(2) << fixed << showpoint <<
		"Ticket Charge...............$" << ticketCharge << endl;


}