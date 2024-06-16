#include<iostream>
#include"UniversityStaff.h"
#include"student.h"
#include"ScienceStudent.h"
using namespace std;

int main()/*test function*/
{
	string name, displine, course;
	int number;
	cout << "Enter the university's name>";
	cin >> name;
	cout << "Enter the registration number>";
	cin >> number;
	cout << "Enter the displine>";
	cin >> displine;
	cout << "Enter the course>";
	cin >> course;

	ScienceStudent user(name, number, displine, course);
	user.setProctor();
	cout << "The universitys name is " << user.getUniversityName() << endl;
	cout << "The registration number is " << user.getRegistNum() << endl;
	cout << "The proctor's name is " << user.getProcterName() << endl;
	cout << "The science displine is " << user.getDiscipline() << endl;
	cout << "The undergraduate or postgraduate course is " << user.getCourse() << endl;
	return 0;
}