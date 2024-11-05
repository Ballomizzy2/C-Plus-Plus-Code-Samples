// Michael Olaoye
// Program that detects whether a user input is even or odd and positive or negative

#include <iostream>

using namespace std;

//Function prototypes
int getNumber();
string determineEvenOrOdd(int);
string determinePositiveOrNegative(int);
void displayResults(int, string, string);

int main(void) {

	//VARIABLES
	int number;
	string evenOrOdd, positiveOrNegative;
	char repeat;

	do {
	
		//INPUT
		number = getNumber();
		
		//PROCESS
		evenOrOdd = determineEvenOrOdd(number);
		positiveOrNegative = determinePositiveOrNegative(number);
		
		//OUTPUT
		displayResults(number, evenOrOdd, positiveOrNegative);

		cout << "Would you like to process another number? < Y or N > ";
		cin >> repeat;
		cout << endl << endl;

	} while (repeat == 'Y' || repeat == 'y');

	return 0;
}

int getNumber() {
	int num;
	do {
		cout << "Please enter the number to be determined as even / odd or positive / negative:";
		cin >> num;
		if (num < -10000 || num > 10000) {
			cout << "Please enter a number between -10,000 and 10,000\n\n";
		}
	} while (num < -10000 || num > 10000);
	return num;
}

string determineEvenOrOdd(int _number) {
	if (_number % 2 == 0)
		return "even";
	else
		return "odd";
}

string determinePositiveOrNegative(int _number) {
	if (_number >= 0)
		return "positive";
	else
		return "negative";
}

void displayResults(int _num, string _evenOrOdd, string _positiveOrNegative) {
	cout << "\nThe number you entered, " << _num << " is a " << _positiveOrNegative
		 << ", " << _evenOrOdd << " value" << endl << endl;
}
