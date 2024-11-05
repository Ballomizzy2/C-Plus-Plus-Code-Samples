// Michael Olaoye
// Categorizes a group of integers into even, odd, positive and negative numbers

#include <iostream>

using namespace std;

const int NO_OF_INTEGERS = 20;

void getIntegers(int integers[NO_OF_INTEGERS]);
void getPositiveAndNegativeIntegers(int integers[NO_OF_INTEGERS], int positiveIntegers[], int negativeIntegers[], int& positiveAmt, int& negativeamt);
void getEvenAndOddIntegers(int integers[NO_OF_INTEGERS], int evenIntegers[], int oddIntegers[], int& evenAmt, int& oddAmt);
void displayAllInfo(int integers[NO_OF_INTEGERS], int positiveIntegers[], int negativeIntegers[], int evenIntegers[], int oddIntegers[], int& positiveAmt, int& negativeAmt, int& evenAmt, int& oddAmt);

int main() {
	int noOfPositive = 0,
		noOfNegative = 0,
		noOfEven = 0,
		noOfOdd = 0;

	int integers[NO_OF_INTEGERS] = { 0 };
	int positiveIntegers[NO_OF_INTEGERS] = { 0 };
	int negativeIntegers[NO_OF_INTEGERS] = { 0 };
	int evenIntegers[NO_OF_INTEGERS] = { 0 };
	int oddIntegers[NO_OF_INTEGERS] = { 0 };

	
	char repeat;

	do {

		//INPUT
		getIntegers(integers);

		//PROCESS
		getPositiveAndNegativeIntegers(integers, positiveIntegers, negativeIntegers, noOfPositive, noOfNegative);
		getEvenAndOddIntegers(integers, evenIntegers, oddIntegers, noOfEven, noOfOdd);

		//OUTPUT
		displayAllInfo(integers, positiveIntegers, negativeIntegers, evenIntegers, oddIntegers, noOfPositive, noOfNegative, noOfEven, noOfOdd);

		cout << "\nWould you like to process another 20 integers?\n";
		cout << "Please enter 'y' for yes or 'n' for no: ";
		cin >> repeat;
		cout << endl;
	} while (repeat == 'Y' || repeat == 'y');


	return 0;
}

// Get the 20 integers from the user and populate the integer array
void getIntegers(int integers[NO_OF_INTEGERS]) {
	cout << "This program inputs 20 integers and places them into even, odd, positive, or negative categories.\n\n";
	cout << "Please enter 20 integers\n";
	for (int i = 0; i < NO_OF_INTEGERS; i++) {
		cout << "Integer " << i + 1 << " = ? ";
		cin >> integers[i];
	}
		
}

// Get the positive integers from the array
void getPositiveAndNegativeIntegers(int integers[NO_OF_INTEGERS], int positiveIntegers[], int negativeIntegers[], int& positiveAmt, int& negativeAmt) {
	int positiveCount = 0, negativeCount = 0;
	for (int i = 0; i < NO_OF_INTEGERS; i++) {
		if (integers[i] >= 0) {
			positiveIntegers[positiveCount] = integers[i];
			positiveCount++;
		}
		else {
			negativeIntegers[negativeCount] = integers[i];
			negativeCount++;
		}
	}
	positiveAmt = positiveCount;
	negativeAmt = negativeCount;
}

// Get the even and odd integers from the array
void getEvenAndOddIntegers(int integers[NO_OF_INTEGERS], int evenIntegers[], int oddIntegers[], int& evenAmt, int& oddAmt) {
	int evenCount = 0, oddCount = 0;
	for (int i = 0; i < NO_OF_INTEGERS; i++) {
		if (integers[i] % 2 == 0) {
			evenIntegers[evenCount] = integers[i];
			evenCount++;
		}
		else {
			oddIntegers[oddCount] = integers[i];
			oddCount++;
		}
	}
	evenAmt = evenCount;
	oddAmt = oddCount;
}  

// Display all the processed information
void displayAllInfo(int integers[NO_OF_INTEGERS], int positiveIntegers[], int negativeIntegers[], int evenIntegers[], int oddIntegers[], int& positiveAmt, int& negativeAmt, int& evenAmt, int& oddAmt) {
	cout << endl;

	cout << "The even integers are: \n";
	for (int i = 0; i < evenAmt; i++) {
		cout << evenIntegers[i] << " ";
	}
	cout << endl;

	cout << "\nThe odd integers are: \n";
	for (int i = 0; i < oddAmt; i++) {
		cout << oddIntegers[i] << " ";
		
	}
	cout << endl;
	
	cout << "\nThe positive integers are: \n";
	for (int i = 0; i < positiveAmt; i++) {
		cout << positiveIntegers[i] << " ";
	}
	cout << endl;

	cout << "\nThe negative integers are: \n";
	for (int i = 0; i < negativeAmt; i++) {
		cout << negativeIntegers[i] << " ";
	}
	cout << endl;


}

