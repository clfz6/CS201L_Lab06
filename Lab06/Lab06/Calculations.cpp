#include "Calculations.h"
#include <iostream>
#include <vector>
#include<stdexcept>

using namespace std;



double GetMiles() //Asks user to input miles
{
	double userInput;
	bool valid = false;

	while (valid == false)
	{
		try
		{
			cout << "How many miles? ";
			cin >> userInput;
			if (cin.fail()) //Testing input
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input received, you must enter a decimal number.");
			}
			if (userInput < 0)
				throw runtime_error("Miles cannot be less than 0.");
			valid = true;
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
		}
	}

	return userInput;
}
double GetGallons() //Asks user to input gallons
{
	double userInput;
	bool valid = false;

	while (valid == false)
	{
		try
		{
			cout << "How many gallons? ";
			cin >> userInput;
			if (cin.fail()) //Testing input
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw runtime_error("Invalid input received, you must enter a decimal number.");
			}
			if (userInput < 0)
				throw runtime_error("Gallons cannot be less than 0.");
			valid = true;
		}
		catch (runtime_error& excpt)
		{
			cout << excpt.what() << endl;
		}
	}

	return userInput;
}
double GetMPG(vector<double> miles, vector<double> gallons) //Calculates mpg using the collected data
{
	double mpg = 0, totalMiles = 0, totalGallons = 0;
	int size;

	try
	{
		if (miles.size() == 0 || gallons.size() == 0)
		{
			throw runtime_error("No values recorded MPG is nan");
		}

		size = miles.size();

		for (int i = 0; i < size; i++) //Adding up all the elements from the vectors
		{
			totalMiles += miles[i];
			totalGallons += gallons[i];
		}
		mpg = totalMiles / totalGallons;
	}
	catch (runtime_error& excpt)
	{
		cout << excpt.what() << endl;
	}

	return mpg;

}