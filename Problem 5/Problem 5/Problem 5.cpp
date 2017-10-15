// Problem 5.cpp : Defines the entry point for the console application.
//
/*
Smallest multiple
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include "stdafx.h"
int checkDivide(long int value, int lower, int upper); 
int rootFind(int value, int divisor);

int _tmain(int argc, _TCHAR* argv[])
{
	long int smallestMultiple = 1; 
	while (!(checkDivide(smallestMultiple, 1, 20))){
		smallestMultiple++;
	}

	printf("\n The smallest number which is evenly divisible by 1 to 20 is %d", smallestMultiple); 
	


	while (1);
	return 0;

}



int checkDivide(long int value, int lower, int upper){
	int i = lower;
	for (; i <= upper; i++){
		if ((value % i) > 0)
			return 0; 
	}
	return 1; 
}
 
int rootFind(int value, int divisor){
	if (value % divisor)
		return 0; 

	return 1 + (rootFind((value / divisor), divisor));
}