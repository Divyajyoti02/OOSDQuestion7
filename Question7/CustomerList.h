#include<string>
#include "Company.h"
#include "Person.h"
using namespace std;

#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

class CustomerList {
	private:
		unsigned int choice;
		vector<Company> cList;
		vector<Person> pList;
		string dString;
		
		void viewCompanies();
		void viewPersons();
		
	public:
		void createCompany();
		void deleteCompany();
		void updateCompany();
		void createPerson();
		void deletePerson();
		void updatePerson();
		void placeOrder();
		void view();
};

#endif
