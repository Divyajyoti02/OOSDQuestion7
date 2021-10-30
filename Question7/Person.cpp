#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include "Person.h"



Person::Person(string FirstName, string LastName, string Address[3], string Phone) : Customer(Address, Phone), firstname(FirstName), lastname(LastName) {}
		
void Person::update() {
	cout << "What to update?" << endl;
	cout << "1 - firstname" << endl;
	cout << "2 - lastname" << endl;
	cout << "3 - address" << endl;
	cout << "4 - phone" << endl;
	cin >> choice;
			
	switch(choice) {
		case 1:
			cout << "Enter new first name: ";
			cin >> firstname;
			break;
		case 2:
			cout << "Enter new last name: ";
			cin >> lastname;
			break;
		case 3:
			cout << "Enter new address:" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < 3; i++) {
				cout << "Address line " << i + 1 << ": ";
				getline(cin, address[i]);
			}
			break;
		case 4:
			cout << "Enter new phone: ";
			cin >> phone;
			break;
		default:
			throw invalid_argument("Invalid choice!\n");
	}
}
