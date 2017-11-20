#include <iostream>
#include "transaction.h"
#include <string>

// defualt constructor sets member variables to zeros
Transaction::Transaction()
{
	int m_day = 0;
	double m_amount = 0.0;
}

// set member variables
void Transaction::read()
{
	std::cin >> m_day;
	std::cin >> m_amount;
	std::cin.ignore();
	std::getline(std::cin, m_description);
}
/**
 * @return int / day member variable
 */
int Transaction::get_day()
{
	return m_day;
}

/**
 * @return double / amount member variable
 */
double Transaction::get_amount()
{
	return m_amount;
}

/**
 * @return string / description member variable
 */
std::string Transaction::get_description()
{
	return m_description;
}
