//Michael Olaoye

/*The program below uses a switch statement to select 
the arithmetic operation(addition, multiplication, or subtraction) 
to be performed on two numbers, depending on the value of 
the variable op_code.*/


#include <iostream>
#include <iomanip>
using namespace std;


int main(void)
{
    int op_code = 0;                   //stores desired mathematical operation code 
    double num1 = 0.0, num2 = 0.0;    //stores values entered by user
    double answer = 0.0;               //stores calculated answer from operation 

    cout << "***********************************************************" << endl;
    cout << "*   This program prompts the user for two values and      *" << endl
        << "*   displays a menu of different mathematical operations  *" << endl
        << "*   for the user to choose from to be performed on the    *" << endl
        << "*   two values.                                           *" << endl
        << "***********************************************************" << endl;

    //Prompt user to enter two values to be operated on   
    cout << "\n\nPlease enter the first value to be operated on (only numbers from 1 to 100): ";
    cin >> num1;

    //Check for number input within the range of 1 to 100
    if (num1 >= 0 && num1 <= 100)
    {

        cout << "Now, enter the second value (only numbers from 1 to 100): ";
        cin >> num2;

        //Check if number is out of range
        if (num2 < 0 || num2 > 100)
        {
            cout << "\n\nIncorret number entered. Please run program again." << endl;
            return 0;
        }

        //Builds a menu for user to choose desired operation on values 
        cout << "\n\nSelect the number code from the menu for the operation to be"
            << " performed on these values: ";
        cout << "\n\n                1 for addition" << endl;
        cout << "\n                2 for multiplication" << endl;
        cout << "\n                3 for subtraction" << endl;
        cout << "\nChoice:? ";
        cin >> op_code;             //stores desired math operation code

      //Determine desired math operation depending on user's choice 
        switch (op_code)         //compares code entered by user to each case
        {
        case 1:              //addition operation is performed if user entered 1
            answer = num1 + num2;
            cout << "\n\nThe sum of " << num1 << " and " << num2 << " is " << answer;
            break;
        case 2:             //multiplication operation is performed if user entered 2
            answer = num1 * num2;
            cout << "\n\nThe product of " << num1 << " and " << num2 << " is " << answer;
            break;
        case 3:         //subtraction operation is performed if user entered 3
            answer = num1 - num2;
            cout << "\n\nThe difference of " << num1 << " and " << num2 << " is " << answer;
            break;
        default:
            cout << "\n\nIncorrect code entered. Program will terminate." << endl;
        }                           //end of switch      	
    }
    return 0;
}
