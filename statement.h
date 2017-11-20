// creates a statement class file
#ifndef STATEMENT_H
#define STATEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

const int MAX_DAY = 30;

class Statement
{
public:
	// member fuction declarations
	Statement();
	void read();
	void print();
	double compute_balances();
	double get_average_daily_balance();
	double get_minimum_daily_balance();
	double get_interest();
private:
	// member variable declarations
	std::vector<Transaction> transactions;
	std::vector<double> daily_balances;
	double current_balance = 0;
};
#endif
