//Name: Michael Olaoye
// Program that prints the address of students, both college and home address

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;  //introduces namespace std

const int COUNT = 50;

// address structure
struct Address {
	string streetAddress, city_state;
	int  zipCode;
};

//student structure nested with address
struct Student
{
	string name;
	Address homeAddress;
	Address collegeAddress;
};

// Function prototypes
int getNumberOfStudents();
void getStudentInfo(Student student[COUNT], const int noOfStudents);
void displayStudentInfo(Student student[COUNT], const int noOfStudents);

int main()
{
	Student student[COUNT];
	int noOfStudents = 0;

	// Function calls
	noOfStudents = getNumberOfStudents();

	getStudentInfo(student, noOfStudents);
	displayStudentInfo(student, noOfStudents);

	cout << endl << endl;
	return 0;
}

// get number of students from user
int getNumberOfStudents() {
	
	int number;
	do {
		cout << "Number of Students (must be a positive number less than or equal to 50): ";
		cin >> number;
			if (number < 1 || number > 50)
				cout << "Please enter a number in the range!\n";
	} while (number < 1 || number > 50);
	
	return number;
}

// get all the students information
void getStudentInfo(Student student[COUNT], const int noOfStudents)
{
	string dummy;
	for (int i = 0; i < noOfStudents; i++)
	{
		getline(cin, dummy);

		cout << "Enter Student " << i + 1 << " information: \n";
		cout << "Name: ";
		getline(cin, student[i].name);

		cout << "\tHome Address: \n";
		cout << "\t\tStreet Address: ";
		getline(cin, student[i].homeAddress.streetAddress);
		cout << "\t\tCity/ State: ";
		getline(cin, student[i].homeAddress.city_state);
		cout << "\t\tZip Code: ";
		cin >> student[i].homeAddress.zipCode;
		cout << endl;
		getline(cin, dummy);

		cout << "\tCollege Address: \n";
		cout << "\t\tStreet Address: ";
		getline(cin, student[i].collegeAddress.streetAddress);
		cout << "\t\tCity/ State: ";
		getline(cin, student[i].collegeAddress.city_state);
		cout << "\t\tZip Code: ";
		cin >> student[i].collegeAddress.zipCode;

		cout << endl << endl;
	}
}

// display all the information
void displayStudentInfo(Student student[COUNT], const int noOfStudents)
{
	cout << "The Student Address report is:\n\n";
	for (int i = 0; i < noOfStudents; i++)
	{
		cout << student[i].name << endl;
		cout << "\tHome: " << student[i].homeAddress.streetAddress
			<< "\n\t\t" << student[i].homeAddress.city_state
			<< " " << student[i].homeAddress.zipCode;
		cout << endl;
		cout << "\tCollege: " << student[i].collegeAddress.streetAddress
			<< "\n\t\t" << student[i].collegeAddress.city_state
			<< " " << student[i].collegeAddress.zipCode;


		cout << endl << endl;
	}
}