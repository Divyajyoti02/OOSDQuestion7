#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include "Company.h"
using namespace std;



Company::Company(string Name, string Regno, string Address[3], string Phone) : Customer(Address, Phone), name(Name), regno(Regno) {}
		
void Company::update() {
	cout << "What to update?" << endl;
	cout << "1 - name" << endl;
	cout << "2 - regno" << endl;
	cout << "3 - address" << endl;
	cout << "4 - phone" << endl;
	cin >> choice;
			
	switch(choice) {
		case 1:
			cout << "Enter new name: ";
			cin >> name;
			break;
		case 2:
			cout << "Enter new regno: ";
			cin >> regno;
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
			throw "Invalid choice!\n";
	}
}
