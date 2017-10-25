// MobileCalc.cpp : Defines the entry point for the console application.
//
#include <map>
#include <iostream>
#include <fstream>
#include "stdafx.h"
#include "Customer.h"
#include "Plan.h"

#include <stdio.h>
#include <tchar.h>


std::map<std::string, Plan> plans;

int getPlans(std::string filepath)
{
	std::ifstream input;
	input.open(filepath);

	if (!input) {
		std::cerr << "Unable to open file " << filepath;
		return(1);   // call system to stop
	}

	std::string line = "";
	char *tokens = NULL;
	while (input >> line) {
		// std::cout << line << std::endl;
		std::array<std::string, 10> lineDetails;
		tokens = strtok((char *)line.c_str(), ",");
		int i = 0;
		while (tokens)
		{
			//std::cout << tokens << std::endl;
			lineDetails[i++] = tokens;
			tokens = strtok(NULL, ",");
		}
		i = 0;
		/*plans[lineDetails[0]] = Plan(lineDetails[i++], 
									std::stoi(lineDetails[i++]),
									std::stoi(lineDetails[i++]),
									std::stoi(lineDetails[i++]),
									std::stoi(lineDetails[i++]),
									std::stof(lineDetails[i++]),
									std::stoi(lineDetails[i++]),
									std::stof(lineDetails[i++]),
									std::stof(lineDetails[i++]),
									std::stof(lineDetails[i++]));*/
		plans[lineDetails[0]] = Plan(lineDetails[0],
									std::stoi(lineDetails[1]),
									std::stoi(lineDetails[2]),
									std::stoi(lineDetails[3]),
									std::stoi(lineDetails[4]),
									std::stof(lineDetails[5]),
									std::stoi(lineDetails[6]),
									std::stof(lineDetails[7]),
									std::stof(lineDetails[8]),
									std::stof(lineDetails[9]));
	}
	return (0);
}


int main()
{
	std::string filename, planname, mins, texts;
	//std::cout << "Please enter file to read from: ";
	//std::cin >> filename;
	//getPlans("PlanDetails.csv");
	if (!getPlans("PlanDetails.csv"))
	{
		std::cout << "Please enter the Customer's Plan name: ";
		std::cin >> planname;

		std::cout << "Please enter the Customer's used minutes: ";
		std::cin >> mins;

		std::cout << "Please enter the Customer's used texts: ";
		std::cin >> texts;

		Customer newCustomer = Customer(planname, std::stoi(mins), std::stoi(texts));

		std::cout << "The customer's bill is: £" << newCustomer.calculateBill() << std::endl;
	}

	std::cin >> filename;
	return 0;
}


