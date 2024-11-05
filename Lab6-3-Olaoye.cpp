//Michael Olaoye
//Program that calculates the average of a gymnastics team

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {

	//VARIABLES
	int noOfGymnasts = 0, noOfEvents = 0, noOfPoints = 0, total = 0, totalTeamPoints = 0;
	float average, totalAverage = 0, averageTeamPointPerEvent = 0;
	string gymnastName, dummy;
	char desicion;

	cout <<
		"************************************************************\n"
		"* This program calculates the total and average            *\n"
		"*  points for each member of a gymnastics team.            *\n"
		"* The team's total and average points are also calculated. *\n"
		"* **********************************************************\n\n\n";
	do {
		
		noOfGymnasts = noOfEvents = noOfPoints = total = average = 
			totalTeamPoints = totalAverage = averageTeamPointPerEvent = 0;

		//INPUT
		cout << "\nPlease enter the number of gymnasts on the team:? ";
		cin >> noOfGymnasts;
		getline(cin, dummy);

		cout << "Please enter the number of events the team competed in:? ";
		cin >> noOfEvents;
		getline(cin, dummy);

		cout << "\n\n";
		
		for (int i = 0; i < noOfGymnasts; i++) {
			cout << "\nEnter gymnast " << i + 1 << "'s name: ? ";
			getline(cin, gymnastName);

			cout << "Enter the point earned by " << gymnastName << " for each event\n";

			for (int j = 0; j < noOfEvents; j++) {
				do {
					cout << "Event " << j + 1 << ": ? ";
					cin >> noOfPoints;
					getline(cin, dummy);

					if (noOfPoints < 0 || noOfPoints > 10)
						cout << "***ERROR- INVALID SCORE - PLEASE RE-ENTER ****\n";
					else {
						total += noOfPoints;
					}
						
				} while (noOfPoints < 0 || noOfPoints > 10);
			}
			average = total / (double)noOfEvents;
			cout << "\n\n" << gymnastName << ":\n"
				<< "   Total Points: " << total
				<< "\n   Avearge Points: " << setprecision(1) << fixed << showpoint << average << endl;
			totalAverage += average;
			totalTeamPoints += total;
			average = total = 0;
		}

		averageTeamPointPerEvent = totalAverage / (double)noOfGymnasts;
		cout << "\n\n Total Team Points: " << totalTeamPoints << endl;
		cout << "Average Team Points Per Event: " << setprecision(1) << fixed << showpoint << averageTeamPointPerEvent << "\n\n";

		cout << "Would you like to calculate the stats on another team? Y or N?";
		cin >> desicion;
		getline(cin, dummy);

	} while (desicion == 'Y' || desicion == 'y');


	return 0;
}