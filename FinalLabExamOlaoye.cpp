// Michael Olaoye
// A program for a lottery game system

// Files needed (Preprocessor directives)
#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

// Global constants used to control the loops
const int NUMBER_OF_ENTRIES = 7,
		  MAX_STUDENTS = 50;

// Structure variable for each student (holding their name, ID, choices, matches and prize)
struct StudentRecord
{
	int studentID = 0;
	string studentName;
	int numberChoices[NUMBER_OF_ENTRIES] = {0}, matches = 0;
	double prize = 0;
	
};

// Function prototypes
void readInfoFromFile(StudentRecord[MAX_STUDENTS], int & noOfStudents);
void determineWinners(StudentRecord[], const int noOfStudents);
void printResults(StudentRecord[MAX_STUDENTS], const int noOfStudents);
void displayWinReport(StudentRecord student[], const int noOfStudents);


// Main Function
int main(void) {

	//VARIABLES
	StudentRecord students[MAX_STUDENTS]; //array of student structures
	int noOfStudents;

	//INPUT
	readInfoFromFile(students, noOfStudents);
	
	//PROCESS
	determineWinners(students, noOfStudents);

	//OUTPUT
	printResults(students, noOfStudents);
	displayWinReport(students, noOfStudents);

}

// Get the all student information from the file
void readInfoFromFile(StudentRecord student[MAX_STUDENTS], int & noOfStudents){
	// Variabke to read the file
	ifstream inFile;
	int i = 0;

	//open file
	inFile.open("guesses2.txt");

	//if file is invalid or not seen report error
	if (!inFile)
		cout << "****ERROR OPENING INPUT FILE!****\nTRY AGAIN\n";
	
	// else read through the file storing the appropriate information per student
	else {
		while (!inFile.eof()) {
			inFile >> student[i].studentID;
			inFile.ignore();
			getline(inFile, student[i].studentName);
			for (int x = 0; x < NUMBER_OF_ENTRIES; x++)
				inFile >> student[i].numberChoices[x];
			i++;
		}
		noOfStudents = i + 1;
		cout << "Number of students is  " << noOfStudents;
	}
	inFile.close(); //close file after reading the info
}

// Ask the user for the 7 lottery numbers and compare each students numbers with the lottery numbers
void determineWinners(StudentRecord student[], const int noOfStudents) {

	cout << "Please enter the 7 different, random numbers between 1 and 50 that were selected\n";

	int lotteryNumbers[NUMBER_OF_ENTRIES];
	int newInput = 0;
	for (int i = 0; i < NUMBER_OF_ENTRIES; i++) {
		// Request a valid input (1-50) from the user
		do {
			cout << "\nNumber " << i + 1 << " : ";
			cin >> newInput;
		
			if (newInput < 1 || newInput > 50)
				cout << "Please insert a number between 1 and 50\n";

		} while (newInput < 1 || newInput > 50);
		lotteryNumbers[i] = newInput;
	}

	// Compare each students numbers with the lottery numbers and update their matches, numbers may not be in order
	for (int i = 0; i < noOfStudents; i++) {
		for (int j = 0; j < NUMBER_OF_ENTRIES; j++) {
			for (int k = 0; k < NUMBER_OF_ENTRIES; k++) {
				if (student[i].numberChoices[j] == lotteryNumbers[k])
					student[i].matches++;
			}
		}
	}

	// Award the prizes for each player per their matches
	for (int i = 0; i < noOfStudents; i++) {
		switch (student[i].matches) {
			case 7: 
				student[i].prize = 20.00;
				break;
			case 6:
				student[i].prize = 10.00;
				break;
			case 5:
				student[i].prize = 5.00;
				break;
			default:
				break;
		}
	}
}

// Print out the results for each student in alphabetical order
void printResults(StudentRecord student[MAX_STUDENTS], const int noOfStudents) {

	//Bubble sort the list according to the names
	StudentRecord temp;

	for (int i = 0; i < (noOfStudents - 1); i++)
	{
		for (int j = 1; j < noOfStudents; j++)
		{
			string name1 = student[j].studentName;
			string name2 = student[j - 1].studentName;
			int x = 0;
			while (name1[x] != '\0' && (name1[x] == name2[x])) {
				x++;
			}
			
			if (name1[x] < name2[x])
			{
				temp = student[j];
				student[j] = student[j - 1];
				student[j - 1] = temp;
			}

		}
	}

	// Print out the results
	cout << "\n**************************************** Results Report  ****************************************\n";
	cout << "Student ID    Student Name           Chosen Numbers                    Matches        Prize $\n";
	cout << "_______________________________________________________________________________________________\n";
	// The file automatically stores two empty Student Records so I start from the third line
	for (int i = 2; i < noOfStudents; i++) { 
		cout << left;
		cout << setw(15) << student[i].studentID
			 << setw(15) << student[i].studentName;
		cout << right;
		for (int j = 0; j < NUMBER_OF_ENTRIES; j++)
			cout << setw(4) << student[i].numberChoices[j];


		cout << setw(18) << student[i].matches
			 << setw(18) << setprecision(2) << fixed 
			 << showpoint << student[i].prize << "\n";

	}
	cout << endl << endl;
}

// Display the winners of 7, 6, and 5 matches with their results
void displayWinReport(StudentRecord student[], const int noOfStudents) {

	cout << "************ Winnings Report ************\n\n";

	cout << "****** Students Who Matched All 7 Numbers ******\n\n";

	cout << "Student ID    Student Name                Matches        Prize $\n";
	cout << "____________________________________________________________________\n";
	// The file automatically stores two empty Student Records so I start from the third line
	for (int i = 2; i < noOfStudents; i++) { 
		if (student[i].matches == 7) {

			cout << left;
			cout << setw(15) << student[i].studentID
				 << setw(15) << student[i].studentName;
			cout << right;

			cout << setw(18) << student[i].matches
				 << setw(18) << setprecision(2) << fixed 
				 << showpoint << student[i].prize << "\n";
		}

	}
	cout << endl << endl;

	cout << "****** Students Who Matched All 6 Numbers ******\n\n";

	cout << "Student ID    Student Name                Matches        Prize $\n";
	cout << "____________________________________________________________________\n";
	// The file automatically stroes two empty Student Records so I start from the third line
	for (int i = 2; i < noOfStudents; i++) {
		if (student[i].matches == 6) {

			cout << left;
			cout << setw(15) << student[i].studentID
				 << setw(15) << student[i].studentName;
			cout << right;

			cout << setw(18) << student[i].matches
				 << setw(18) << setprecision(2) << fixed 
				 << showpoint << student[i].prize << "\n";
		}

	}
	cout << endl << endl;

	cout << "****** Students Who Matched All 5 Numbers ******\n\n";

	cout << "Student ID    Student Name                Matches        Prize $\n";
	cout << "____________________________________________________________________\n";
	// The file automatically stroes two empty Student Records so I start from the third line
	for (int i = 2; i < noOfStudents; i++) { 
		if (student[i].matches == 5) {

			cout << left;
			cout << setw(15) << student[i].studentID
				 << setw(15) << student[i].studentName;
			cout << right;

			cout << setw(18) << student[i].matches
				 << setw(18) << setprecision(2) << fixed
				 << showpoint << student[i].prize << "\n";
		}

	}
	cout << endl << endl;
}

// end of program
 