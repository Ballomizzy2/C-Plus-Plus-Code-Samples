//Name:
// Pass-by-Value vs Pass-by-Reference

#include <iostream>
#include <string>
using namespace std;

void newVal(double& , double&);

int main()
{
	double firstnum, secondnum;

	cout << "Enter two real numbers separated by a space: ";
	cin >> firstnum >> secondnum;

	cout << "\nThe value in firstnum is " << firstnum << endl;
	cout << "\nThe value in secondnum is " << secondnum << endl;

	newVal(firstnum, secondnum);

	cout << "\nThe value in firstnum in main after function call: " << firstnum << endl;
	cout << "\nThe value in secondnum in main after function call: " << secondnum << endl;

	return 0;
}

void newVal(double& firstnum, double& secondnum)
{
	cout << "\nThe value in firstnum in function newVal: " << firstnum << endl;
	cout << "\nThe value in secondnum in function newVal: " << secondnum << endl;

	firstnum = 89.5;
	secondnum = 99.5;

	cout << "\nThe value in firstnum in function newVal is now: " << firstnum << endl;
	cout << "\nThe value in secondnum in function newVal is now: " << secondnum << endl;
}

//Output from Pass-by-Value
/*
Enter two real numbers separated by a space : 22.5 33.1
The value in firstnum is 22.5
The value in secondnum is 33.1
The value in firstnum in function newVal : 22.5
The value in secondnum in function newVal : 33.1
The value in firstnum in function newVal is now : 89.5
The value in secondnum in function newVal is now : 99.5
The value in firstnum in main after function call : 22.5
The value in secondnum in main after function call : 33.1
*/
		

//Output from Pass-by-Reference
/*
Enter two real numbers separated by a space : 22.5 33.1
The value in firstnum is 22.5
The value in secondnum is 33.1
The value in firstnum in function newVal : 22.5
The value in secondnum in function newVal : 33.1
The value in firstnum in function newVal is now : 89.5
The value in secondnum in function newVal is now : 99.5
The value in firstnum in main after function call : 89.5
The value in secondnum in main after function call : 99.5
*/