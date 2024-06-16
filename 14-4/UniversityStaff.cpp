#include "UniversityStaff.h"
#include <iostream>
using namespace std;
UniversityStaff::UniversityStaff():name("none"){}/*constructor*/
UniversityStaff::UniversityStaff(string theName) :name(theName){}/*constructor*/
UniversityStaff::UniversityStaff(const UniversityStaff& theObject) {/*constructor*/
	name = theObject.getName();
}
string UniversityStaff::getName() const {/*accessor*/
	return name;
}
UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtside) {/*oprator overloading=*/
	name = rtside.name;
	return *this;
}
istream& operator >>(istream& input, UniversityStaff& s){/*oprator overloading>>*/
	cout << "Enter the proctor's name>>";
	input >> s.name;
	return input;
}
ostream& operator <<(ostream& output, UniversityStaff& s){/*oprator overloading<<*/
	output << "The proctor's name is " << s.name;
	return output;
}