/************************************************************************
*																		*
*	Program:	FlashCards.cpp											*
*																		*
*	Author:		Micheal James Davis										*
*																		*
*	Date:		Oct 3, 2019											    *
*																		*
*	Purpose: The program generates a number of flash cards by the       *
*	number entered by the user. Generates addition, subtraction,        *
*	multiplication, division, and remainder. Promts the users score     *
*	also if the user would like to quiz again with more promblems.		*
*																		*									*
*																		*
*************************************************************************/

/************************************************************************
*																		*
*	Function: Flash Cards												*
*																		*
*	Purpose: Quiz the user with randomly generated promblems			*
*																		*
*************************************************************************/


#include <iostream>
#include <string>
#include <cstdlib>		
#include <ctime>	

using namespace std;

int main() {

	srand(time(NULL));		// Allows the random numbers generated to be diffrent numbers each run of the program 
	
	int addnumber;			// Data types for the Add portion of the program
	int addnumber1;

	int subnumber;
	int subnumber1;			// Data types for the Subtraction portion of the program with the temp to make sure no negatives are placed into the answers 
	int temp;

	int mulnumber;
	int mulnumber1;			// Data types for the Multiplication portion of the program

	int divisor;			// Data types for the Division portion of the program
	int divans;

	
	int remnumber;			// Data types for the Remainder portion of the program
	int remnumber1;

	char choice;			// Data type for the choice the user makes to continue with another quiz
	int correct = 0;		// How many answers where correct inputed by the user 

	do {					// Loop where it allows the user to select if they would like to do another quiz

	cout << "How many promblems would you like to solve: " << endl;
	int prob_amount;													// Ask the user how many questions they would like to solve and inputs into the program
	cin >> prob_amount;

	enum Operation { ADD, SUB, MUL, DIV, REM };
	Operation prob_type = ADD;						// This part allows the variables ADD SUB MUL DIV REM to numbers in the program in conjuction to how many questions are asked to do 


		for (int i = 0; i < prob_amount; i++) {			// This for loop allows the system to keep looping in these problems until the certain number that was inputed by the user is reached

			switch (prob_type)		// This switch allows the program to switch between the previous operations of ADD SUB MUL DIV REM after each question
			{

			case ADD:		// First case where everything inside this case is done and then moves on to the next if input is above one and so on. 
			{

				addnumber = rand() % 100 + 1;
				addnumber1 = rand() % 100 + 1;			// Generates two random numbers for the promblem

				cout << addnumber << "+" << addnumber1 << endl;
				int addanswer;
				cin >> addanswer;

				int addcorrect = addnumber + addnumber1;

				if (addanswer == addcorrect) {
					cout << "Correct" << endl;		// Allows the program to see if the number inputed into the program is correct to the answer generated above with the two random numbers 
					correct++;						// Keeps tally by adding one to correct variable every time answer is correct for total later
				}
				else {
					cout << "Wrong" << endl;		// If two numbers dont match Wrong is outputed to the user 
				}

				prob_type = SUB;
										// Prob Type allows the next problem to switch 
				break;					// This breaks the loop if the certain number of promblems is reached 
			}
			case SUB:
			{
				subnumber = 1 + rand() % 100;
				subnumber1 = 1 + rand() % 100;				// Generates two random numbers for the promblem

				if (subnumber < subnumber1) {
					temp = subnumber;					// This if statement allows the program to switch the two random numbers to larger first if needed for a negative number isnt the answer
					subnumber = subnumber1;
					subnumber1 = temp;
				}

				cout << subnumber << "-" << subnumber1 << endl;
				int subanswer;
				cin >> subanswer;

				if (subanswer == subnumber - subnumber1) {
					cout << "Correct" << endl;
					correct++;
				}
				else {
					cout << "Wrong" << endl;
				}

				prob_type = MUL;	// Prob Type allows the next problem to switch 

				break;				
			}
			case MUL:
			{
				mulnumber = rand() % 15 + 1;
				mulnumber1 = rand() % 15 + 1;				// Generates two random numbers for the promblem keep the range of 1-15 to allow easy math for user

				cout << mulnumber << "*" << mulnumber1 << endl;
				int mulanswer;
				cin >> mulanswer;

				if (mulanswer == mulnumber * mulnumber1) {
					cout << "Correct" << endl;
					correct++;
				}
				else {
					cout << "Wrong" << endl;
				}

				prob_type = DIV;			// Prob Type allows the next problem to switch 

				break;
			}
			case DIV:
			{
				divisor = 1 + rand() % 15;			// Generates two random numbers for the promblem keep the range of 1-15 to allow easy math for user
				divans = 1 + rand() % 15;		

				int dividend = divisor * divans;		// To make sure the answer is a whole number this takes the two random numbers and times them by themselves to get the dividend

				cout << dividend << "/" << divisor << endl;
				int divanswer;
				cin >> divanswer;

				if (divanswer == dividend / divisor) {		// Then the dividend is divided by the divisor the get the answer to allow for whole numbers 
					cout << "Correct" << endl;			 
					correct++;
				}
				else {
					cout << "Wrong" << endl;
				}

				prob_type = REM;		// Prob Type allows the next problem to switch 

				break;
			}
			case REM:
			{
				remnumber = 1 + rand() % 100;
				remnumber1 = 1 + rand() % 100;		// Generates two random numbers for the promblem

				if (remnumber < remnumber1) {
					temp = remnumber;				// This if statement allows the program to switch the two random numbers to larger first if needed for a negative number isnt the answer
					remnumber = remnumber1;
					remnumber1 = temp;
				}

				cout << remnumber << "%" << remnumber1 << endl;
				int remanswer;
				cin >> remanswer;

				if (remanswer == remnumber % remnumber1) {
					cout << "Correct" << endl;
					correct++;
				}
				else {
					cout << "Wrong" << endl;
				}

				prob_type = ADD;	// Goes back to the orginal ADD to restart the loop 

				break;
			}
			}
				
		}
		
		int score = round(100.0 * correct / prob_amount);			// This calcuates the correct answers given into a whole number then inputed below for the grading process
		
		if (score == 100) 
			cout << "You scored a " << score << " Your score was Perfect!" << endl;
		else if (score >= 90)
			cout << "You scored a " << score << " Your score was Great!" << endl;
		else if (score >= 80)
			cout << "You scored a " << score << " Your score was Good!" << endl;			// These if statements allow the program to read what the score was the user got and 
		else if (score >= 70)																//	how well they did with a personal message
			cout << "You scored a " << score << " Your score was Average." << endl;
		else if (score >= 60)
			cout << "You scored a " << score << " Your score was Below Average." << endl;
		else if (score >= 0)
			cout << "You scored a " << score << " You Failed! " << endl;

		cout << "Would you like to quiz again? Y for yes or N for no." << endl;		// This output statement prompts the user to see if they would like to quiz again with Y or no with N to end the program
		cin >> choice;
	}
	while (choice == 'Y');		// If Y is chosen the loop continues and if no the program ends 

	system("pause");
	return 0;
}



