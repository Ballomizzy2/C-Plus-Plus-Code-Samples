/******************************************************************************
Name: Michael Olaoye
********************************C**********************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std; //introduces namespace std

const int NUMBER_OF_JUDGES = 50;

//get the Contestant's name and scores and calculates the total 
int getNameAndScores(string& name, int& total, int[]);

//calculates the average score using the total from previous function 
double calculateAverage(int total, int);

//displays name, all scores entered, and average
void displayInformation(string name, double average, int[], int judges);

int main(void)
{
	//Stores score from each judge, total scores, average, and name
	int score[NUMBER_OF_JUDGES] = { 0 };
	int total = 0;
	double average = 0;
	char repeat;
	string name, dummy;
	int judges = 0;

	//Allow user to run program again
	do
	{
		//Resets total to process another contestant if desired
		total = 0;

		judges = getNameAndScores(name, total, score);
		average = calculateAverage(total, judges);
		displayInformation(name, average, score, judges);

		cout << "\n\n\nWould you like to calculate the average for another contestant? Y or N ";
		cin >> repeat;
		getline(cin, dummy);

	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}

//get the Contestant's name and scores and calculates the total 
int getNameAndScores(string& name, int& total, int score[])
{
	//Reads contestant's name
	cout << "\nPlease enter the contestants name:  ";
	getline(cin, name);

	cout << "\nPlease enter the scores from the judges." << endl;
	cout << "\nEnter -1 when finished." << endl;

	int i = 0;
	//Reads scores from each judge
	for (i = 0; i < NUMBER_OF_JUDGES; i++)
	{
		cout << "\nScore from Judge " << i + 1 << ": ? ";
		cin >> score[i];
		if (score[i] == -1)
			break;
		total = total + score[i];
	}
	return i;
}

//calculates the average score using the total from previous function 
double calculateAverage(int total, int judges)
{
	double average = 0;

	//Calcualtes the average score for the contestant
	average = total / double(judges);

	return average;
}

//displays name, all scores entered, and average
void displayInformation(string name, double average, int score[], int judges)
{
	//Format output
	cout << setprecision(1) << fixed << showpoint;

	cout << "\n\nThe average score for " << name << " is " << average << endl;

	cout << "\n\nThe  scores entered were: " << endl;

	for (int i = 0; i < judges; i++)
	{
		cout << " " << score[i];
	}
}

