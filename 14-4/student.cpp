#include <iostream>
#include "student.h"
using namespace std;

student::student() :university("none"), regist(0){}/*constructor*/
student::student(string u, int r):university(u),regist(r){}/*constructor*/
void student::setName(string u) {/*mutator*/
	university = u;
}
void student::setNumber(int r) {/*mutator*/
	regist = r;
}
void student::setProctor() {/*mutator*/
	cin >> procter;
}
string student::getUniversityName() const {/*accessor*/
	return university;
}
int student::getRegistNum() const {/*accessor*/
	return regist;
}
string student::getProcterName() {/*accessor*/
	return procter.getName();
}