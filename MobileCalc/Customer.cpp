#include <map>
#include "Customer.h"
 #include "Plan.h"

extern std::map<std::string, Plan> plans;

Customer::Customer(std::string Plan, int mins, int texts, int data)
{
	planType = Plan;
	minutesUsed = mins;
	textsUsed = texts;
	dataUsed = data;
};

// Calculate Customer Bill
float Customer::calculateBill()
{
	float customerBill = 0;
	Plan custplan = plans[planType];

	// Calculate Calls
	int remainingMins = minutesUsed;
	if (remainingMins > custplan.includedMins)
	{
		remainingMins -= custplan.includedMins;
		for (int i = 0; i < custplan.tiers.size(); i++)
		{
			if (remainingMins > custplan.tiers[i].limit)
			{
				customerBill += (custplan.tiers[i].limit * custplan.tiers[i].cost);
			}
			else
			{
				customerBill += (remainingMins * custplan.tiers[i].cost);
			}
			remainingMins -= custplan.tiers[i].limit;
		}
		if (remainingMins > 0)
		{
			customerBill += (remainingMins * custplan.followOnRateCalls);
		}
	}

	// Calculate Texts
	int remainingTexts = textsUsed;
	if (remainingTexts > custplan.includedTexts)
	{

		customerBill += ((remainingTexts - custplan.includedTexts) * custplan.followOnRateTexts);
	}

	// Calculate Data
	int remainingData = dataUsed;
	if (remainingData > custplan.includedData)
	{

		customerBill += ((remainingData - custplan.includedData) * custplan.followOnRateData);
	}

	customerBill += custplan.baseCost;

	bill = customerBill;
	return bill;
};
