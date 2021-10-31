#include<iostream>
#include<string>
#include<vector>
#include<climits>
#include "Order.h"
#include "CustomerList.h"
#include "OrderList.h"
using namespace std;

CustomerList cl;
OrderList ol;

void viewCustomers();
void createCompany();
void updateCompany();
void deleteCompany();
void createPerson();
void updatePerson();
void deletePerson();

void placeOrder();
void viewOrders();
void viewPerCustomer();
void processOrder();
void deleteOrder();

void play();
int main();

void play() {
	bool exe = true;
	unsigned int choice;

	while(exe) {
		cout << endl << endl;
		cout << "========================================" << endl;
		cout << "========================================" << endl;
		cout << "Select operation:" << endl << endl;
		
		cout << "Customer related:" << endl;
		cout << "1 - View customers" << endl;
		cout << "2 - Create company" << endl;
		cout << "3 - Update company" << endl;
		cout << "4 - Delete company" << endl;
		cout << "5 - Create person" << endl;
		cout << "6 - Update person" << endl;
		cout << "7 - Delete person" << endl << endl;
		
		cout << "Order related:" << endl;
		cout << "8 - Place order" << endl;
		cout << "9 - View all orders" << endl;
		cout << "10 - View orders of a customer" << endl;
		cout << "11 - Process order" << endl;
		cout << "12 - Delete order" << endl << endl;
		
		cout << "99 - Exit" << endl << endl << endl;
		
		cin >> choice;
		try {
			switch(choice) {
				case 1:
					viewCustomers();
					break;
				case 2:
					createCompany();
					break;
				case 3:
					updateCompany();
					break;
				case 4:
					deleteCompany();
					break;
				case 5:
					createPerson();
					break;
				case 6:
					updatePerson();
					break;
				case 7:
					deletePerson();
					break;
					
				case 8:
					placeOrder();
					break;
				case 9:
					viewOrders();
					break;
				case 10:
					viewPerCustomer();
					break;
				case 11:
					processOrder();
					break;
				case 12:
					deleteOrder();
					break;
					
				case 99:
					exe = false;
					break;
					
				default:
					throw invalid_argument("Invalid choice!\n");
			}
		} catch (invalid_argument& ia) {
			cout << ia.what() << endl;
			cout << "Invalid operation!" << endl;
		}
	}
}

int main() {
	play();
	return 0;
}

void viewCustomers() {cl.view();}
void createCompany() {cl.createCompany();}
void updateCompany() {cl.updateCompany();}
void deleteCompany() {cl.deleteCompany(ol);}
void createPerson() {cl.createPerson();}
void updatePerson() {cl.updatePerson();}
void deletePerson() {cl.deletePerson(ol);}

void placeOrder() {cl.placeOrder(ol);}
void viewOrders() {ol.viewOrders();}
void viewPerCustomer() {cl.viewPerCustomer(ol);}
void processOrder() {ol.processOrder();}
void deleteOrder() {cl.deleteOrder(ol);}
