#pragma once
#include <string>

// Customer Class
class Customer
{
private:
	std::string planType;
	int minutesUsed;
	int textsUsed;
	int dataUsed;
	float bill;
public:
	Customer(std::string Plan, int mins, int texts, int data);
	float calculateBill();
};
