#include <iostream>
#include <iomanip>
#include "transaction.h"
#include "statement.h"

// defualt constructor
Statement::Statement()
{

}
// propmt user to enter transaction objects
void Statement::read()
{
	bool more = true;
	while (more)
	{
		Transaction t;
		// limits transactions vector to 30 objects
		if (transactions.size() < MAX_DAY)
		{
			t.read(); // sets member varibles of transaction object
			transactions.push_back(t); // pushes current transaction object to transactions variable
			std::cout << "Would you like to enter another? (Y/N)"; 
			char response;
			std::cin >> response;
			if (response != 'y' && response != 'Y')
				more = false;
		}
		else
		{
			more = false;
		}
	}

}

/**
 * @return double / the sum of tranaction's amounts
 */
double Statement::compute_balances()
{
	double count = 0.0;
	for (int i = 0; i < transactions.size(); i++)
	{
		count += transactions[i].get_amount(); // adds the amount of all transactions
	}
	return count;
}

// prints statement as a chart
void Statement::print()
{
	// prints statement header
	std::cout << std::setw(15) << std::left << "Day:" 
		<< std::setw(15) << std::left << "Amount:" 
		<< std::setw(15) << std::left << "Desription:" 
		<< std::setw(15) << std::left << "Balance:" << std::endl;
	// prints out elements of each object in the vector
	for (int i = 0; i < transactions.size(); i++)
	{
		current_balance += transactions[i].get_amount(); // set current balance
		std::cout << std::setw(15) << transactions[i].get_day() << std::setw(15) << transactions[i].get_amount()
			<< std::setw(15) << transactions[i].get_description() << std::setw(15) << current_balance << std::endl;
		
	}
	std::cout << "Average Daily Balance: " << get_average_daily_balance() << std::endl;
	std::cout << "Minimum Daily Balance: "<< get_minimum_daily_balance() << std::endl;
	std::cout << "Interest: " << get_interest() << std::endl;
}

/**
 * @return double / daily average of transactions
 */
double Statement::get_average_daily_balance()
{
	return compute_balances()/transactions.size();
}

/**
 * @return double / minimum daily balance of transactions
 */
double Statement::get_minimum_daily_balance()
{
	double minimum = transactions[0].get_amount();
	for (int i = 1; i < transactions.size(); i++)
	{
		if (transactions[i].get_amount() < minimum)
		{
			minimum = transactions[i].get_amount();
		}
	}
	return minimum;
}

/**
 * @return double / interest of transactions
 */
double Statement::get_interest()
{
	return get_average_daily_balance() * 0.005;
}
