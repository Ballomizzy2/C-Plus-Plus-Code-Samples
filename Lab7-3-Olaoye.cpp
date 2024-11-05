// Michael Olaoye
// a program that will calculate the average score and letter grade earned by a student in any course

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//Function prototypes
string getStudentName();
int getNumberOfExams();
double getScoresAndCalculateTotal(int);
double calculateAverage(double, int);
string determineLetterGrade(double);
void displayAverageGrade(string, double, string);


int main(void) {

	//VARIABLES
	string studentName, grade;
	int noOfExams;
	double total, average;
	char repeat;

	do {

		//INPUT
		studentName = getStudentName();
		noOfExams = getNumberOfExams();

		//PROCESS
		total = getScoresAndCalculateTotal(noOfExams);
		average = calculateAverage(total, noOfExams);
		grade = determineLetterGrade(average);

		//OUTPUT
		displayAverageGrade(studentName, average, grade);

		cout << "\nWould you like to calculate another student\'s grade? < Y or N > ";
		cin >> repeat;
		cin.ignore();
		cout << endl << endl;
	} while (repeat == 'Y' || repeat == 'y');
	return 0;
}

string getStudentName() {
	string _name;
	cout << "Please enter the student\'s name: ";
	getline(cin, _name);
	return _name;
}

int getNumberOfExams() {

	int _noOfExams;
	do {
		cout << "Please enter the number of exams taken by the student in the course : ";
		cin >> _noOfExams;

		if (_noOfExams < 1) {
			cout << "Please input a number greater than or equal to 1\n";
		}
	} while (_noOfExams < 1);
	cout << endl;
	return _noOfExams;
}

double getScoresAndCalculateTotal(int _noOfExams) {
	double _total = 0;
	int newNum = 0;
	cout << "Enter the exam scores: \n";
	for (int i = 0; i < _noOfExams; i++) {
		cout << "Exam " << i + 1 << ":? ";
		cin >> newNum;
		_total += newNum;
	}
	return _total;
}

double calculateAverage(double _total, int _noOfExams) {
	return _total / (double)_noOfExams;
}

string determineLetterGrade(double _average) {
	if (_average >= 90 && _average < 100)
		return "A";
	else if (_average >= 80 && _average < 90)
		return "B";
	else if (_average >= 70 && _average < 80)
		return "C";
	else if (_average >= 60 && _average < 70)
		return "D";
	else if (_average >= 0 && _average < 60)
		return "F";
	else
		return "W";
}

void displayAverageGrade(string _name, double _average, string _grade) {
	cout << "\nStudent Name: " << _name << endl;
	cout << setprecision(1) << fixed << showpoint << "Average: " << _average << endl;
	cout << "Letter Grade Earned: " << _grade << endl;
}