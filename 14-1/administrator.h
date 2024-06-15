//the header file of administrator
#ifndef ADMINISTRATOR_H_
#define ADMINISTRATOR_H_
#include<iostream>
#include <string>
#include "salariedemployee.h"
using namespace std;


namespace SavitchEmployees
{
	class Administrator : public SalariedEmployee
	{
	public:
		Administrator();/*consturctor*/
		Administrator(const string& theName, const string& theNumber, double theWeeklySalary);/*consturctor*/
		void setAnnualSalary(double theAnnualSalary);/*mutator*/
		void setAdminTitle(const string& theAdminTitle);/*mutator*/
		void setCompanyArea(const string& theCompany);/*mutator*/
		void setSupervisor(const string& theSupervisor);/*mutator*/
		double getAnnualSalary() const;/*accessor*/
		void input();/*let user input the info*/
		void printCheck();/*print check*/
	protected:
		double annualSalary;
	private:
		string adminTitle;/*private member*/
		string company;
		string supervisor;
	};
}

#endif // ADMINISTRATOR_H_