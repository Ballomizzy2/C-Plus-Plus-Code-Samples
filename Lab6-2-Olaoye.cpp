//Michael Olaoye
// Program that calculates the occupancy rate of an hotel

#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {

	//VARIABLES
	int noOfFloors, currentAmountOfRooms, currentFloorRoomsOccupied, currentFloorEmptyRooms, 
		totalRoomsOccupied = 0, totalEmptyRooms = 0, totalRooms = 0;
	double occupancyRate;

	//INPUT
	do {
		cout << "How many rooms floors does the hotel have? ";
		cin >> noOfFloors;
	
		if (noOfFloors <= 0)
			cout << "\nPlease enter a number greater than 0.\n";
	
	} while (noOfFloors <= 0);

	for (int i = 0; i < noOfFloors; i++) {
		do {
			cout << "\nHow many rooms are on floor " << i + 1 << " ? ";
			cin >> currentAmountOfRooms;
		
			if (currentAmountOfRooms <= 0)
				cout << "\nAmount of rooms should be greater than 0.\n";
			else {
				do {
					cout << "How many of those rooms are occupied? ";
					cin >> currentFloorRoomsOccupied;

					if (currentFloorRoomsOccupied <= 0) {
						cout << "\nPlease enter a positive number.\n";
					}
				} while (currentFloorRoomsOccupied <= 0);
				totalRoomsOccupied += currentFloorRoomsOccupied;
			}
		} while (currentAmountOfRooms <= 0);

		currentFloorEmptyRooms = currentAmountOfRooms - currentFloorRoomsOccupied;
		totalEmptyRooms += currentFloorEmptyRooms;
	}

	//PROCESS
	totalRooms = totalEmptyRooms + totalRoomsOccupied;
	occupancyRate = ((double)totalRoomsOccupied / totalRooms) * (double)100;

	//OUTPUT
	cout << "\nThe hotel has a total of " << totalRooms << " rooms.\n"
		<< totalRoomsOccupied << " are occupied.\n"
		<< totalEmptyRooms << " are empty.\n"
		<< "The occupancy rate is " << setprecision(1) << fixed << showpoint << occupancyRate << "%\n";

	return 0;
}