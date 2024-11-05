//Michael Olaoye
//Program that claculates the average score of bowlers

#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

int main(void) {
	//VARIABLES NEEDED
	string bowlerName, dummy;
	int noOfGames, newScore, total;
	float average;
	char decision;

	do {
		//RESET VARIABLES
		total = average = noOfGames = newScore = 0;
		
		//INPUT
		cout << "Enter Bowler name: ? ";
		getline(cin, bowlerName);

		do {
			cout << "Number of games bowled? ";
			cin >> noOfGames;
			if (noOfGames < 1)
				cout << "\n***ERROR: Negative or Zero number for games.***\n\n";
		} while (noOfGames < 1);

		cout << "\nEnter " << bowlerName << " score for each of the following games: \n";

		for (int i = 0; i < noOfGames; i++) {
			do {
				cout << "Game " << i + 1 << ": ? ";
				cin >> newScore;
				if (newScore < 0 || newScore > 300)
					cout << "\n***ERROR: Score must be from 1 to 300***\n";
				else
					total += newScore;
			} while (newScore < 0 || newScore > 300);
		}

		//PROCESS
		average = total / (double)noOfGames;

		//OUTPUT
		cout << "\n\nBowler Results: \n"
			<< "Name: " << bowlerName << "\n"
			<< "Total Score: " << total << "\n"
			<< "Average: " << setprecision(1) << fixed << showpoint << average << "\n\n";

		cout << "Would you like to calculate the average for another bowler? Y or N ?\n";
		cin >> decision;
		getline(cin, dummy);
		cout << endl;
	
	} while (decision == 'Y' || decision == 'y');
	return 0;
}