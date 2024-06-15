#include <iostream>
#include <string>
#include "administrator.h"
using namespace std;

namespace SavitchEmployees
{
	Administrator::Administrator()/*constructor*/
		: annualSalary(0), adminTitle("none"), company("none"), supervisor("none")
	{

	}

	Administrator::Administrator(const string& theName, const string& theNumber, double theWeeklySalary)/*constructor*/
		: SalariedEmployee(theName, theNumber, theWeeklySalary)
	{
		annualSalary = theWeeklySalary * 365.0 / 7.0;
	}

	void Administrator::setAnnualSalary(double theAnnualSalary)/*mutator*/
	{
		annualSalary = theAnnualSalary;
	}

	void Administrator::setAdminTitle(const string& theAdminTitle)/*mutator*/
	{
		adminTitle = theAdminTitle;
	}

	void Administrator::setCompanyArea(const string& theCompany)/*mutator*/
	{
		company = theCompany;
	}

	void Administrator::setSupervisor(const string& theSupervisor)/*mutator*/
	{
		supervisor = theSupervisor;
	}

	double Administrator::getAnnualSalary() const /*accessor*/
	{
		return annualSalary;
	}

	void Administrator::input()/*let user input*/
	{
		string enteredTitle, enteredComArea, enteredSupervisor;

		cout << "Enter the administrator title: \n";
		cin >> enteredTitle;
		cout << "Enter the company area of responsibility: \n";
		cin >> enteredComArea;
		cout << "Entered the name of supervisor: \n";
		cin >> enteredSupervisor;

		setAdminTitle(enteredTitle);
		setCompanyArea(enteredComArea);
		setSupervisor(enteredSupervisor);
	}

	void Administrator::printCheck()/*print check*/
	{
		setNetPay(annualSalary);
		cout << "\n__________________________________________________\n";
		cout << "Pay to the order of " << getName() << endl;
		cout << "Administrator Title: " << adminTitle << endl;
		cout << "Company area of responsibility " << company << endl;
		cout << "Supervisor Name: " << supervisor << endl;
		cout << "The sum of " << getNetPay() << " Dollars\n";
		cout << "_________________________________________________\n";
		cout << "Check Stub NOT NEGOTIABLE \n";
		cout << "Employee Number: " << getSsn() << endl;
		cout << "Salaried Employee. Regular Pay: " << getSalary() << endl;
		cout << "Annual Salary: " << annualSalary << endl;
		cout << "_________________________________________________\n";
	}
}