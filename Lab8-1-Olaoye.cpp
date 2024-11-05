// Michael Olaoye
// Program that calculates the charge for a buffet restaurant

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double ADULT_MEAL_PRICE = 6.0,
			 CHILD_MEAL_PRICE = 3.0,
			 DESSERT_PRICE = 1.0,
			 TAX = 0.065,
			 GRATUITY = 0.15;

void getCustomerDetails(string&, string&, int&, int&, int&);
void calculateCharges(double&, double&, double&, double&, double&, double&, double&, int, int, int);
void displayBill(string, string, double, double, double, double, double, double, double, int, int, int);

int main(void) {
	
	//VARIABLES
	string customerName, dateOfBill;
	int noOfAdultMeals, noOfChildMeals, noOfDesserts;

	double adultCharge, childCharge, dessertCharge, 
		   totalTax, subTotal, gratuityCharge, totalCharge;

	char decision;

	do {

		//INPUT
		cout << "Enter the following Customer's Information. \n";
		getCustomerDetails(dateOfBill, customerName, noOfAdultMeals, noOfChildMeals, noOfDesserts);

		//PROCESS
		calculateCharges(adultCharge, childCharge, dessertCharge, totalTax, subTotal, gratuityCharge, totalCharge, noOfAdultMeals, noOfChildMeals, noOfDesserts);
		
		//OUTPUT
		displayBill(dateOfBill, customerName, adultCharge, childCharge, dessertCharge, totalTax, subTotal, gratuityCharge, totalCharge, noOfAdultMeals, noOfChildMeals, noOfDesserts);

		cout << "Would you like to process another customer's bill? (Y or N): ";
		cin >> decision;
		cin.ignore();
	} while (decision == 'Y' || decision == 'y');

	return 0;
}

//Get the date of the bill
void getCustomerDetails(string& date, string& customerName, int& adultMeals, int& childMeals, int& desserts) {
	cout << "Date: ";
	getline(cin, date);

	//Get the name of the customer
	cout << "Customer Name: ";
	getline(cin, customerName);

	//Get the number of adult meals
	do {
		cout << "Number of Adult Meals: ";
		cin >> adultMeals;
	
		if (adultMeals < 0)
			cout << "ERROR! Please insert a positive integer!\n";
	} while (adultMeals < 0);

	//Get the number of children meals
	do {
		cout << "Number of Child Meals: ";
		cin >> childMeals;

		if (childMeals < 0)
			cout << "ERROR! Please insert a positive integer!\n";
	} while (childMeals < 0);

	//Get the number of desserts
	do {
		cout << "Number of Desserts: ";
		cin >> desserts;

		if (desserts < 0)
			cout << "ERROR! Please insert a positive integer!\n";
	} while (desserts < 0);
}
//Calculate the charges
void calculateCharges(double& adultMealCharge, double& childMealCharge, double& dessertCharge, double& totalTaxes, double& subTotal, double& gratuityCharge, double& totalCharge, int adultMealNo, int childMealNo, int noOfDessert) {
	double total;
	adultMealCharge = adultMealNo * ADULT_MEAL_PRICE;
	childMealCharge = childMealNo * CHILD_MEAL_PRICE;
	dessertCharge = noOfDessert * DESSERT_PRICE;
	total = adultMealCharge + childMealCharge + dessertCharge;
	totalTaxes = total * TAX;
	subTotal = total + totalTaxes;
	gratuityCharge = subTotal * GRATUITY;
	totalCharge = subTotal + gratuityCharge;
}
//Display the bill
void displayBill(string date, string name, double adultMealCharge, double childMealCharge, double dessertCharge, double totalTaxes, double subTotal, double gratuityCharge, double totalCharge, int adultMealNo, int childMealNo, int noOfDessert) {
	cout << endl;
	cout << "The All-You-Can-Eat Buffet Restaurant\n\n";
	cout << "Date: " << date << endl;
	cout << "Customer Name: " << name << endl << endl;

	cout << "Adult Meal Charge: " << adultMealNo << "@6.00 each" << "  $  " 
		 << setprecision(2) << fixed << showpoint << adultMealCharge << endl;

	cout << "Child Meal Charge: " << childMealNo << "@3.00 each" << "  $  "
		<< setprecision(2) << fixed << showpoint << childMealCharge << endl;

	cout << "Dessert Charge: " << noOfDessert << "   @1.00 each" << "  $  "
		<< setprecision(2) << fixed << showpoint << dessertCharge << endl;

	cout << "Taxes:                           $  "
		<< setprecision(2) << fixed << showpoint << totalTaxes << endl;

	cout << "\tSubtotal: " << setw(20) << "                          $  "
		<< setprecision(2) << fixed << showpoint << subTotal << endl << endl;

	cout << "Gratuity Charge: (15.00%)" << setw(20) << "  $  "
		<< setprecision(2) << fixed << showpoint << gratuityCharge << endl << endl;

	cout << "Total: " << setw(20) << "                                     $  "
		<< setprecision(2) << fixed << showpoint << totalCharge << endl;

	cout << "Thank you for eating at the All - You - Can - Eat Buffet Restaurant. \nPlease come again.\n\n";

}


