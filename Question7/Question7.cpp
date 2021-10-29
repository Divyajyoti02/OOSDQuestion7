#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include "Customer.h"
#include "Company.h"
using namespace std;



class Person : public Customer {	
	public:
		string firstname, lastname;
		
		Person(string FirstName, string LastName, string Address[3], string Phone) : Customer(Address, Phone), firstname(FirstName), lastname(LastName) {}
		
		void update() {
			cout << "What to update?" << endl;
			cout << "1 - firstname" << endl;
			cout << "2 - lastname" << endl;
			cout << "3 - address" << endl;
			cout << "4 - phone" << endl;
			cin >> choice;
			
			/*===================================================*/
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
					throw "Invalid choice!\n";
			}
			/*===================================================*/
		}
};


class CustomerList {
	private:
		unsigned int choice;
		vector<Company> cList;
		vector<Person> pList;
		
		void viewCompanies() {
			unsigned int idx = 1;
			cout << "S.No.\tName\tRegNo\tAddress1\tAddress2\tAddress3\tPhone" << endl;
			for (auto c : cList) {cout << idx++ << "\t" << c.name << "\t" << c.regno << "\t" << c.address[0] << "\t" << c.address[1] << "\t" << c.address[2] << "\t" << c.phone << endl;}
		}
		
		void viewPersons() {
			unsigned int idx = 1;
			cout << "S.No.\tFirstName\tLastName\tAddress1\tAddress2\tAddress3\tPhone" << endl;
			for (auto p : pList) {cout << idx++ << "\t" << p.firstname << "\t" << p.lastname << "\t" << p.address[0] << "\t" << p.address[1] << "\t" << p.address[2] << "\t" << p.phone << endl;}
		}
		
		
	public:
		void createCompany() {
			string name, regno, phone;
			string address[3];
			
			cout << "Enter new name: ";
			cin >> name;
			cout << "Enter new regno: ";
			cin >> regno;
			cout << "Enter new address:" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < 3; i++) {
				cout << "Address line " << i + 1 << ": ";
				getline(cin, address[i]);
			}
			cout << "Enter new phone: ";
			cin >> phone;
			
			cList.push_back(Company(name, regno, address, phone));
		}
		
		void deleteCompany() {
			cout << "Select entry to delete:" << endl;
			viewCompanies();
			cin >> choice;
			if (choice > cList.size())
				throw "Invalid choice!\n";
			cList.erase(cList.begin() + choice - 1);
		}
		
		void updateCompany() {
			cout << "Select entry to update:" << endl;
			viewCompanies();
			cin >> choice;
			if (choice > cList.size())
				throw "Invalid choice!\n";
			cList[choice - 1].update();
		}
		
		void createPerson() {
			string firstname, lastname, phone;
			string address[3];
			
			cout << "Enter new first name: ";
			cin >> firstname;
			cout << "Enter new last name: ";
			cin >> lastname;
			cout << "Enter new address:" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			for (int i = 0; i < 3; i++) {
				cout << "Address line " << i + 1 << ": ";
				getline(cin, address[i]);
			}
			cout << "Enter new phone: ";
			cin >> phone;
			
			pList.push_back(Person(firstname, lastname, address, phone));
		}
		
		void deletePerson() {
			cout << "Select entry to delete:" << endl;
			viewPersons();
			cin >> choice;
			if (choice > pList.size())
				throw "Invalid choice!\n";
			pList.erase(pList.begin() + choice - 1);
		}
		
		void updatePerson() {
			cout << "Select entry to update:" << endl;
			viewPersons();
			cin >> choice;
			if (choice > pList.size())
				throw "Invalid choice!\n";
			pList[choice - 1].update();
		}
		
		void view() {
			cout << "Companies:" << endl;
			viewCompanies();
			cout << "Persons:" << endl;
			viewPersons();
		}
};


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
