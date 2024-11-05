#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;
void getNoCircles(int* no_circles_ptr);
//These are arrays
void setData(int* x, int* y, int no_circles); 
void displayCircles(int* x, int* y, int no_circles);




int main()
{
	//Variable Declaration/Initialization
	int no_circles = 0;
	const int MAX_CIRCLES = 50;
	int x[MAX_CIRCLES] = { 0 };
	int y[MAX_CIRCLES] = { 0 };



	//Display graphics
	displayGraphics();

	//Prompt for the no_circles - alternative to pass-by-ref
	getNoCircles(&no_circles);

	//Set data for circles
	setData(x, y, no_circles);

	//Display circles
	displayCircles(x, y, no_circles);
}

void getNoCircles(int* no_circles_ptr)
//Add Header for each function

{
	//Prompt for the # of circles (must be > 0 and < 10)
	do
	{
		cout << "Enter # of circles (> 0 but < 10): ";
		//Prompt for the no_circles using pointer notation
		if ((*no_circles_ptr < 0) || (*no_circles_ptr > 10))
			cout << "Enter # of circles (> 0 but < 10): ";
		else
			cin >> *no_circles_ptr;

	} while ((*no_circles_ptr < 0) || (*no_circles_ptr > 10));
}


void setData(int* x, int* y, int no_circles)
{
	//Variable Declaration/Initialization
	int i = 0;

	//Initialize random gen seed
	srand(time(0));

	//Generate random x/y values
	for (i = 0; i < no_circles; i++)
	{
		x[i] = rand() % 640;
		y[i] = rand() % 480;
	}
}

void displayCircles(int* x, int* y, int no_circles)
{
	//Variable Declaration/initialization
	int i = 0;

	//Display each circle
	for (i = 0; i < no_circles; i++)
	{
		drawCircle(10, x[i], y[i]);
	}
}




// A pointer is a variable that holds an address
