// Michael Olaoye
// Calculate The average score for a science fair student project

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {

	//Variables needed
	string name;
	int noOfJudges = 0, counter = 0;
	float total = 0, average, newNumber;

	//Input
	cout << "Please enter the student's name: ? ";
	getline(cin, name);

	cout << "How many judges scored " << name << "'s project? ";
	cin >> noOfJudges;

	if (noOfJudges < 1) {
		cout << "\nError: Number of judges must be at least 1. Run the program again!.\n";
		return 0;
	}

	cout << "\nEnter the score received from each judge.\n";
	while (counter < noOfJudges) {
		cout << "\t Judge " << counter + 1 << ": ";
		cin >> newNumber;
		total += newNumber;
		counter++;
	}
	cout << endl;

	//Process
	average = total / noOfJudges;

	//Output
	cout << name << "'s Science FAir Project Scores: \n\n"
		<< setprecision(1) << fixed << showpoint
		<< "Total Score............" << total << endl
		<< "Average Score.........." << average << endl;

	return 0;
}