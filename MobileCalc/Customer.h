#pragma once
#include <string>

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