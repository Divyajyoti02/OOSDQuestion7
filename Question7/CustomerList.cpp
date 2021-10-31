#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include<regex>
#include "Customer.h"
#include "Company.h"
#include "Person.h"
#include "CustomerList.h"
#include "OrderList.h"
using namespace std;



void CustomerList::viewCompanies() {
	unsigned int id = 1;
	cout << "S.No.\tCustomerId\tName\tRegNo\tAddress1\tAddress2\tAddress3\tPhone\tOrders" << endl;
	for (auto* c : cList) {
		cout << id++ << "\t" << c << "\t" << c->name << "\t" << c->regno << "\t" << c->address[0] << "\t" << c->address[1] << "\t" << c->address[2] << "\t" << c->phone << "\t";
		for (auto o : c->orderLst) {cout << o << ',';}
		cout << endl;
	}
}
		
void CustomerList::viewPersons() {
	unsigned int id = 1;
	cout << "S.No.\tCustomerId\tFirstName\tLastName\tAddress1\tAddress2\tAddress3\tPhone\tOrders" << endl;
	for (auto* p : pList) {
		cout << id++ << "\t" << p << "\t" << p->firstname << "\t" << p->lastname << "\t" << p->address[0] << "\t" << p->address[1] << "\t" << p->address[2] << "\t" << p->phone << "\t";
		for (auto o : p->orderLst) {cout << o << ',';}
		cout << endl;
	}
}
				
void CustomerList::createCompany() {
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
		
	Company* c = new Company(name, regno, address, phone);
	cList.push_back(c);
}
		
void CustomerList::deleteCompany(OrderList& ol) {
	cout << "Select entry to delete:" << endl;
	viewCompanies();
	cin >> choice;
	if (choice > cList.size())
		throw invalid_argument("Invalid choice!\n");
	while (!(cList[choice - 1]->orderLst.empty())) {
		ol.deleteOrder(cList[choice - 1]->orderLst.back());
		cList[choice - 1]->orderLst.pop_back();
	}
	delete cList[choice - 1];
	cList.erase(cList.begin() + choice - 1);
}
		
void CustomerList::updateCompany() {
	cout << "Select entry to update:" << endl;
	viewCompanies();
	cin >> choice;
	if (choice > cList.size())
		throw invalid_argument("Invalid choice!\n");
	cList[choice - 1]->update();
}
		
void CustomerList::createPerson() {
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
		
	Person *p = new Person(firstname, lastname, address, phone);
	pList.push_back(p);
}
		
void CustomerList::deletePerson(OrderList& ol) {
	cout << "Select entry to delete:" << endl;
	viewPersons();
	cin >> choice;
	if (choice > pList.size())
		throw invalid_argument("Invalid choice!\n");
	while (!(pList[choice - 1]->orderLst.empty())) {
		ol.deleteOrder(pList[choice - 1]->orderLst.back());
		pList[choice - 1]->orderLst.pop_back();
	}
	delete pList[choice - 1];
	pList.erase(pList.begin() + choice - 1);
}
		
void CustomerList::updatePerson() {
	cout << "Select entry to update:" << endl;
	viewPersons();
	cin >> choice;
	if (choice > pList.size())
		throw invalid_argument("Invalid choice!\n");
	pList[choice - 1]->update();
}
		
void CustomerList::view() {
	cout << "Companies:" << endl;
	viewCompanies();
	cout << "Persons:" << endl;
	viewPersons();
}

void CustomerList::placeOrder(OrderList& ol) {
	regex matchExpr("[0-9][0-9]/[0-1][0-9]/[0-9][0-9]");
	view();
	cout << "Who wants to place an order?" << endl;
	cout << "1 - Company" << endl;
	cout << "2 - Person" << endl;
	cin >> choice;
	switch(choice) {
		case 1:
			cout << "Select entry to update:" << endl;
			cin >> choice;
			if (choice > cList.size())
				throw invalid_argument("Invalid choice!\n");
			cout << "Enter date in the form DD/MM/YY: ";
			cin >> dString;
			if (regex_match(dString, matchExpr)) {
				int dd = stoi(dString.substr(0, 2)), mm = stoi(dString.substr(3, 2)), yy = stoi(dString.substr(6, 2));
				cList[choice - 1]->addOrder(dd, mm, yy);
				ol.addOrder(cList[choice - 1]->orderLst.back());
			} else
				throw invalid_argument("Invalid string!\n");
			break;
		case 2:
			cout << "Select entry to update:" << endl;
			cin >> choice;
			if (choice > pList.size())
				throw invalid_argument("Invalid choice!\n");
			cout << "Enter date in the form DD/MM/YY: ";
			cin >> dString;
			if (regex_match(dString, matchExpr)) {
				int dd = stoi(dString.substr(0, 2)), mm = stoi(dString.substr(3, 2)), yy = stoi(dString.substr(6, 2));
				pList[choice - 1]->addOrder(dd, mm, yy);
				ol.addOrder(pList[choice - 1]->orderLst.back());
			} else
				throw invalid_argument("Invalid string!\n");
			break;
		default:
			throw invalid_argument("Invalid choice!\n");
	}
}

void CustomerList::viewPerCustomer(OrderList& ol) {
	view();
	cout << "Select type of customer" << endl;
	cout << "1 - Company" << endl;
	cout << "2 - Person" << endl;
	cin >> choice;
	switch(choice) {
		case 1:
			cout << "Select entry to view:" << endl;
			cin >> choice;
			if (choice > cList.size())
				throw invalid_argument("Invalid choice!\n");
			ol.viewPerCustomer(cList[choice - 1]);
			break;
		case 2:
			cout << "Select entry to view:" << endl;
			cin >> choice;
			if (choice > pList.size())
				throw invalid_argument("Invalid choice!\n");
			ol.viewPerCustomer(pList[choice - 1]);
			break;
		default:
			throw invalid_argument("Invalid choice!\n");
	}
}

void CustomerList::deleteOrder(OrderList& ol) {
	view();
	cout << "Select type of customer" << endl;
	cout << "1 - Company" << endl;
	cout << "2 - Person" << endl;
	cin >> choice;
	switch(choice) {
		case 1:
			cout << "Select customer:" << endl;
			cin >> choice;
			if (choice > cList.size())
				throw invalid_argument("Invalid choice!\n");
			ol.viewPerCustomer(cList[choice - 1]);
			cout << "Select entry to delete:" << endl;
			cin >> choice2;
			if (choice > cList[choice - 1]->orderLst.size())
				throw invalid_argument("Invalid choice!\n");
			ol.deleteOrder(cList[choice - 1]->orderLst[choice2 - 1]);
			cList[choice - 1]->orderLst.erase(cList[choice - 1]->orderLst.begin() + choice2 - 1);
			break;
		case 2:
			cout << "Select customer:" << endl;
			cin >> choice;
			if (choice > pList.size())
				throw invalid_argument("Invalid choice!\n");
			ol.viewPerCustomer(pList[choice - 1]);
			cout << "Select entry to delete:" << endl;
			cin >> choice2;
			if (choice > pList[choice - 1]->orderLst.size())
				throw invalid_argument("Invalid choice!\n");
			ol.deleteOrder(pList[choice - 1]->orderLst[choice2 - 1]);
			pList[choice - 1]->orderLst.erase(pList[choice - 1]->orderLst.begin() + choice2 - 1);
			break;
		default:
			throw invalid_argument("Invalid choice!\n");
	}
}
