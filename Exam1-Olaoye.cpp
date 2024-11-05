/****************************************************************

 Name: Michael Olaoye
 
 Purpose: A program that creates an invoice for an artist's customers 
 by calculating the handling fee, shipping charge and total processing 
 charges based on the volume of the shape selected by the user 

 *****************************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

// Symbolic constants
const double PI = 3.1416;
const double HANDLE_FEE_1 = 5.55, SHIP_FEE_1 = 0.10,
			 HANDLE_FEE_2 = 7.75, SHIP_FEE_2 = 0.23,
			 HANDLE_FEE_3 = 9.50, SHIP_FEE_3 = 0.28,
			 HANDLE_FEE_4 = 11.25, SHIP_FEE_4 = 0.32;

int main(void) 
{
	//VARIABLES NEEDED
	
	// Variable for Cube Volume
	double sideOfCubeLength = 0;
	//Variables for Torus Volume
	double minorRadiusOfTorus = 0, majorRadiusOfTorus = 0; 
	//Variables for Ellipsoid Volume
	double aAxisRadiusEllipsoid = 0, bAxisRadiusEllipsoid = 0, cAxisRadiusEllipsoid = 0; 
	// Output variables
	double volume = 0, handlingCharge = 0, shippingCharge = 0, totalProcessingCharge = 0; 
	//menu selector number
	int decisionFromMenu = 0;
	//other customer information
	string customerName, selectedObjectName;

	
	//INPUT
	//Display Menu before prompt
	cout << "Please enter your choice of shape from the following menu: \n"
		 << "1. Cube\n"
		 << "2. Torus\n"
		 << "3. Ellipsoid\n"
		 << "4. Quit\n";

	//Prompt user for menu selection and customer name
	cout << "\nEnter Menu Choice: ";
	cin >> decisionFromMenu;
	cin.ignore();


	//Switch the menu selection to get more specific user input
	switch (decisionFromMenu)
	{
		case 1: //Cube
			//Get customer name
			cout << "Enter the Name of the Customer: ";
			getline(cin, customerName);
			cout << endl;

			//Prompt user for side length of the cube
			cout << "Enter the Side measurement of the cube: ";
			cin >> sideOfCubeLength;
			selectedObjectName = "Cube";
			break;

		case 2: //Torus
			//Get customer name
			cout << "Enter the Name of the Customer: ";
			getline(cin, customerName);
			cout << endl;

			//Prompt user for torus' inner and outer radius
			cout << "Enter the Major Radius (R) measurement of the Torus: ";
			cin >> majorRadiusOfTorus;
			cout << "Enter the Minor Radius (r) measurement of the Torus: ";
			cin >> minorRadiusOfTorus;
			selectedObjectName = "Torus";
			break;

		case 3: //Ellipsoid
			//Get customer name
			cout << "Enter the Name of the Customer: ";
			getline(cin, customerName);
			cout << endl;

			//Prompt user for ellipsoid's a, b, c axes
			cout << "Enter the a-axis radius: ";
			cin >> aAxisRadiusEllipsoid;
			cout << "Enter the b-axis radius: ";
			cin >> bAxisRadiusEllipsoid;
			cout << "Enter the c-axis radius: ";
			cin >> cAxisRadiusEllipsoid;
			selectedObjectName = "Ellipsoid";
			break;

		case 4: //Quit
			//Display quit message to user and terminate program
			cout << "Thanks for using this program!!!\n";
			return 0;
			break;

		default:
			//Display error message to user and terminate program
			cout << "Invalid menu choice, Run program again.\n";
			return 0;
			break;
	}


	//PROCESS
	switch (decisionFromMenu)
	{
		case 1: //Cube
			//Calculate the volume of cube: S ^ 3
			volume = pow(sideOfCubeLength, 3);
			break;

		case 2: //Torus
			//Calculate the volume of torus: 0.25 * (PI ^ 2) * (r + R) * ((R - r) ^ 2)
			volume = 0.25 * pow(PI, 2) 
						  * (minorRadiusOfTorus + majorRadiusOfTorus) 
					      * pow((majorRadiusOfTorus - minorRadiusOfTorus), 2);
			break;

		case 3: //Ellipsoid
			//Calculate the volume of ellipsoid
			volume = (double(4) / 3) * PI
									 * aAxisRadiusEllipsoid 
									 * bAxisRadiusEllipsoid 
									 * cAxisRadiusEllipsoid;
			break;

		default:
			//Display error message to user and terminate program
			cout << "Something wrong happened – Please run the program again.\n";
			return 0;
			break;
	}

	//Calculate handling and shipping according to the volume
	if(volume > 0 && volume <= 50)
	{
		handlingCharge = HANDLE_FEE_1;
		shippingCharge = volume * SHIP_FEE_1;
	}
	else if (volume > 50 && volume <= 100) 
	{
		handlingCharge = HANDLE_FEE_2;
		shippingCharge = (volume - 50) * SHIP_FEE_2;
	}
	else if (volume > 100 && volume <= 150) 
	{
		handlingCharge = HANDLE_FEE_3;
		shippingCharge = (volume - 100) * SHIP_FEE_3;
	}
	else if (volume > 150) 
	{
		handlingCharge = HANDLE_FEE_4;
		shippingCharge = (volume - 150) * SHIP_FEE_4;
	}

	//Calculate the total processing charge
	totalProcessingCharge = handlingCharge + shippingCharge;


	//OUTPUT
	cout << endl;
	cout << "Shipping Invoice for " << customerName << "\n\n"
		 << "Dimensions of the " << selectedObjectName << ": \n";

	//Output variables based on selected object 
	cout << setprecision(1) << fixed << showpoint; // Format output to 1 decimal place
	switch (decisionFromMenu)
	{
		case 1: //Cube
			cout << "Side: " << sideOfCubeLength << " feet\n";
			break;
		case 2: //Torus
			cout << "Major radius (R): " << majorRadiusOfTorus << " feet\n";
			cout << "Minor radius (r): " << minorRadiusOfTorus << " feet\n";
			break;
		case 3: //Ellipsoid
			cout << "A-axis Radius: " << aAxisRadiusEllipsoid << " feet\n";
			cout << "B-axis Radius: " << bAxisRadiusEllipsoid << " feet\n";
			cout << "C-axis Radius: " << cAxisRadiusEllipsoid << " feet\n";
			break;
		default:
			//Display error message to user and terminate program
			cout << "Something wrong happened – Please run the program again.\n";
			return 0;
			break;
	}
	cout << "\nVolume: " << volume << " cubic feet"; // Display volume

	cout << setprecision(2) << fixed << showpoint << endl << endl; // Format output to 2 decimal places
	// Display charges and total
	cout << "Handling fee......................$" << handlingCharge << endl;
	cout << "Shipping Charge...................$" << shippingCharge << endl;
	cout << "Total Processing Charge...................$" << totalProcessingCharge << endl;

	// End program
	return 0;
}