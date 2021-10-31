#include<iostream>
#include<functional>
#include<string>
#include<vector>
#include "Customer.h"
using namespace std;

#ifndef ORDER_H
#define ORDER_H

class Order {
	public:
		bool status;
		
		Customer* customer;
		
		class Date;
		Date* date;
		
		Order(Customer* cust, int dd, int mm, int yy);
		~Order();
		
		void process();
};

#endif
