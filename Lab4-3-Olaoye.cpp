// Michael Olaoye
// Program that calculates and displays software company customers' invoice

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const double PACKAGE_PRICE = 50.99,
			 SALES_TAX = 0.085;

int main(void) {
	//Input
	int quantityOfPackages;
	double discount, softwareCost, totalSales, salesTax, totalCost;
	string customerName;

	cout << "Please enter the Customer's Name : ";
	getline(cin, customerName);

	cout << "Please enter the total number of software package(s) purchased: ? ";
	cin >> quantityOfPackages;

	//Process
	if (quantityOfPackages >= 1 && quantityOfPackages <= 10) {
		discount = 0;
	}
	else if (quantityOfPackages >= 11 && quantityOfPackages <= 20) {
		discount = .2;
	}
	else if (quantityOfPackages >= 21 && quantityOfPackages <= 50) {
		discount = .3;
	}
	else if (quantityOfPackages >= 51 && quantityOfPackages <= 100) {
		discount = .4;
	}
	else if (quantityOfPackages >= 101) {
		discount = .5;
	}
	else {
		cout << "Error :/";
		return 0;
	}

	
	softwareCost = PACKAGE_PRICE * quantityOfPackages;
	totalSales = softwareCost - (softwareCost * discount);
	salesTax = SALES_TAX * totalSales;
	totalCost = totalSales + salesTax;
	

	//Output
	cout << "\n\nINVOICE for " << customerName << endl;
	cout << "Quantity: " << quantityOfPackages << endl;
	cout << setprecision(2) << fixed << showpoint;
	cout << "  Discount: " << discount * 100 << "%\n\n";

	cout << "Software Cost (" << quantityOfPackages << " packages at $50.99 each)..........$ " << softwareCost << endl;
	cout << "Discount...........................................$ " << discount << endl;
	cout << "                                                   --------\n";
	cout << "Total Sales........................................$ " << totalSales << endl;
	cout << "Sales Tax..........................................$ " << salesTax << endl;
	cout << "                                                   --------\n";
	cout << "Total Purchase.....................................$ " << totalCost << endl;
}