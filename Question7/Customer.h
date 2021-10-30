#include<string>
#include<functional>
#include<vector>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Order;

class Customer {
	protected:
		vector<const Order*> orderLst;
		unsigned int choice;
	
	public:
		string address[3];
		string phone;
		
		Customer(string Address[3], string Phone);
		virtual void update() = 0;
		void addOrder(int DD, int MM, int YY);
};

#endif
