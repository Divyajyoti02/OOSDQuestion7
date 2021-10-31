#include<iostream>
#include<algorithm>
#include<vector>
#include "Order.h"
#include "Date.h"
#include "OrderList.h"
using namespace std;


void OrderList::addOrder(Order* order) {oList.push_back(order);}

void OrderList::deleteOrder(Order* order) {
	vector<Order*>::iterator o = find(oList.begin(), oList.end(), order);
	delete *o;
	oList.erase(o);
}

void OrderList::viewOrders() {
	unsigned int id = 1;
	cout << "S.No.\tOrder ID\tCustomer ID\tDate\tStatus" << endl;
	for (auto* o : oList) {cout << id++ << "\t" << o << "\t" << o->customer << "\t" << o->date << "\t" << o->status << endl;}
}

void OrderList::viewPerCustomer(Customer* cust) {
	unsigned int id = 1;
	cout << "S.No.\tOrder ID\tCustomer ID\tDate\tStatus" << endl;
	for (auto* o : oList)
		if (o->customer == cust)
			cout << id++ << "\t" << o << "\t" << o->customer << "\t" << o->date << "\t" << o->status << endl;
}

void OrderList::processOrder() {
	viewOrders();
	cout << "Select entry to process:" << endl;
	cin >> choice;
	if (choice > oList.size())
		throw invalid_argument("Invalid choice!\n");
	oList[choice - 1]->process();
	cout << "Processed" << endl;
}
