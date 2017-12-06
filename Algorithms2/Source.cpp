#include <iostream>
#include <vector>

using namespace std;

//Coin Sort Algorithm-----------------------------------------------------------------------------------------
void changeCascade(double & a, double & b, double c)
{
	if (a - b> c)
		b = b + c;
}

double changeDue(double a, double b)
{
	double change = b - a, changeCount; // find the change by taking the price from the payment amount.
	if (change >= 1.00)
		while (changeCount < change)
			++changeCount;
	changeCascade(change, changeCount, 0.50);
	changeCascade(change, changeCount, 0.20);
	changeCascade(change, changeCount, 0.10);
	changeCascade(change, changeCount, 0.05);
	changeCascade(change, changeCount, 0.02);
	changeCascade(change, changeCount, 0.01);

	return (changeCount);
}

void coinSort()
{
	double priceIn, payIn;
	cout << "Enter the price in pounds: ";
	cin >> priceIn;
	cout << "Enter the payment amount in pounds: ";
	cin >> payIn;
	cout << "The change due is: " << changeDue(priceIn, payIn) << endl;
}

//Knapsack Algorithm------------------------------------------------------------------------------------------
void knapsack()
{

}

//Knapsack All------------------------------------------------------------------------------------------------
void knapsackAll()
{

}

//Menu----------------------------------------------------------------------------------------------
int main()
{
	int exercise = -1;
	while (exercise != 0)
	{
		cout << "Select an Algorithm ('1' for Coin, '2' for Knapsack or '3' for Knapsack All) or use 0 to exit: ";
		cin >> exercise;
		switch (exercise)
		{
		case 0:
			break;
		case 1:
			coinSort();
			break;
		case 2:
			knapsack();
			break;
		case 3:
			knapsackAll();
			break;

		default:
			cout << "Incorrect choice" << endl;
		}
	}
	return(0);
}