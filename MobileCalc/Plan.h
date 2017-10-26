#pragma once
#include <string>
#include <map>
#include <array>

// Plan Class
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
	int includedData;

	std::array<tier_mins, 2> tiers;

	float followOnRateCalls;
	float followOnRateTexts;
	float followOnRateData;

	Plan();

  // Tiers probably should be structs
	Plan(std::string name,
		int cost,
		int incMin,
		int incTex,
		int incData,
		int t1Lim,
		float t1Cost,
		int t2Lim,
		float t2Cost,
		float flMin,
		float flTex,
		float flData);
};
