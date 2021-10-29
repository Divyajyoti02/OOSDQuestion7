#include<string>
#include "Customer.h"
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person : public Customer {	
	public:
		string firstname, lastname;
		
		Person(string FirstName, string LastName, string Address[3], string Phone);
		void update();
};

#endif
