#ifndef UNIVERSITYSTAFF_H
#define UNIVERSITYSTAFF_H
#include<string>
//interface of universitystaff
#include<iostream>
using namespace std;
class UniversityStaff
{
public:
	UniversityStaff();/*construcot*/
	UniversityStaff(string theName);/*construcot*/
	UniversityStaff(const UniversityStaff& theObject);/*construcot*/
	string getName() const;/*accessor*/
	UniversityStaff& operator=(const UniversityStaff& rtside);/*oprator overloading=*/
	friend istream& operator >>(istream& input, UniversityStaff& s); /*oprator overloading>>*/
	friend ostream& operator <<(ostream& output, UniversityStaff& s);/*oprator overloading<<*/
private:
	string name;
};
#endif
