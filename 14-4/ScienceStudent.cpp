#include "ScienceStudent.h"
#include<iostream>
#include<string>
using namespace std;
ScienceStudent::ScienceStudent():discipline("none"),course("none") {}/*constuctor*/
ScienceStudent::ScienceStudent(string university, int regist, string dis, string course) :student(university,regist),discipline(dis), course(course){}/*constuctor*/
string ScienceStudent::getDiscipline() {/*accessor*/
	return discipline;
}
string ScienceStudent::getCourse() {/*accessor*/
	return course;
}
void ScienceStudent::setDispline(string d) {/*mutator*/
	discipline = d;
}
void ScienceStudent::setCourse(string c) {/*mutator*/
	course = c;
}