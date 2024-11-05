// Michael Olaoye
// Guess the number game

#include<iostream>
#include<ctime>
#include<iomanip>
#include<string>

using namespace std;

const int NUMBER_POSSIBLE = 100;

// Function Prototypes
string getPlayerName();
void playTheGame(string, int, int, int);

int main(void) {

	int userGuess = 0, rand_number = 0, numberOfAttempts = 0;
	string player_name;
	bool repeat;

	do {
		//Function calls
		player_name = getPlayerName();
		playTheGame(player_name, userGuess, rand_number, numberOfAttempts);

		cout << "Would you like to play again? (1 for yes, 0 for No): ";
		cin >> repeat;
		cin.get();
		cout << endl << endl;   
		
	
	
	} while (repeat);



	return 0;
}

string getPlayerName() {
	string player_name;

	cout << "Welcome to Guess the Number Game" << endl;

	cout << "\nPlease enter your name: ";
	getline(cin, player_name);

	return player_name;
}

void playTheGame(string playerName, int userGuesses, int rand_number, int numberOfAttempts) {

	//Initialize srand function with seed
	srand(time(0));

	//Compute random number (normalized to desired # of possibilities)
	rand_number = rand() % NUMBER_POSSIBLE + 1;

	numberOfAttempts = 0;

	while (userGuesses != rand_number && numberOfAttempts < 7) {
		do {
			cout << endl << playerName << ", Guess a Number Between 1 and 100: ";
			cin >> userGuesses;
		
			if (userGuesses < 1 || userGuesses > NUMBER_POSSIBLE)
				cout << "Invalid number entered - Must be 1 - 100";
		
		} while (userGuesses < 1 || userGuesses > NUMBER_POSSIBLE);
		numberOfAttempts++;

		if (userGuesses == rand_number) {
			cout << "\nCongratulations, you guessed the number " << rand_number << " in " << numberOfAttempts << "!";
		}
		else if (userGuesses < rand_number) {
			cout << "HINT: Guess HIGHER!" << endl;
		}
		else if (userGuesses > rand_number) {
			cout << "HINT: Guess LOWER!" << endl;
		}
	}

	
}
