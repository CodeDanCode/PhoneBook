/**********************************************call_stats7.cpp************************************************************

Name: Daniel Leach                    
Course: Foundations of Computer Science (COP3014)
Assignment #:  11  call_stats8.cpp

Description: This program shows function overloading, dynamic arrays and the use of classes. This program also uses the copy class constructor.

*************************************************************************************************************************/


#include "call_class.h"

// main function
int main() {

	call_class MyClass;
	string key = " ";
	int userInput;
	bool run = true;
	
	cout << "Welcome to call calcultor " << endl;


	//menu loop
	while (run) {

		cout << endl;
		cout << "Please enter a number: " << endl;
		cout << endl;
		cout << "1) Display current database: " << endl;
		cout << "2) Search database: " << endl;
		cout << "3) Add to database: " << endl;
		cout << "4) delete from database: " << endl;
		cout << "5) Quit: " << endl;;
		cin >> userInput;

		system("CLS");

		switch (userInput) {
		case 1: cout << endl;			//shows current database
			cout << MyClass;
			break;

		case 2:cout << "please enter phone number of the person you want to search for: ";   //allows user to search records
			cin >> key;
			if (MyClass.search(key) == -1) {
				cout << " person not found" << endl;
			}
			else {
				MyClass.personSearch(key);  // search record function
			}

			break;

		case 3:
			MyClass.add();   // allows user to add to the record
			cout << MyClass;			  // shows new database after addition
			break;

		case 4:cout << "Please enter phone number of person you want to delete: " << endl;   // allows user to delete from the database
			cout << endl;
			cout << MyClass;      //shows current database
			cout << endl;
			cout << "ENTER PHONE NUMBER: ";   // user input
			cin >> key;
			cout << endl;
			MyClass.personSearch(key); // shows record to be deleted from database
			cout << endl;
			MyClass - key;         // deletes record from database
			cout << MyClass;               //show new list of records
			break;

		case 5: run = false;             //closes menu and quits program
			break;
		default:
			cout << "you enter a wrong number: ";        // checks for user error
		}


	}

	///////////////////////////////////////////////////////////////////

	call_class CopyClass = MyClass; // calls the copy constructor.
	CopyClass.outFile();

	//////////////////////////////////////////////////////////////////


	MyClass.~call_class();

	return 0;
}


