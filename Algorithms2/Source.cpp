#include <iostream>
#include <iomanip>

using namespace std;

//Coin Sort Algorithm-----------------------------------------------------------------------------------------
void changeCascade(double & a, double & b, double c)
{
	if (a - b >= c)
	{
		b = b + c;
		cout << c * 100 << "p, ";
	}
}

double changeDue(double change)
{
	double changeCount = 0; // find the change by taking the price from the payment amount.
	cout << "Coins due: ";
	while (change - changeCount >= 1.00)
	{
		++changeCount;
		cout << "1 pound, ";
	}
	changeCascade(change, changeCount, 0.50);
	while (change - changeCount >= 0.20) // allows the system to give two 20p coins when the remaining change is greater than 20p.
		changeCascade(change, changeCount, 0.20);
	changeCascade(change, changeCount, 0.10);
	changeCascade(change, changeCount, 0.05);
	while (change - changeCount >= 0.02)		// allows the system to give two 2p coins when the remaining change is 4p.
		changeCascade(change, changeCount, 0.02);
	changeCascade(change, changeCount, 0.01);

	cout << endl;
	return (changeCount);
}

void coinSort()
{
	double priceIn, payIn;
	cout << "Enter the price in pounds: ";
	cin >> priceIn;
	cout << "Enter the payment amount in pounds: ";
	cin >> payIn;
	double change = round((payIn - priceIn) * 100.0) / 100.0; // round the answer to just 2 dp.
	if (change == 0)
		cout << "No change due." << endl << endl;
	else
		cout << fixed << setprecision(2) << "Total change due is: " << changeDue(change) << endl << endl << defaultfloat;
}

//Knapsack Algorithm------------------------------------------------------------------------------------------
void knapsack()
{
	int value[10]{ 50, 110, 110, 120, 145, 185, 220, 250, 230, 300 },
		weight[10]{ 5, 10, 10, 12, 15, 18, 20, 22, 24, 30 },
		weightMax = 50, 
		knapsackW =0,
		knapsackV = 0,
		knapsackTopV = 0,
		i = 0;

	while (knapsackW < weightMax)
	{
		knapsackW = weight[i];
		knapsackV = value[i];
		i++;
	}
	knapsackTopV = knapsackW;

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