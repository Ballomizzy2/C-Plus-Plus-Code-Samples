//Name: Michael Olaoye

#include<iostream>
#include<string>
#include <iomanip>

using namespace std;  //introduces namespace std

const int COUNT = 3;
struct StudentRecord
{
	int ID;
	string name;
	string address;
	string city;
	string state;
	int zip;
};

void getStudentInfo(StudentRecord student[]);
void displayStudentInfo(StudentRecord student[COUNT]);


int main()
{
	StudentRecord student[COUNT];

	getStudentInfo(student);
	displayStudentInfo(student);
	

	cout << endl << endl;
	return 0;
}

void getStudentInfo(StudentRecord student[])
{
	string dummy;
	for (int i = 0; i < COUNT; i++)
	{
		cout << "Enter Student " << i + 1 << " ID: ";
		cin >> student[i].ID;
		getline(cin, dummy);
		cout << "Enter Student " << i + 1 << " name: ";
		getline(cin, student[i].name);
		cout << "Enter Student " << i + 1 << " Address: ";
		getline(cin, student[i].address);
		cout << "Enter Student " << i + 1 << " City: ";
		getline(cin, student[i].city);
		cout << "Enter Student " << i + 1 << " State: ";
		cin >> student[i].state;
		cout << "Enter Student " << i + 1 << " Zip: ";
		cin >> student[i].zip;
		cout << endl << endl;
	}
}

void displayStudentInfo(StudentRecord student[COUNT])
{
	cout << "ID     Name      Address    City   State   Zip" << endl;
	for (int i = 0; i < COUNT; i++)
	{
		cout << setw(5) << left << student[i].ID;
		cout << setw(12) << student[i].name;
		cout << setw(10) << student[i].address;
		cout << setw(10) << student[i].city;
		cout << setw(5) << student[i].state;
		cout << setw(7) << student[i].zip;
		cout << endl;
	}
}

//student1.ID = 11;
//student1.name = "Bob Smith";
//student1.address = "2 Ash Dr.";
//student1.city = "Conway";
//student1.state = "AR";
//student1.zip = 72034;
//
//student2.ID = 22;
//student2.name = "Sue Hill";
//student2.address = "3 Elm St.";
//student2.city = "Conway";
//student2.state = "AR";
//student2.zip = 72032;
//
//cout << student1.ID << endl;
//cout << student1.name << endl;
//cout << student1.address << endl;
//cout << student1.city << endl;
//cout << student1.state << endl;
//cout << student1.zip << endl;
//
//cout << student2.ID << endl;
//cout << student2.name << endl;
//cout << student2.address << endl;
//cout << student2.city << endl;
//cout << student2.state << endl;
//cout << student2.zip << endl;