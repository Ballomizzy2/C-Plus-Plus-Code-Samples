/******************************************************************************
Author        : Michael Olaoye

Description   : Prompts the user for the experiment name, number of results, and the value
of each result. Computes and displays the experiment name, total, and 
average of the results.

Input: name of experiment, # of results, and each lab result

Process: 1) while ( there are lab results to be entered)
get result from user and total the results as they are entered

2) calculate average = total / # of results

Output:name of the result, total, and average (3 decimals places)

********************************C**********************************************/
#include <iostream>               
#include <iomanip> 
#include <string>

using namespace std;            //introduces namespace std

//Function Prototypes (declarations)
string getName();
int getNumOfResults();
double calculateTotal(int);
double calculateAverage(double, int);
void display(string, double, double);

int main(void)
{
	// Declaration and Initialization Statements
	int number_of_results = 0, counter = 1;
	double total = 0.0, average = 0.0, result = 0;
	string name;
	char repeat;

	do
	{
		//Function Calls
		name = getName();
		number_of_results = getNumOfResults();
		total = calculateTotal(number_of_results);
		average = calculateAverage(total, number_of_results);
		display(name, total, average);

		cout << "\n\nWould you like to calculate another Experiment (Y or N): ? ";
		cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');

	cout << "\n\nEnd of Program.";

	cout << endl << endl;

	return 0;
}

//Function definitions
string getName() 
{
	string name;
	cout << "\nPlease enter the name of the experiment: ? ";
	getline(cin, name);

	return name;
}
int getNumOfResults() 
{
	int number_of_results;
	// Prompts and gets from the user the number of results for a scientific  
	//     experiment 

	cout << "How many results would you like to enter? ";
	cin >> number_of_results;

	return number_of_results;
}
double calculateTotal(int number_of_results) 
{
	int counter = 1;
	double result, total = 0;
	while (counter <= number_of_results)
	{
		cout << "\nPlease enter a result: ";
		cin >> result;
		total = total + result;
		counter = counter + 1;
	}

	return total;
}
double calculateAverage(double total, int number_of_results) 
{
	return total / number_of_results;
}
void display(string name, double total, double average)
{
	//Displays the total and average of the results entered by the user
	cout << endl << endl;
	cout << fixed << showpoint << setprecision(3);
	cout << endl << endl << name << " Experiment Calculations: " << endl;	
	cout << "The total of the results is: " << total << endl
		 << "The average of the results is: " << average << endl;
}

/*




//Prompts user for the results and accumulates the total 
// of these results as the user enters them



//Calculates the average of the results
average = total / number_of_results;


cout << "The total of the results is: " << total << endl
<< "The average of the results is: " << average << endl;


*/
