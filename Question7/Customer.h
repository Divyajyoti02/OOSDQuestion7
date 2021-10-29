#include<string>
using namespace std;

class Customer {
	protected:
		unsigned int choice;
	
	
	public:
		string address[3];
		string phone;
		
		Customer(string Address[3], string Phone);
		
		virtual void update() = 0;
};
