// Problem 7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
char prime(unsigned __int64 nmbr);

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int target = 10001; 
	unsigned int result = 0; 
	unsigned long n = 100000000; 

	for (n =2 ; n < 100000000; n++){
		if (prime(n))
			result++;

		if (result ==target)
		{
			printf("\n %d ", n);
			return 0;
		}
	}

	return 0;
}


/* char prime(unsigned __int64 nmbr)
purpose: take input number, if input number is prime return 1
input: nmbr - number to check if prime
*/
char prime(unsigned __int64 nmbr){
	int cmp = 0;
	
	if (!(nmbr % 2) || nmbr < 2)
		return 0; 

	for (cmp = 2; cmp < nmbr; cmp++){
		if (nmbr % cmp == 0)
			return 0;
	}
	return 1;
}