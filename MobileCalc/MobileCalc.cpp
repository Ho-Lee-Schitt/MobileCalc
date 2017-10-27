// MobileCalc.cpp : Defines the entry point for the console application.
//
#include <map>
#include <iostream>
#include <fstream>
#include <limits>

// #include "stdafx.h"
#include "Customer.h"
#include "Plan.h"

#include <stdio.h>
// #include <tchar.h>
#include <string.h>

std::map<std::string, Plan> plans;


// Helper function to get Mobile Plans.
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
		if (i < 10)
		{
			std::cerr << "Bad CSV file." << std::endl;
			return(1);
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
		try
		{
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
		// Catch invalid csv data.
		catch (std::invalid_argument& e) {
			std::cerr << "Bad CSV file." << std::endl;
			return(1);
		}
	}
	return (0);
}

// Validator function to validate string is a given type.
template <class T>
T read_input(std::string message)
{
	T input = -1;
	bool valid = false;
	do
	{
		std::cout << message << std::flush;
		std::cin >> input;
		if (std::cin.good() && input >= 0)
		{
			//everything went well, we'll get out of the loop and return the value
			valid = true;
		}
		else
		{
			//something went wrong, we reset the buffer's state to good
			std::cin.clear();
			//and empty it
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. " << std::endl;
		}
	} while (!valid);

	return (input);
}


int main()
{
	std::string filename, planname;
	int mins, texts;
	//std::cout << "Please enter file to read from: ";
	//std::cin >> filename;
	//if (!getPlans(filename))
	if (!getPlans("C:\\Users\\hughesn\\Documents\\Dev\\MobileCalc\\MobileCalc\\PlanDetails.csv"))
	//if (!getPlans("BadPlan.csv"))
	{
		bool gotPlan = false;
		while (!gotPlan)
		{
			std::cout << "Please enter the Customer's Plan name: ";
			std::cin >> planname;

			if (plans.find(planname) != plans.end())
			{
				gotPlan = true;
			}
			else
			{
				std::cout << "Plan not found." << std::endl;
			}
		}

		mins = read_input<int>("Please enter the Customer's used minutes: ");

		texts = read_input<int>("Please enter the Customer's used texts: ");

		Customer newCustomer = Customer(planname, mins, texts);

		std::cout << "The customer's bill is: \x9C" << newCustomer.calculateBill() << std::endl;
	}

	system("pause");
	return 0;
}
