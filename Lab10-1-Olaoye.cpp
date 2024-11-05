// Michael Olaoye
// A program that calculates the scores of 4 golf student players 

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

const int NO_OF_STUDENTS = 4;
const int NO_OF_ROUNDS = 3;

void getStudentNames(string studentNames[NO_OF_STUDENTS]);
void getStudentScores(int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS]);
void calStudentAverageScores(int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS], double averageScores[NO_OF_STUDENTS]);
void calStudentAverageScoresPerRound(int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS], double averageScoresPerRound[NO_OF_ROUNDS]);
int getBestStudentAverageScore(double averageScores[NO_OF_STUDENTS]);
void displayInfo(string studentNames[NO_OF_STUDENTS], int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS], double averageScores[NO_OF_STUDENTS], double averageScoresPerRound[NO_OF_ROUNDS], int bestScoreID);

int main() {
	//VARIABLES
	string studentNames[NO_OF_STUDENTS];
	int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS];
	double averageScores[NO_OF_STUDENTS];
	double averageScoresPerRound[NO_OF_ROUNDS];

	int bestScoreID = 0;

	//INPUT
	getStudentNames(studentNames);
	getStudentScores(studentScores);

	//PROCESS
	calStudentAverageScores(studentScores, averageScores);
	calStudentAverageScoresPerRound(studentScores, averageScoresPerRound);
	bestScoreID = getBestStudentAverageScore(averageScores);

	//OUTPUT
	displayInfo(studentNames, studentScores, averageScores, averageScoresPerRound, bestScoreID);



	return 0;
}

//Get student names
void getStudentNames(string studentNames[NO_OF_STUDENTS]) {
	cout << "Please enter the students' names\n\n";
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		cout << "Please enter student " << i + 1 << "'s name: ";
		getline(cin, studentNames[i]);
	}
	cout << endl;
}

//Get each student scores for the 3 rounds
void getStudentScores(int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS]) {
	int score = 0;
	cout << "Please enter the scores for each student per round\n\n";
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		for (int j = 0; j < NO_OF_ROUNDS; j++) {
			do {
				cout << "Please enter student " << i + 1 << "'s " << "round " << j + 1 << " score: ";
				cin >> score;
				if (score < 0)
					cout << "Please enter a score that is not less than  zero\n";
			} while (score < 0);
			studentScores[i][j] = score;
		}	
		cout << endl;
	}
	cout << endl;
}

// Calculate the average for each student
void calStudentAverageScores(int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS], double averageScores[NO_OF_STUDENTS]) {
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		double counter = 0;
		for (int j = 0; j < NO_OF_ROUNDS; j++) {
			counter += studentScores[i][j];
		}
		averageScores[i] = (double)counter / NO_OF_ROUNDS;
	}
}

// Calculate the average for each round
void calStudentAverageScoresPerRound(int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS], double averageScoresPerRound[NO_OF_ROUNDS]) {
	for (int i = 0; i < NO_OF_ROUNDS; i++) {
		double counter = 0;
		for (int j = 0; j < NO_OF_STUDENTS; j++) {
			counter += studentScores[j][i];
		}
		averageScoresPerRound[i] = (double)counter / NO_OF_STUDENTS;
	}
}

// Determine the best average score
int getBestStudentAverageScore(double averageScores[NO_OF_STUDENTS]) {
	int bestScoreID = 0;
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		if (averageScores[i] < averageScores[bestScoreID]) {
			bestScoreID = i;
		}
	}
	return bestScoreID;
}

// Display all info
void displayInfo(string studentNames[NO_OF_STUDENTS], int studentScores[NO_OF_STUDENTS][NO_OF_ROUNDS], double averageScores[NO_OF_STUDENTS], double averageScoresPerRound[NO_OF_ROUNDS], int bestScoreID) {
	cout << endl;
	cout << "Player        Round 1        Round 2        Round 3        Ave./Student\n";
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		cout << studentNames[i]<<"\t";
		for (int j = 0; j < NO_OF_ROUNDS; j++) {
			cout << studentScores[i][j]<<"\t\t";
		}
		cout << fixed << setprecision(1) << showpoint << averageScores[i] << endl;
	}
	
	cout << "Ave./Round \t";
	for (int i = 0; i < NO_OF_ROUNDS; i++) {
		cout << averageScoresPerRound[i]<<"\t\t";
	}
	cout << endl;
	cout << studentNames[bestScoreID] << ", with an average of " << fixed << setprecision(1) << showpoint << averageScores[bestScoreID] << ", was the best student average from the rounds of golf";
	cout << endl;
}

