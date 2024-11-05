// Michael Olaoye
// A program that calculates the average scores and grade of student in a computer science class

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct StudentRecord
{
	string studentName;
	double totalPointsExam, totalPointLab;
	double averageGrade;
	char letterGrade;
};

const int MAX_STUDENTS = 50;

void getExamInfo(int& noOfStudents, int& examTotalPoints, int& labTotalPoints);
void getStudentInfo(StudentRecord records[], const int noOfStudents);
void getAverageScoresAndGrade(StudentRecord record[], const int noOfStudents, int examTotalPoints, int labTotalPoints);
void getHighestLowestScore(StudentRecord record[], double & highestScore, double & lowestScore, const int noOfStudent);
void displayInformation(StudentRecord record[], int noOfStudents ,double highestScore, double lowestScore);

int main(void) {

	//VARIABLES
	StudentRecord records[MAX_STUDENTS];
	int noOfStudents, examTotalPoints, labTotalPoints;
	double highestScore, lowestScore;

	//INPUT
	getExamInfo(noOfStudents, examTotalPoints, labTotalPoints);
	getStudentInfo(records, noOfStudents);
	
	//PROCESS
	getAverageScoresAndGrade(records, noOfStudents, examTotalPoints, labTotalPoints);
	getHighestLowestScore(records, highestScore, lowestScore, noOfStudents);

	//OUTPUT
	displayInformation(records, noOfStudents, highestScore, lowestScore);

}

// Get the number of students, exam and lab total possible points
void getExamInfo(int& noOfStudents, int& examTotalPoints, int& labTotalPoints) {
	cout << "Please enter the number of students in the course ? ";
	cin >> noOfStudents;

	cout << "Enter the total EXAM points that are possible for the course: ";
	cin >> examTotalPoints;

	cout << "Enter the total LAB points that are possible for the course: ";
	cin >> labTotalPoints;

	cout << endl;
}

// Get the names of all the students and the points they earned in lab and exam
void getStudentInfo(StudentRecord records[], const int noOfStudents) {
	for (int i = 0; i < noOfStudents; i++) {
		cout << "Please enter Student " << i + 1 << "'s information\n";
		cin.ignore();

		cout << "\tName: ? ";
		getline(cin, records[i].studentName);

		cout << "\tExam Points Earned: ";
		cin >> records[i].totalPointsExam;

		cout << "\tLab Points Earned: ";
		cin >> records[i].totalPointLab;
	}
}

// Find the average and letter grade for each student
void getAverageScoresAndGrade(StudentRecord record[], const int noOfStudents, int examTotalPoints, int labTotalPoints) {
	for (int i = 0; i < noOfStudents; i++) {
		record[i].averageGrade = 100 * ((.60 * (record[i].totalPointsExam / (double)examTotalPoints)) +
								 (.40 * (record[i].totalPointLab / (double)labTotalPoints)));

		// Determine the letter grades
		if (record[i].averageGrade >= 90)
			record[i].letterGrade = 'A';
		else if (record[i].averageGrade >= 80 && record[i].averageGrade < 90)
			record[i].letterGrade = 'B';
		else if (record[i].averageGrade >= 70 && record[i].averageGrade < 80)
			record[i].letterGrade = 'C';
		else if (record[i].averageGrade >= 60 && record[i].averageGrade < 70)
			record[i].letterGrade = 'D';
		else if (record[i].averageGrade < 60)
			record[i].letterGrade = 'F';
	}
}

// Find the highest and lowest scores in the class
void getHighestLowestScore(StudentRecord record[], double & highestScore, double & lowestScore, const int noOfStudents) {
	double highest, lowest;
	//Find highest and lowest average score
	highest = record[0].averageGrade;
	lowest = record[0].averageGrade;
	for (int i = 0; i < noOfStudents; i++) {
		if (record[i].averageGrade > highest)
			highest = record[i].averageGrade;
		if (record[i].averageGrade < lowest)
			lowest = record[i].averageGrade;
	}
	highestScore = highest;
	lowestScore = lowest;

}

// Display all the results
void displayInformation(StudentRecord record[], int noOfStudents, double highestScore, double lowestScore) {
	cout << "Student Name\tExam Pts\tLab Pts\tAverage\tLetter Grade\n";
	cout << "------------\t--------\t-------\t-------\t------------\n";
	cout << setprecision(1) << fixed << showpoint;
	for (int i = 0; i < noOfStudents; i++) {
		cout << record[i].studentName << "\t"
			<< record[i].totalPointsExam << "\t\t"
			<< record[i].totalPointLab << "\t"
			<< record[i].averageGrade << "\t"
			<< record[i].letterGrade << "\n";
	}
	cout << endl;

	cout << "Highest Average: " << highestScore << endl;
	cout << "Lowest Average: " << lowestScore << endl;
	cout << endl;

}

 