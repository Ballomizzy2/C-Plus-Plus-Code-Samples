//Name: Michael Olaoye

#include <iostream>
#include <ctime>       //Header file for time functions
#include <cstdlib>     //Header file for random number generators

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int seed = 0;                             //Declaration for seed
	int rand_number = 0;                      //Declaration for random number
	int no_possibilities = 6;                 //Declaration for number of possibilites - Example for a dice

	//Set the seed to be the number of seconds since 1970
	seed = time(0);

	cout << endl << "SEED " << seed << endl << endl;

	//Initialize srand function with seed
	srand(seed);

	//Compute random number (normalized to desired # of possibilites)
	rand_number = rand() % no_possibilities + 1;

	//Compute random number 
	//rand_number = rand();

	//Display random number generated (5 cases)
	cout << "Random #1 generated: " << rand_number << endl;

	rand_number = rand() % no_possibilities + 1;
	cout << "Random #2 generated: " << rand_number << endl;

	rand_number = rand() % no_possibilities + 1;
	cout << "Random #3 generated: " << rand_number << endl;

	rand_number = rand() % no_possibilities + 1;
	cout << "Random #4 generated: " << rand_number << endl;

	rand_number = rand() % no_possibilities + 1;
	cout << "Random #5 generated: " << rand_number << endl;

	cout << endl << endl;

	return 0;
}

/*

//Variable Declaration/Initialization
  int seed = 0;                             //Declaration for seed
  int rand_number = 0;                      //Declaration for random number
  int no_possibilities = 6;                 //Declaration for number of possibilites - Example for a dice

  //Set the seed to be the number of seconds since 1970
  seed = time(0);

  //cout << endl << "SEED " << seed << endl << endl;

  //Initialize srand function with seed
  srand(seed);

  //Compute random number (normalized to desired # of possibilites)
  //rand_number = rand() % no_possibilities;


*/

