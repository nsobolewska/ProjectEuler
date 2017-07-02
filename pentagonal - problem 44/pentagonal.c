#include "pentagonal.h"

/************************************************************************************************************************************************************/
/* Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?*/
/*                                                                   https://projecteuler.net/problem=44                                                    */
/************************************************************************************************************************************************************/

/** Function which finds if the number is pentagonal:
*\param number is the number which is checked
*/

bool isPentagonal(unsigned long long number)
{
	float n = (1 + sqrt(1 + 24 * number)) / 6;
	if (n - (int)n != 0)
	{
		return false;
	}
	return true;
}

/** Function which converts the number to pentagonal:
*\param number is the number which is converted
*/
unsigned long long toPentagonal(unsigned long long number)
{
	return number*(3 * number - 1) / 2;
}

/** Function which adds two pentagonals:
*\param first is the first element of the addition
*\param second is the second element of the addition
*/
unsigned long long sum(unsigned long long first, unsigned long long second)
{
	return toPentagonal(first) + toPentagonal(second);
}

/** Function which subtracts two pentagonals:
*\param first is the first element of the subtraction
*\param second is the second element of the subtraction
*/
unsigned long long subtract(unsigned long long first, unsigned long long second)
{
	return toPentagonal(first) - toPentagonal(second);
}

int main()
{
	unsigned long long minimalDifference = LONG_LONG_MAX;
	for (unsigned long long i = 1; i < SEARCH_RANGE; i++)
	{
		for (unsigned long long j = i + 1; j < SEARCH_RANGE; j++)
		{
			unsigned long long difference = subtract(j, i);
			if (isPentagonal(sum(i, j)) && isPentagonal(difference) && difference < minimalDifference)
			{
					minimalDifference = difference;
			}
		}
	}
	printf("%u", minimalDifference);
	return 0;
}