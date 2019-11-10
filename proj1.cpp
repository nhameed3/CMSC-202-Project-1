/*Title: proj1.cpp 
Author: Nauman Hameed
Date: 9/27/16
Section: 17
Description: Simulates the interface that a user might have for an atm
*/
#include "proj1.h" //pre and post conditions for each function in header file "proj1.h"
int main()
{
  int myStartChoice, choiceMain = 0, age;
  float accountBalance;
  string fName, lName, inputFile, save;
  ifstream inStream;
  ofstream outStream;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  myStartChoice = menuStart();
  while(myStartChoice > 0)
    {
      switch(myStartChoice) 
	{
	case 1: //Loads a user profile
	  inStream.open("proj1.txt");
	  inStream >> fName >> lName >> age >> accountBalance;
	  choiceMain = menuMain();
	  myStartChoice = -1;
	  break;
	case 2: //Prompts user and creates a new profile
	  cout << "Please enter the following" << endl;
	  cout << "First Name: " << endl;
	  cin >> fName;
	  cout << "Last Name: " << endl;
	  cin >> lName;
	  cout << "Age: " << endl;
	  cin >> age;
	  cout << "Initial Deposit: " << endl;
	  cin >> accountBalance;
	  cout << "$" << accountBalance << "deposited" << endl;
	  choiceMain = menuMain();
	  myStartChoice = -1;
	  break;
	case 3: //Breaks out of loop 
	  myStartChoice = -1;
	  break;
	}
    }
  while(choiceMain > 0)
    {
      switch(choiceMain)
	{
	case 1:
	  displayBalance(accountBalance);
	  choiceMain = menuMain();
	  break;
	case 2:
	  deposit(accountBalance);
	  choiceMain = menuMain();
	  break;
	case 3:
	  withdraw(accountBalance);
	  choiceMain = menuMain();
	  break;
	case 4:
	  displayAccountDetails(fName,lName,age,accountBalance);
	  choiceMain = menuMain();
	  break;
	case 5: //Updates proj1.txt if save == yes, and breaks out of loop
          cout << "Would you like to save your account information?: /nyes or no" << endl;
          cin >> save;
          if(save == "yes" || save == "YES" )
            {
              outStream.open("proj1.txt");
              outStream << fName <<" "<<  lName <<" "<< age <<" "<< accountBalance << endl;
              cout << "File Saved" << endl;
            }
          else
            {choiceMain = -1;}
	  choiceMain = -1;
	  break;
	}
    }
  cout << "Thanks for using the UMBC ATM" << endl;
  return 0;
}
int menuStart()  //Displays Start menu
{
  int Start;
  cout << "Welcome to the UMBC atm!" << endl;
  cout << "Choice from below: " << endl;
  cout << "1.) Load User Profile from a file" << endl;
  cout << "2.) Enter a new user profile" << endl;
  cout << "3.) Exit" << endl;
  cout << "Enter your choice: ";
  cin >> Start;
  return Start;
}
int menuMain()  //Displays Main menu
{
  int mainMenu;
  cout << "********Please choice an option from this menu**********" << endl;
  cout << "1.) Account Balance" << endl;
  cout << "2.) Deposit Money" << endl;
  cout << "3.) Withdraw Money" << endl;
  cout << "4.) Display your account details" << endl;
  cout << "5.) Exit" << endl;
  cout << "Enter your choice: ";
  cin >> mainMenu;
  return mainMenu;
}
void displayBalance(float accountBalance)
{
  cout << "Account Balance: $" << accountBalance << endl;
}
void deposit(float &accountBalance)
{
  float depositAmount;
  cout << "Please enter the amount to be deposited" << endl;
  cin >> depositAmount;
  if(depositAmount>0)  //Checks for valid input
    {
    accountBalance += depositAmount;
  cout << "$" << depositAmount << "deposited to your account" << endl;
    }
  else 
    {cout << "Amount should be greater than 0" << endl;}
}
void withdraw(float &accountBalance)
{
  float withdrawAmount;
  cout << "Please enter the amount to be withdrawn" << endl;
  cin >> withdrawAmount;
  if(withdrawAmount>0 && withdrawAmount<accountBalance)  //Checks for valid input
    {
     accountBalance -= withdrawAmount;
     cout << "$" << withdrawAmount << "withdrawn from your account." << endl;
    }
  else
    { cout << "Amount can not be less than 0 or greater than account balance" << endl;}
}
void displayAccountDetails(string fName, string lName, int age, float accountBalance)
{
  cout << "First Name : " << fName << endl;
  cout << "Last Name : " << lName << endl;
  cout << "Age : " << age << endl;
  cout << "Account Balance: $" << accountBalance << endl;
}
