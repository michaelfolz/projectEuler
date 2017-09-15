// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Probably not the most efficient method, but it is quick, 
// a list of known prime factors is generated 


unsigned __int64 *primeList;
#define maxPrimeCalc 10000
#define primeListSize 10000
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

char primeListGenerate(unsigned __int64 *primeList);
char prime(unsigned __int64 nmbr);
int primeFact(unsigned __int64 i);

int _tmain(int argc, _TCHAR* argv[])
{
	primeList = (unsigned __int64 *)calloc(primeListSize, (sizeof(unsigned __int64)));


	if (primeListGenerate(primeList))
		printf("\n error in generating prime number list");
	printf("\n prime number %llu consists of the following factors: \n\t\t\t", 600851475143);
	primeFact(600851475143);
	return 0;
}


/* int primeFact(unsigned __int64 i) {
purpose: take input prime number compare it with prime list, print out max prime factor
	input: i 
	Depends:  maxPrimeCalc - max prime number in the system
	primeListSize - storeage size
*/
int primeFact(unsigned __int64 i) {
	unsigned int count = 0;

	if ((char)i == 1){
		return 0;
	}

	for (count = 0; count < primeListSize; count++) {
		if ((i % primeList[count]) == 0){
			i /= primeList[count];
			printf(" %llu,", primeList[count]);
			return primeFact(i);
		}
	}

	return 1;
}

/* char primeListGenerate(unsigned __int64 *primeList)
purpose: take input storage location, store list of prime numbers
	input: *primeList - pointer to allocated memory on the system 
	Depends:  maxPrimeCalc - max prime number in the system 
		  primeListSize - storeage size
*/
char primeListGenerate(unsigned __int64 *primeList){
	int counter = 0;
	
	if (primeList == NULL)
		return 1; 

	for (unsigned long i = 2; i < maxPrimeCalc; i++)
	{
		if (prime(i)){
			primeList[counter++] = i;
		}

		if (counter > primeListSize)
			return 1;

	}
	return 0;
}

/* char prime(unsigned __int64 nmbr)
purpose: take input number, if input number is prime return 1  
	input: nmbr - number to check if prime
*/
char prime(unsigned __int64 nmbr){
	int cmp = 0;

	for (cmp = 2; cmp < nmbr; cmp++){
		if (nmbr % cmp == 0)
			return 0;
	}
	return 1;
}