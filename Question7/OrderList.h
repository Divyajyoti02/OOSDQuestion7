#include<iostream>
#include<vector>
#include "Order.h"
using namespace std;

#ifndef ORDERLIST_H
#define ORDERLIST_H

class OrderList {
	private:
		unsigned int choice;
		vector<Order*> oList;
	
	public:
		void addOrder(Order* order);
		void deleteOrder(Order* order);
		void viewOrders();
		void viewPerCustomer(Customer* cust);
		void processOrder();
};

#endif
