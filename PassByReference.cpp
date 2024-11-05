
//NAME: Michael Olaoye

//This program calculates the perimeter and area of a rectangle.
/*******************************************************
Input:
Length and width of rectangle

Process:
1. Calculate the area: length X width
2. Calculate perimeter: (2 X length) + (2 X width)
						OR length + length + width + width

Output:
Length, width, and calculated area and perimeter of a rectangle
*******************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
void getLengthWidth(int &, int &);
void calculateAreaPeri(int, int, int &, int &);
void displayRectangleInfo(int, int, int, int);

int main()
{
	//Variables needed 
	int length = 0, width = 0, area = 0, perimeter = 0;
	bool repeat;

	do
	{
		//Function Call Statements
		getLengthWidth(length, width);
		calculateAreaPeri(length, width, area, perimeter);
		displayRectangleInfo(length, width, perimeter, area);

		cout << "Run again (1 for YES, 0 for NO): ";
		cin >> repeat;
	} while (repeat);

	return 0;
}

//Function Definitions 

//Prompts and gets the length of the rectangle 
void getLengthWidth(int &leng, int &wid) //function header
{
	//function body;
	cout << "Enter the Length of the rectangle: ";
	cin >> leng;
	cout << "Enter the Width of the rectangle: ";
	cin >> wid;
}

//Calculates the area of the rectangle 
void calculateAreaPeri(int l, int w, int& area, int& perimeter) //function header
{
	//function body
	area = l * w;
	perimeter = l + l + w + w;


}

//Displays the dimensions and area of the rectangle  
void displayRectangleInfo(int length, int width, int perimeter, int area) //function header
{
	//function body
	cout << "\n\n\nThe dimensions of the rectangle are: " << endl;
	cout << "Length: " << length << endl;
	cout << "Width: " << width << endl;
	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;
	cout << endl << endl;
}

