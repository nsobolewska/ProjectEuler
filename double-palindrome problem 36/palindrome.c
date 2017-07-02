#include "palindrome.h"

/****************************************************************************************************/
/* Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2. */
/*                              https://projecteuler.net/problem=36                                 */	
/****************************************************************************************************/

/** Function which finds if the number is palindrom:
 *\param number is the number which is checked
 *\param numberSystem is the system in which the number is checked 
*/
bool isPalindrome(int number, int numberSystem)
{
	bool isPalindrome = true;
	int count = 0;
	int split = number;
	if (number < 0)
		return false;
	while (split > 0)
	{
		split = split / numberSystem;
		count += 1;
	}
	int* tab = (int*)malloc(count * sizeof(int));
	split = number;
	for (int i = 0; i < count; i++)
	{
		tab[i] = split % numberSystem;
		split = (split - tab[i]) / numberSystem;
	}
	for (int i = 0; i < count / 2; i++)
	{
		if (tab[i] != tab[count - i - 1])
		{
			isPalindrome = false;
		}
	}
	return isPalindrome;
}

/** Function which finds if the number is palindrome in decimal and binary system:
*\param number is the number which is checked
*/
bool isDecimalAndBinaryPalindrome(int number)
{
	return isPalindrome(number, DECIMAL) && isPalindrome(number, BINARY);
}

int main()
{
	int sum = 0;
	for (int i = 0; i < 1000000; i++)
	{
		bool isPalindrom = isDecimalAndBinaryPalindrome(i);
		if (isPalindrom)
		{
			sum += i;
		}
	}
	printf("The sum of all duble-palindromes less than one million is: %i\n", sum);
	return 0;
}