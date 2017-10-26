#include "Plan.h"

Plan::Plan()
{
	planName = "";
	baseCost = 0;
	includedMins = 0;
	includedTexts = 0;
	includedData = 0;
	tiers[0].limit = 0;
	tiers[0].cost = 0;
	tiers[1].limit = 0;
	tiers[1].cost = 0;
	followOnRateCalls = 0;
	followOnRateTexts = 0;
	followOnRateData = 0;
};

// Tiers probably should be structs
Plan::Plan(std::string name, int cost, int incMin, int incTex, int incData, int t1Lim, float t1Cost, int t2Lim, float t2Cost, float flMin, float flTex, float flData)
{
	planName = name;
	baseCost = cost;
	includedMins = incMin;
	includedTexts = incTex;
	includedData = incData;
	tiers[0].limit = t1Lim;
	tiers[0].cost = t1Cost;
	tiers[1].limit = t2Lim;
	tiers[1].cost = t2Cost;
	followOnRateCalls = flMin;
	followOnRateTexts = flTex;
	followOnRateData = flData;
};
