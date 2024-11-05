//Name: Michael Olaoye
// Program that manipulates the string enetered by a user, displaying the length etc.

#include<iostream>
#include<string>


using namespace std;  //introduces namespace std

// Function prototypes
string getString();
int getStringLength(string);
void getAmtOfWords(string, const int);
void displayTextBackwards(string, const int);

int main()
{
	string phrase;
	int lengthOfString = 0;
	bool repeat;


	do {

		// Function calls
		phrase = getString();
		lengthOfString = getStringLength(phrase);
		getAmtOfWords(phrase, lengthOfString);
		displayTextBackwards(phrase, lengthOfString);

		cout << endl << endl;

		cout << "Run program again ? ";
		cin >> repeat;
		cout << endl << endl;
		cin.ignore();

	} while (repeat == 1);

	cout << endl << endl;
	return 0;
}

// get the string from the user
string getString() {
	string phrase;
	cout << "Enter message: ";
	getline(cin, phrase);
	
	cout << "\nThe message you entered was:\n";
	cout << phrase << endl << endl;
	
	return phrase;
}

// calculate the length of the string
int getStringLength(string phrase)
{
	int length = 0;
	while (phrase[length] != NULL) {
		length++;
	}
	cout << "The length of the string entered is: " << length << endl;
	return length;
}

// Get the amount of words in the phrase
void getAmtOfWords(string phrase, const int phraseLength)
{
	int words = 0;
	if (phrase[0] && phrase[0] != ' ')
		words++;
	for (int i = 0; i < phraseLength; i++) {
		if (phrase[i] == ' ')
			words++;
	}

	cout << "Number of Words in message: " << words << endl << endl;
}

// Display the text backwards
void displayTextBackwards(string phrase, const int phraseLength) {
	cout << "The message displayed bacward is:\n";
	for (int i = 0; i < phraseLength + 1; i++) {
		cout << phrase[phraseLength - i];
	}
}

