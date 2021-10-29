#include<string>
#include "Customer.h"
using namespace std;

#ifndef COMPANY_H
#define COMPANY_H

class Company : public Customer {
	public:
		string name, regno;
		
		Company(string Name, string Regno, string Address[3], string Phone);
		void update();
};

#endif
