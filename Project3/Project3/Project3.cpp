// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

unsigned char primeNumbers[25] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
	37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
	79, 83, 89, 97 };

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

13195
/     \
5     2639
	/       \
	7      377
			/       \
			13      29
					/       \
					29      1


*/
int prime(unsigned long i); 
int _tmain(int argc, _TCHAR* argv[])
{
	prime(13195);
	return 0;
}

int prime(unsigned long i) {
	unsigned int count = 0; 
	
	if (i == 1){
		return 0;
	}

	for (count = 0; count < sizeof(primeNumbers); count++) {
		if ((i % primeNumbers[count]) == 0){
			i /= primeNumbers[count];
			printf("\n prime: %d i: %d", i, primeNumbers[count]);
		}
	
	}
	
	return prime(i); 
}
