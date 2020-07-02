#include "Calculations.h"
#include <iostream>
#include <vector>
#include<stdexcept>

using namespace std;

vector<double> gallons, miles;

double GetMiles()
{
	double userInput;
	bool valid = false;

	while (valid == false)
	{
		try
		{
			cout << "How many miles? ";
			cin >> userInput;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input received, you must enter a decimal number.");
			}
			if (userInput < 0)
				throw runtime_error("Miles cannot be less than 0.");
			valid = true;
			miles.push_back(userInput);
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
		}
	}

	return userInput;
}
double GetGallons()
{
	double userInput;
	bool valid = false;

	while (valid == false)
	{
		try
		{
			cout << "How many gallons? ";
			cin >> userInput;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input received, you must enter a decimal number.");
			}
			if (userInput < 0)
				throw runtime_error("Gallons cannot be less than 0.");
			valid = true;
			gallons.push_back(userInput);
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
		}
	}

	return userInput;
}
double GetMPG(vector<double> miles, vector<double> gallons)
{
	double mpg = 0;
	return mpg;

}