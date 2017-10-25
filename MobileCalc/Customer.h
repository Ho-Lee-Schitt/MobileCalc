#pragma once
#include <string>

// Customer Class
class Customer
{
private:
	std::string planType;
	int minutesUsed;
	int textsUsed;
	float bill;
public:
	Customer(std::string Plan, int mins, int texts);
	float calculateBill();
};