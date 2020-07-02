#include<iostream>
#include "Calculations.h"
#include<stdexcept>
#include<iomanip>

using namespace std;

int main()
{
	char userInput, upperInput;
	bool quit = false, valid = false;
	vector<double> gallons, miles;

	while (quit == false) //Loops through main menu
	{
		while (valid == false) //Testing for valid input
		{
			try
			{
				cout << "\nPress 'L' to log another tank for your vehicle." << endl
					<< "Or press 'Q' to quit and view the fuel economy of your vehicle. >> ";
				cin >> userInput;
				upperInput = toupper(userInput);
				if (upperInput != 'Q' && upperInput != 'L')
				{
					throw runtime_error("Invalid input. You must enter 'L' or 'Q'.");
				}
				valid = true;
			}
			catch (runtime_error& excpt)
			{
				cout << excpt.what() << endl;
			}
		}
		valid = false;

		if (upperInput == 'Q')
		{
			quit = true;
			break;
		}

		miles.push_back(GetMiles());
		cout << endl;
		gallons.push_back(GetGallons());
		cout << endl;
	}

	cout << fixed << setprecision(2) << "\nThe fuel economy of your vehicle is: " << GetMPG(miles, gallons) << " mpg" << endl;

	return 0;
}