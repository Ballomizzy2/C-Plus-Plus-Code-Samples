// Michael Olaoye
// A program that calculates the average of scores for an exams and categorizes into letter grades

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int NO_OF_STUDENTS = 12;

void getExamInfo(string&, int scores[NO_OF_STUDENTS]);
void getHighestAndLowest(int scores[NO_OF_STUDENTS], int&, int&);
double calculateAverage(int scores[NO_OF_STUDENTS]);
void calculateNoOfStudentsPassed(int scores[NO_OF_STUDENTS], int& pass, int& fail);
void findAmountPerGrade(int scores[NO_OF_STUDENTS], int& a, int& b, int& c, int& d, int& f);
void displayInformation(string name, int scores[NO_OF_STUDENTS], double average, int highest, int lowest, int passed, int failed, int a, int b, int c, int d, int f);

int main() {
	string examName;
	int scores[NO_OF_STUDENTS] = { 0 };
	int highestScore, lowestScore,
		passStudents, failStudents;
	double average;
	int a, b, c, d, f;
	char repeat;

	do {
		//INPUT
		getExamInfo(examName, scores);
		
		//PROCESS
		getHighestAndLowest(scores, highestScore, lowestScore);
		average = calculateAverage(scores);
		calculateNoOfStudentsPassed(scores, passStudents, failStudents);
		findAmountPerGrade(scores, a, b, c, d, f);

		//OUTPUT
		displayInformation(examName, scores, average, highestScore, lowestScore, passStudents, failStudents, a, b, c, d, f);
		
		cout << "Would you like to calculate the average for another exam? <Y or N> ";
		cin >> repeat;
		cin.ignore();
	} while (repeat == 'Y' || repeat == 'y');




	return 0;
}

// Get the name of the exam and the 12 scores from the user
void getExamInfo(string& examName, int scores[NO_OF_STUDENTS]) {
	cout << "Please enter the name of the exam: ? ";
	getline(cin, examName);

	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		int score;
		do {
			cout << "Enter score " << i + 1 << " :? ";
			cin >> score;
			if (!(score >= 0 && score <= 100))
				cout << "Please eneter a score between 0 and 100\n";
		} while (!(score >= 0 && score <= 100));
		scores[i] = score;
	}
	cout << endl;
}

// Get the highest and lowest score from the list of scores given by the user
void getHighestAndLowest(int scores[NO_OF_STUDENTS], int& high, int& low) {
	int highest = 0, lowest = scores[0];
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		if (scores[i] > highest)
			highest = scores[i];
		if (scores[i] < lowest)
			lowest = scores[i];
	}
	high = highest;
	low = lowest;
}

// Calculate the average of the scores enetered by the user
double calculateAverage(int scores[NO_OF_STUDENTS]) {
	int sum = 0;
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		sum += scores[i];
	}
	return sum / (double)NO_OF_STUDENTS;
}

// Calculate the number of students who passed and failed respectively
void calculateNoOfStudentsPassed(int scores[NO_OF_STUDENTS], int& pass, int& fail) {
	int noOfPass = 0, noOfFail = 0;
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		if (scores[i] >= 60)
			noOfPass++;
		else
			noOfFail++;
	}
	pass = noOfPass;
	fail = noOfFail;
}

// Categorize each score to grade A, B, C, D, F and calculate the amount for each grade
void findAmountPerGrade(int scores[NO_OF_STUDENTS], int& a, int& b, int& c, int& d, int& f){
	int _a = 0, _b = 0, _c = 0, _d = 0, _f = 0;
	for (int i = 0; i < NO_OF_STUDENTS; i++) {
		if (scores[i] >= 90)
			_a++;
		else if (scores[i] >= 80 && scores[i] < 90)
			_b++;
		else if (scores[i] >= 70 && scores[i] < 80)
			_c++;
		else if (scores[i] >= 60 && scores[i] < 70)
			_d++;
		else if (scores[i] < 60)
			_f++;
	}
	a = _a;
	b = _b;
	c = _c;
	d = _d;
	f = _f;
}

// Display all the information about the exams
void displayInformation(string name, int scores[NO_OF_STUDENTS], double average, int highest, int lowest, int passed, int failed, int a, int b, int c, int d, int f) {
	cout << "The scores for " << name << " are: \n";
	for (int i = 0; i < NO_OF_STUDENTS; i++)
		cout << scores[i] << " ";
	cout << endl;

	cout << "The average score is " << setprecision(2) << fixed << showpoint << average << endl << endl;
	cout << "The highest score is " << highest << endl;
	cout << "The lowest score is " << lowest << endl << endl;

	cout << "Number of Students who passed: " << passed << endl;
	cout << "Number of Students who failed: " << failed << endl << endl;

	cout << "The number of exams represented by each letter grade is as follows: \n";
	cout << "A's: " << a << endl;
	cout << "B's: " << b << endl;
	cout << "C's: " << c << endl;
	cout << "D's: " << d << endl;
	cout << "F's: " << f << endl;
	cout << endl;

}
