#pragma once
#include <string>
#include <map>
#include <array>

class Plan {
	struct tier_mins{
		int limit;
		float cost;
	};
public:
	std::string planName;
	int baseCost;
	int includedMins;
	int includedTexts;

	std::array<tier_mins, 2> tiers;

	float followOnRateCalls;
	float followOnRateTexts;

	Plan();

	Plan(std::string name,
		int cost,
		int incMin,
		int incTex,
		int t1Lim,
		float t1Cost,
		int t2Lim,
		float t2Cost,
		float flMin,
		float flTex);
};

