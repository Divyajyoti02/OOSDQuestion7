#include<iostream>
using namespace std;



enum Month{Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

class Date {
	public:
		unsigned int dd, yy;
		enum Month mm;
		
		Date(unsigned int DD, enum Month MM, unsigned int YY);
};

ostream& operator<<(ostream& out, const Date& date);
