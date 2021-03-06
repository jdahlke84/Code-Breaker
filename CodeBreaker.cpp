// James Dahlke 
// The goal is to guess the correct digit based on the location to break the code.
// This is similar to the game Mastermind where you guess four colors hidden on a board.  
// ------------------------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;


// setting up the random number generator for each digit in the secret number. 
void setSecretNumber(int &num1, int &num2, int &num3, int &num4, int &num5) 
{
	num1 = 1 + rand() % 9;
	num2 = 1 + rand() % 9;
	num3 = 1 + rand() % 9;
	num4 = 1 + rand() % 9;
	num5 = 1 + rand() % 9;
}

int getChoice(const char *choiceName) 
{

	int choice = 0;
	while(choice == 0)
	{
		cout << "Please enter your " << choiceName << " choice out of a 5 digit number: "; 
		cin >> choice;
		if(choice < 1 || choice > 9) // if the choice is either less than 1 or greater than 9, it is an invalid entry. 
		{
			cout << "Invalid entry! Please try any number between 1 and 9.\n" << endl;
			choice = 0;
		}
	}

	return choice;
}

void getGuess(int &choice1, int &choice2, int &choice3, int &choice4, int &choice5)
{
	cout << "Welcome to a simple version of a Mastermind type game!\n"
		<< "1 implies that it's the right number in the right spot."
		<< "2 implies that it's the right number in the wrong spot."
		<< "0 implies that it's the incorrect number.\n\n"
		<< "1 - First Digit\n"
		<< "2 - Second Digit\n"
		<< "3 - Third Digit\n"
		<< "4 - Fourth Digit\n"
		<< "5 - Fifth Digit\n" << endl;
	choice1 = getChoice("first");
	choice2 = getChoice("second");
	choice3 = getChoice("third");
	choice4 = getChoice("fourth");
	choice5 = getChoice("fifth");
}


// This function prompts and reads the numbers the user guesses.
// Correct number and correct place = '1'
// Correct number and wrong place = '2'
// Wrong number = '0'
int getExactMatches(int &num1, int &num2, int &num3, int &num4, int &num5,  
		int &choice1, int &choice2, int &choice3, int &choice4, int &choice5)
{
	int counter=0;

	if(choice1 == num1)
		printf("1");
	else if(choice1 != num1)
		printf("0");
	else if(choice1 == num1)
		printf("2");

	if(choice2 == num2)
		printf("1");
	else if(choice2 != num2)
		printf("0");
	else if(choice2 == num2)
		printf("2");

	if(choice3 == num3)
		printf("1");
	else if(choice3 != num3)
		printf("0");
	else if(choice3 == num3)
		printf("2");

	if(choice4 == num4)
		printf("1");
	else if(choice4 != num4)
		printf("0");
	else if(choice4 == num4)
		printf("2");

	if(choice5 == num5)
		printf("1");
	else if(choice5 != num5)
		printf("0");
	else if(choice5 == num5)
		printf("2");

	return counter;
}

void showNums(int &num1, int &num2, int &num3, int &num4, int &num5) 
{
	cout << num1 << " - " << num2 << " - " << num3 << " - " << num4 << " - " << num5;
}

int main(void) 
{
	int num1, num2, num3, num4, num5, choice1, choice2, choice3, choice4, choice5;
	srand(static_cast<unsigned int>(time(0)));

	setSecretNumber(num1, num2, num3, num4, num5);
	getGuess(choice1, choice2, choice3, choice4, choice5);
	int exactMatch = getExactMatches(num1, num2, num3, num4, num5, choice1, choice2, choice3, choice4, choice5);
	
	cout << "\nAnswer: \n";
	showNums(num1, num2, num3, num4, num5);
	cout << endl;

	cout << "\nGuess: \n";
	showNums(choice1, choice2, choice3, choice4, choice5);
	cout << endl;

	system("pause");
	return 0;
}