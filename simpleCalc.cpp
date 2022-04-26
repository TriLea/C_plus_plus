/*
* Tristan Lea
* Cs212 Iverson
* 4/15/22
* Description: A simple salary calculation based on user inputs.
*/
#include <iostream>
using namespace std;

int main() {
	int hourlyWage = 0;
	int workHoursPerWeek = 0;
	int workWeeksPerYear = 0;

	const int monthsPerYear = 12; 

	int annualSalary;
	int monthlySalary;

	//here I am copy pasting the code blocks of cout for user instruction, and
	//then cin with the insertation >> for taking user inputs. 
	//3 in total for the 3 variable
	cout << "Enter hourly wage: " << endl;
	cin >> hourlyWage;

	cout << "Enter hours worked per week: " << endl;
	cin >> workHoursPerWeek;

	cout << "Enter number of weeks worked per year: " << endl;
	cin >> workWeeksPerYear;

	//I added workWeeksPerYear as specified, it was originally assumed to be 50.
	//I put the formula here because it relys on the previous variable for the
	//calculation and it is being used in the next code block.
	annualSalary = hourlyWage * workHoursPerWeek * workWeeksPerYear;
	cout << "Annual Salary is: ";
	cout << annualSalary << endl;

	//this is just a simple extension of the line 34 calculation.
	cout << "Monthly salary is: ";
	monthlySalary = annualSalary / monthsPerYear;
	cout << monthlySalary << endl;

	return 0;
}