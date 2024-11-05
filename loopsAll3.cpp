
//Name: Michael Olaoye

//Complete the source code below by replacing the ???? with code to produce the 
//the following output.
/*
While loop output:
1  2  3  4  5  6  7  8  9  10

for loop output:
1  2  3  4  5  6  7  8  9  10

Do_while loop output:
1  2  3  4  5  6  7  8  9  10
*/


#include <iostream>
#include <iomanip>
using namespace std;

const int END_VALUE = 10;

int main(void)
{
	int number = 1;

	cout << "While loop output: " << endl;
	while (number <= 10)
	{
		cout << setw(4) << number;
		number++;
	}

	cout << endl << endl;

	int num = 1;
	cout << "for loop output: " << endl;
	for (num = 1; num <= 10; num++) {
		cout << setw(4) << num;
	}

	cout << setw(4) << num;
	cout << endl << endl;
	number = 1;

	cout << "Do_while loop output: " << endl;
	do{
		cout << setw(4) << number;
		number++;
	} while (number <= 10);

	cout << endl << endl;

	//system("pause");
}



