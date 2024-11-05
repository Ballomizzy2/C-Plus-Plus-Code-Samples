// Michael Olaoye
// Program for Conway Regional patient billing system

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double TAX = 0.085;

void getPatientData(int&, string&, int&, double&, double&, double&);
void computeInPatientCharges(double&, int, double);
void computeAdditionalCharges(double&, double, double&, double);
double computeTotalBill(double, double);
void displayResults(int, string, int, double, double, double, double, double, double, double);

int main(void) {

	//VARIABLES
	int patientID, numberOfDaysInHospital;
	string patientName;
	double dailyRate, medicationCharges, laboratoryCharges,
		   inpatientCharge, additionalCharges, medicationTax,
		   totalBill;

	char decision;

	do {
	
		//INPUT
		getPatientData(patientID, patientName, numberOfDaysInHospital, dailyRate, medicationCharges, laboratoryCharges);

		//PROCESS
		computeInPatientCharges(inpatientCharge, numberOfDaysInHospital, dailyRate);
		computeAdditionalCharges(additionalCharges, medicationCharges, medicationTax, laboratoryCharges);
		totalBill = computeTotalBill(inpatientCharge, additionalCharges);

		//OUTPUT
		displayResults(patientID, patientName, numberOfDaysInHospital, dailyRate, inpatientCharge, medicationCharges, medicationTax, laboratoryCharges, additionalCharges, totalBill);
			
		cout << "Would you like to calculate another Patient bill? Y or N: ";
		cin >> decision;
		//cin.ignore();
	} while (decision == 'Y' || decision == 'y');
	return 0;
}

//Get User input/ patient details
void getPatientData(int& patientID, string& patientName, int& daysStayed, double& dailyRate, double& medCharges, double& labCharges) {
	do {
		cout << "Enter Patient ID: ";
		cin >> patientID;
		cin.ignore();
		if (patientID > 8000 || patientID < 2000)
			cout << "ERROR! Invalid patient ID. (Enter a number from 2000 to 8000, inclusive)\n";
	} while (patientID > 8000 || patientID < 2000);
	
	cout << "Enter Patient Name: ";
	getline(cin, patientName);

	do {
		cout << "Enter Days stayed in Hospital: ";
		cin >> daysStayed;
		if (daysStayed < 1)
			cout << "ERROR! Invalid patient ID. (Enter a number that is 1 or more)\n";
	} while (daysStayed < 1);

	do {
		cout << "Enter daily Inpatient Rate: ";
		cin >> dailyRate;
		if (!dailyRate > 0)
			cout << "ERROR! Invalid patient ID. (Enter a number that is greater than zero)\n";
	} while (!dailyRate > 0);

	cout << "Enter Medication Charges: ";
	cin >> medCharges;

	cout << "Enter Laboratory Charges: ";
	cin >> labCharges;
}
// Calculates the inpatient's charge
void computeInPatientCharges(double& inpatientCharge, int numberOfDaysInHospital, double dailyRate) {
	inpatientCharge = numberOfDaysInHospital * dailyRate;
}
//Calculates the additional charges for the inpatient
void computeAdditionalCharges(double& additionalCharges, double medCharges, double& medTax, double labCharges) {
	medTax = (medCharges * TAX);
	additionalCharges = medCharges +  medTax + labCharges;
}
//Calculates the total bill
double computeTotalBill(double inpatientCharges, double additionalCharges) {
	return inpatientCharges + additionalCharges;
}
//Display inpatient's bill
void displayResults(int patientID, string patientName, int daysInHospital, double dailyRate, double inpatientCharge, double medicationCharge, double medicationTax, double labCharge, double totalAdditionalCharges, double totalBill) {
	cout << "\nPatient ID:                   " << patientID << endl;
	cout << "Patient Name:                 " << patientName << endl;
	cout << "Length of Stay:(#of Days)     " << daysInHospital << " days" << endl;
	cout << "Daily Inpatient Rate:         " << "$ " << setprecision(2) << fixed << showpoint << dailyRate << endl;
	cout << "Total Inpatient Charges:      " << "$ " << setprecision(2) << fixed << showpoint << inpatientCharge << endl;
	cout << "\nAdditional Charges:\n";
	cout << " Medication:                  " << "$ " << setprecision(2) << fixed << showpoint << medicationCharge << endl;
	cout << "    Med Taxes:                " << "$ " << setprecision(2) << fixed << showpoint << medicationTax << endl;
	cout << " Laboratory:                  " << "$ " << setprecision(2) << fixed << showpoint << labCharge << endl;
	cout << "\nTotal Additional Charges:   " << "$ " << setprecision(2) << fixed << showpoint << totalAdditionalCharges << endl << endl;
	cout << "Total Bill:                   " << "$ " << setprecision(2) << fixed << showpoint << totalBill << endl << endl;
}