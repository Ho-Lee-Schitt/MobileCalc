#include "Plan.h"

Plan::Plan()
{
	planName = "";
	baseCost = 0;
	includedMins = 0;
	includedTexts = 0;
	tiers[0].limit = 0;
	tiers[0].cost = 0;
	tiers[1].limit = 0;
	tiers[1].cost = 0;
	followOnRateCalls = 0;
	followOnRateTexts = 0;
};

Plan::Plan(std::string name, int cost, int incMin, int incTex, int t1Lim, float t1Cost, int t2Lim, float t2Cost, float flMin, float flTex)
{
	planName = name;
	baseCost = cost;
	includedMins = incMin;
	includedTexts = incTex;
	tiers[0].limit = t1Lim;
	tiers[0].cost = t1Cost;
	tiers[1].limit = t2Lim;
	tiers[1].cost = t2Cost;
	followOnRateCalls = flMin;
	followOnRateTexts = flTex;
};