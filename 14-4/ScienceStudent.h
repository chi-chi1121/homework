//interface of sciencestudnet
#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H
#include "student.h"
#include <iostream>
#include <string>
using namespace std;
class ScienceStudent:public student /*derived from student*/
{
public:
	ScienceStudent();/*constuctor*/
	ScienceStudent(string university, int regist, string dis, string course);/*constuctor*/
	string getDiscipline();/*accessor*/
	string getCourse();/*accessor*/
	void setDispline(string d);/*mutator*/
	void setCourse(string c);/*mutator*/
private:
	string discipline;
	string course;

};


#endif // !SCIENCESTUDENT_H

