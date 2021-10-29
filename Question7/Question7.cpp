#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include "CustomerList.h"
#include "Date.h"
using namespace std;



void play() {
	bool exe = true;
	unsigned int choice;
	CustomerList cl = CustomerList();
	while(exe) {
		cout << "Select operation" << endl;
		cout << "1 - View" << endl;
		cout << "2 - Create company" << endl;
		cout << "3 - Update company" << endl;
		cout << "4 - Delete company" << endl;
		cout << "5 - Create person" << endl;
		cout << "6 - Update person" << endl;
		cout << "7 - Delete person" << endl;
		cout << "8 - Exit" << endl;
		cin >> choice;
		switch(choice) {
			case 1:
				cl.view();
				break;
			case 2:
				cl.createCompany();
				break;
			case 3:
				cl.updateCompany();
				break;
			case 4:
				cl.deleteCompany();
				break;
			case 5:
				cl.createPerson();
				break;
			case 6:
				cl.updatePerson();
				break;
			case 7:
				cl.deletePerson();
				break;
			case 8:
				exe = false;
				break;
			default:
				throw "Invalid choice!\n";
		}
	}
}

int main() {
	play();
	return 0;
}
