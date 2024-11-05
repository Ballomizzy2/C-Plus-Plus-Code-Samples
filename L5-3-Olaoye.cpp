// Michael Olaoye
// Program that calcculates the speed of sound through different media

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const float AIR = 331.5, CO2 = 258.0, HELIUM = 972.0, HYDROGEN = 1270.0;
int main(void) {
	float noOfSeconds;
	char mediumChoice;
	float mediumSpeedMultiplier = 1, newSpeed;
	string name;

	cout << "Enter the number of seconds: ";
	cin >> noOfSeconds;

	if(noOfSeconds < 0){
		cout << "\n******Seconds must be a greater than 0. *******\n"
			<< "Please run program again.\n";
		return 0;
	}

	cout << "Select one of the following gases: \n"
		<< "A. Air\n"
		<< "B. Carbon Dioxide\n"
		<< "C. Helium\n"
		<< "D. Hydrogen\n"
		<< "E. Quit\n\n"
		<< "Enter your choice: ";
	cin >> mediumChoice;

	switch (mediumChoice)
	{
	case 'A': case 'a':
		mediumSpeedMultiplier = AIR;
		name = "Air";
		break;
	case 'B': case 'b':
		mediumSpeedMultiplier = CO2;
		name = "Carbon Dioxide";
		break;
	case 'C': case 'c':
		mediumSpeedMultiplier = HELIUM;
		name = "Helium";
		break;
	case 'D': case 'd':
		mediumSpeedMultiplier = HYDROGEN;
		name = "Hydrogen";
		break;
	case 'E': case 'e':
		cout << "\nProgram terminated succesfully!";
		return 0;
		break;
	default:
		cout << "\n*****The valid choices are A, B, C, D, and E.*****\n"
			<< "Run the program again and select one of those.\n";
		break;
	}

	newSpeed = noOfSeconds * mediumSpeedMultiplier;

	cout << setprecision(1) << fixed << showpoint << endl;
	cout << "A sound wave travels " << newSpeed << " meters in " << noOfSeconds
		<< " seconds through " << name << ".\n";

	return 0;
}