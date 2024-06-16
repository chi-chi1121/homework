//interface of studnet
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "UniversityStaff.h"
using namespace std;
class student
{
public:
	student();/*constructor*/
	student(string u,int r);/*constructor*/
	void setName(string theUniversity);/*mutator*/
	void setNumber(int newRegistration);/*mutator*/
	void setProctor();/*mutator*/
	string getUniversityName() const;/*accessor*/
	int getRegistNum() const;/*accessor*/
	string getProcterName();/*accessor*/

private:
	string university;
	int regist;
	UniversityStaff procter;
};


#endif // !STUDENT_H

