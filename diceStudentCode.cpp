// NAME: Michael Olaoye
/* Rules:
The user will enter a wager amount. The wager is an integer value greater than $5.00.
If the sum of the dice is 7, the user doubles the wager.
If the sum of the dice is EVEN (dice_1_roll + dice_2_roll) %2) == 0 ), the user wins $2.
If the sum of the dice is ODD (dice_1_roll + dice_2_roll) %2) == 1), the user loses $2.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

void drawDice(int);

int main()
{
	//Variable Declaration
	int dice_1_roll = 0; //stores the first random number from 1 to 6 to represent the first dice roll
	int dice_2_roll = 0; //stores the second random number from 1 to 6 to represent the second dice roll
	int seed = 0; //declare a seed variable
	int wager = 0; //declare a variable for user's money wager
	
	//Prompt for amount wager:
	cout << "Enter your wager: ($5 minimum): ";
	cin >> wager;

	if (wager < 5) {
		//display "Your wager of $" (the wager amount) " is less than required $5" starting at position 150, 200
		cout << "Your wager $" << wager << " is less than required $ 5" << endl;
		cout << "Please re-run program and enter larger amount" << endl;
	}
	else {

		//Initialize random # generator
		srand(time(0));

		//Generate two random # between 1 and 6 inclusive
		dice_1_roll = (rand() % 6) + 1;
		dice_2_roll = (rand() % 6) + 1;

		//Display the first dice
		if (dice_1_roll == 1)
			drawDice(dice_1_roll); //display dice face 1 
		else if (dice_1_roll = 2)
			drawDice(dice_1_roll); //display dice face 2 
		else if (dice_1_roll == 3)
			drawDice(dice_1_roll);  //display dice face 3 
		else if (dice_1_roll == 4)
			drawDice(dice_1_roll);  //display dice face 4
		else if (dice_1_roll == 5)
			drawDice(dice_1_roll);  //display dice face 5 
		else if (dice_1_roll == 6)
			drawDice(dice_1_roll); //display dice face 6 
		else
			cout << "Impossible option!" << endl;

		//Display the 2nd dice
		if (dice_2_roll == 1)
			drawDice(dice_2_roll);  //display dice face 1 
		else if (dice_2_roll == 2)
			drawDice(dice_2_roll); //display dice face 2 
		else if (dice_2_roll == 3)
			drawDice(dice_2_roll); //display dice face 3 
		else if (dice_2_roll == 4)
			drawDice(dice_2_roll);  //display dice face 4 
		else if (dice_2_roll == 5)
			drawDice(dice_2_roll); //display dice face 5 
		else if (dice_2_roll == 6)
			drawDice(dice_2_roll);  //display dice face 6 
		else
			cout << "Impossible option!" << endl;

		//Display the total at position 
		cout << "Dice Total: " << (dice_1_roll + dice_2_roll) << endl;

		//Check for the winner
		if (dice_1_roll + dice_2_roll == 7)
		{
			//display text You're Lucky Today 
			cout <<"You're Lucky Today!" << endl;
			//display text "You double your wager " 
			cout <<"You double your wager " << endl;
			//display text "Your Winnings: $" 
			cout << "Your Winnings: $" << wager << " + " << "Original Wager = $" << wager << " = $" << 2 * wager << endl;
		}
		else if (((dice_1_roll + dice_2_roll) % 2) == 0)
		{
			// display text "You win $2 extra for even roll!" 
			cout << "You win $2 extra for even roll!" << endl;
			cout << "Your Winnings: $2 + Original Wager: $" << wager << " = $" << (wager + 2) << endl;
			cout << "Congratulations!" << endl;
		}
		else if (((dice_1_roll + dice_2_roll) % 2) == 1)
		{
			// display text "You loose $2 for odd roll!" 
			cout << "You loose $2 for odd roll!" << endl;
			cout << "Original Wager: $" << wager << " - Losses: $2 = $" << wager - 2 << endl;
			cout << "SORRY!!!" << endl;
		}
	}


	return 0;
}

void drawDice(int number)
{
		cout << "_______" << endl;
		if(number == 1)
		{ 
			
			cout << "| " << '*' << "   |" << endl;
			cout << "|" << "     |" << endl;
			cout << "|_____|" << endl;
	    }
		else if (number == 2)
		{

			cout << "| " << "* *" << " |" << endl;
			cout << "|" << "     |" << endl;
			cout << "|_____|" << endl;
		}
		else if (number == 3)
		{

			cout << "| " << "* *" << " |" << endl;
			cout << "| *" << "   |" << endl;
			cout << "|_____|" << endl;
		}
		else if (number == 4)
		{

			cout << "| " << "* *" << " |" << endl;
			cout << "| * *" << " |" << endl;
			cout << "|_____|" << endl;
		}
		else if (number == 5)
		{

			cout << "| " << "* *" << " |" << endl;
			cout << "| * *" << " |" << endl;
			cout << "| *" << "   |" << endl;
			cout << "|_____|" << endl;
		}
		else if (number == 6)
		{

			cout << "| " << "* *" << " |" << endl;
			cout << "| * *" << " |" << endl;
			cout << "| * *" << " |" << endl;
			cout << "|_____|" << endl;
		}


}
