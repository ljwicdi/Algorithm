#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include<numeric>


int main()
{
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	long long lastVal;

	int testCase;
	std::cin >> testCase;

	long long tempVal;

	std::cin >> tempVal;
	const long long  a1 = tempVal;
	std::cin >> tempVal;
	const long long  a2 = tempVal;
	std::cin >> tempVal;
	const long long  a3 = tempVal;


	bool isArithmeticSeq = false;
	if ((a3 - a2) == (a2 - a1))
	{
		isArithmeticSeq = true;
	}
	bool isGeometicSeq = false;
	if ((a3 / a2) == (a2 / a1))
	{
		isGeometicSeq = true;
	}

	lastVal = a3;

	int modifierVal = 0;
	if ((testCase > 3) && isArithmeticSeq && isGeometicSeq)
	{
		modifierVal = 1;
		std::cin >> tempVal;
		const long long  a4 = tempVal;
		if ((a4 - a3) == (a3 - a2))
		{
			isGeometicSeq = false;
		}
		else
		{
			isArithmeticSeq = false;
		}

		lastVal = a4;
	}

	for (int i = 3 + modifierVal; i < testCase; i++)
	{
		long long tempVal;
		std::cin >> tempVal;
		lastVal = tempVal;
	}

	if (isArithmeticSeq == true)
	{
		lastVal = lastVal + (a2 - a1);
	}

	if (isGeometicSeq == true)
	{
		lastVal = lastVal * (a2 / a1);
	}

	std::cout << lastVal;
}