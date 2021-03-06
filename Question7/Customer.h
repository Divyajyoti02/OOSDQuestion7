#include<string>
#include<functional>
#include<vector>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Order;

class Customer {
	protected:
		unsigned int choice;
	
	public:
		string address[3];
		string phone;
		vector<Order*> orderLst;
		
		Customer(string Address[3], string Phone);
		virtual void update() = 0;
		void addOrder(int DD, int MM, int YY);
		void deleteOrder();
};

#endif
