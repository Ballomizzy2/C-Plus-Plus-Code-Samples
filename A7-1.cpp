// Michael Olaoye
// A program to calculate the gross pay for an assembly line employee that works for a company that pays all assembly line workers 

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double MINIMUM_TIME = 40,
			 PAY_PER_HOUR = 12.5;

//Function prototypes
string getName();
double getTime();
double computePay(double);
void displayPay(string, double, double);

int main(void) {

	//VARIABLES
	string name;
	double timeWorked = 0,
		   grossPay = 0;
	char restart;

	do {
		//INPUT
		name = getName();
		timeWorked = getTime();

		//PROCESS
		grossPay = computePay(timeWorked);

		//OUTPUT
		displayPay(name, grossPay, timeWorked);

		cout << "\n\nWould you like to calculate another employee's pay? (Y or N) ";
		cin >> restart;
		cin.ignore();
		cout << endl << endl;
	}while (restart == 'Y' || restart == 'y');
	
	return 0;
}

//Function definitions
 string getName() {//Function header
	//Function body
	string _name;
	cout << "Enter the Employee name: ";
	getline(cin, _name);
	return _name;
}

 double getTime(){//Function header
	 //Function body
	 double _time;
	do {
		cout << "Enter the time worked for this pay period: ";
		cin >> _time;
		if (_time < 0)
			cout << "Error: Please enter a positive number!\n";
	} while (_time < 0);
	return _time;
 }

 double computePay(double time) {//Function header
	 //Function body
	 double pay;
	 if (time > MINIMUM_TIME)
		 pay = (time * PAY_PER_HOUR) + (((time - 40) / 2) * PAY_PER_HOUR);
	 else
		pay = time * PAY_PER_HOUR;
	 return pay;
 }

 void displayPay(string _name, double _grossPay, double _timeWorked) {//Function header
	 //Function body
	 cout << endl << endl << setprecision(2) << fixed << showpoint;
	 cout << "Employee Name: " << _name << endl;
	 cout << "Hours Worked: " << _timeWorked << " hours." << endl;
	 cout << "Gross Pay: $" << _grossPay << endl;
 }


