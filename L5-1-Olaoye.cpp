//Michael Olaoye
//Displays weight on different planets


#include <iostream>
#include <iomanip>

using namespace std;

const float JUPITER = 2.65,
			MARS = 0.39,
			MERCURY = 0.38,
			NEPTUNE = 1.23,
			PLUTO = 0.05,
			SATURN = 1.17,
			URANUS = 1.05,
			VENUS = 0.78;

int main(void) {
	//Variables
	float earthWeight, planetGravity, newWeight;
	int planetNumber;
	string planetChosen;

	//Input
	cout << "This program converts your weight on Earth to your weight on the planet of your choice.\n\n" <<
		"Please enter your weight on planet Earth: ";
	cin >> earthWeight;

	cout << "\nPlease enter the number that follows your planet of choice.\n" <<
		"MERCURY: 1\n" <<
		"VENUS:   2\n" <<
		"MARS:    3\n" <<
		"JUPITER: 4\n" <<
		"SATURN:  5\n" <<
		"URANUS:  6\n" <<
		"NEPTUNE: 7\n" <<
		"PLUTO:   8\n\n" <<
		"Planet Number = ? ";
	cin >> planetNumber;

	//Process
	switch (planetNumber)
	{
	case 1:
		planetGravity = MERCURY;
		planetChosen = "Mercury";
		break;
	case 2:
		planetGravity = VENUS;
		planetChosen = "Venus";
		break;
	case 3:
		planetGravity = MARS;
		planetChosen = "Mars";
		break;
	case 4:
		planetGravity = JUPITER;
		planetChosen = "Jupiter";
		break;
	case 5:
		planetGravity = SATURN;
		planetChosen = "Saturn";
		break;
	case 6:
		planetGravity = URANUS;
		planetChosen = "Uranus";
		break;
	case 7:
		planetGravity = NEPTUNE;
		planetChosen = "Neptune";
		break;
	case 8:
		planetGravity = PLUTO;
		planetChosen = "Pluto";
		break;
	default:
		cout << "Invalid planet number entered, Try again!\n";
		return 0;
		break;
	}

	newWeight = earthWeight * planetGravity;

	//Output
	cout << setprecision(1) << fixed << showpoint << endl;
	cout << "Your weight on earth:                 " << earthWeight << " lbs.\n";
	cout << "Planet Chosen:                        " << planetChosen << endl;
	cout << "Your weight on the chosen planet:     " << newWeight << " lbs." << endl;

	return 0;
}