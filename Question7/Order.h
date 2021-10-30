#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include "Customer.h"
using namespace std;

#ifndef ORDER_H
#define ORDER_H

class Order {
	private:
		const Customer* customer;
		
	public:
		bool status;
		
		class Date;
		
		Date* date;
		
		Order(const Customer* cust, int dd, int mm, int yy);
		
		void process();
};

#endif
