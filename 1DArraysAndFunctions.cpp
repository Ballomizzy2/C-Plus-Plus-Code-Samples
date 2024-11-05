/******************************************************************************
Name: Michael Olaoye
********************************C**********************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; //introduces namespace std

const int NUMBER_OF_JUDGES = 5;

//get the Contestant's name and scores and calculates the total 
void getNameAndScores(string& name, int& total, int[]);

//calculates the average score using the total from previous function 
double calculateAverage(int total);

//displays name, all scores entered, and average
void displayInformation(string name, double average, int[]);

int main(void)
{
	//Stores score from each judge, total scores, average, and name
	int score[NUMBER_OF_JUDGES] = { 0 };
	int total = 0;
	double average = 0;
	char repeat;
	string name, dummy;

	//Allow user to run program again
	do
	{
		//Resets total to process another contestant if desired
		total = 0;

		getNameAndScores(name, total, score);
        average =  calculateAverage(total);
        displayInformation(name, average, score);

		cout << "\n\n\nWould you like to calculate the average for another contestant? Y or N ";
		cin >> repeat;
		getline(cin, dummy);

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

//get the Contestant's name and scores and calculates the total 
void getNameAndScores(string& name, int& total, int score[])
{
      //Reads contestant's name
		cout << "\nPlease enter the contestants name: ? ";
		getline(cin, name);

		cout << "\nPlease enter the scores from the judges." << endl;

		//Reads scores from each judge
		for (int i = 0; i < NUMBER_OF_JUDGES; i++)
		{
			cout << "\nScore from Judge " << i + 1 << ": ? ";
			cin >> score[i];
			total = total + score[i];
		}
}

//calculates the average score using the total from previous function 
double calculateAverage(int total)
{
	double average = 0;

	//Calcualtes the average score for the contestant
	average = total / double(NUMBER_OF_JUDGES);
	
	return average;
}

//displays name, all scores entered, and average
void displayInformation(string name, double average, int score[])
{
	    //Format output
		cout << setprecision(1) << fixed << showpoint;

		cout << "\n\nThe average score for " << name << " is " << average << endl;

		cout << "\n\nThe  scores entered were: " << endl;

		for (int i = 0; i < NUMBER_OF_JUDGES; i++)
		{
			cout << " " << score[i];
		}	
}

