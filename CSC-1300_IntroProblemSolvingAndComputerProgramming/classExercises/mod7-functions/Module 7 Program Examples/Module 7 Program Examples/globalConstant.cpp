/*********************************************
	Title: 		globalConstant.cpp
	Author:  	April R Crockett
	Date:  		February1 9, 2009
	Purpose:  	This program uses some global
				constants and calculates gross
				pay of an employee.
**********************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants
const double PAY_RATE = 22.55;	  // Hourly pay rate
const double BASE_HOURS = 40.0;	  // Max non-overtime hours
const double OT_MULTIPLIER = 1.5; // Overtime multiplier

// Function prototypes
double getBasePay(int);
double getOvertimePay(double);

int main()
{
	double hours,		// Hours worked
		basePay,		// Base pay
		overtime = 0.0, // Overtime pay
		totalPay;		// Total pay

	int num;
	basePay = getBasePay(num);
	// Get the number of hours worked.
	cout << "How many hours did you work? ";
	cin >> hours;

	// Get the amount of base pay.
	basePay = getBasePay(hours);

	// Get overtime pay, if any.
	if (hours > BASE_HOURS)
		overtime = getOvertimePay(hours);

	// Calculate the total pay.
	totalPay = basePay + overtime;

	// Set up numeric output formatting.
	cout << setprecision(2) << fixed << showpoint;

	// Display the pay.
	cout << "Base pay: $" << basePay << endl
		 << "Overtime pay $" << overtime << endl
		 << "Total pay $" << totalPay << endl;

	return 0;
}

/**********************************************************
	Function Name:  	getBasePay()
	Function Purpose:	This function accepts the number of
						hours worked as an argument and
						returns the employee's pay for
						non-overtime hours.
***********************************************************/
double getBasePay(int hoursWorked)
{
	double basePay; // To hold base pay

	// Determine base pay.
	if (hoursWorked > BASE_HOURS)
		basePay = BASE_HOURS * PAY_RATE;
	else
		basePay = hoursWorked * PAY_RATE;

	return basePay;
}

/**********************************************************
	Function Name:  	getOvertimePay()
	Function Purpose:	This function accepts the number
						of hours worked as an argument and
						returns the employee's overtime pay.
***********************************************************/
double getOvertimePay(double hoursWorked)
{
	double overtimePay; // To hold overtime pay

	// Determine overtime pay.
	if (hoursWorked > BASE_HOURS)
	{
		overtimePay = (hoursWorked - BASE_HOURS) * PAY_RATE * OT_MULTIPLIER;
	}
	else
		overtimePay = 0.0;

	return overtimePay;
}
