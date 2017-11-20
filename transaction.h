//creates the transaction class file.
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction
{
	// member function declarations
public:
	Transaction();
	void read();
	int get_day();
	double get_amount();
	std::string get_description();
private:
	// member data declarations
	int m_day;
	double m_amount;
	std::string m_description;
};

#endif
