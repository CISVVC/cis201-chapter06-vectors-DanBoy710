/**
*File: BankStatementMain.cpp
*Developer: Danny Michalak
*Email: michalakd@student.vvc.edu
*Description: The program will prompt the user to enter the day, amount, and description of a transaction. Then it will output a statement for a period of 30 days.
*/

#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"
#include "statement.h"

int main() 
{
	Statement statement;
	statement.read();
	statement.compute_balances();
	statement.print();
	
	return 0;
} 
