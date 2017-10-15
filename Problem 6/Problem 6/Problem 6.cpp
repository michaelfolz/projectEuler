// Problem 6.cpp : Defines the entry point for the console application.
//
/*

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


*/
#include "stdafx.h"
// completed using brute force, not very proud 


int rootFind(int value, int divisor); 
long int sumNumbers(int highestNumb);
long int sumSquares(int highestNumb); 

int _tmain(int argc, _TCHAR* argv[])
{
	int sumofSquares = 0; 
	int sumNSquare = sumNumbers(100);
	sumNSquare *= sumNSquare;
	sumofSquares = sumSquares(100);

	printf("\n  %d %d", sumofSquares, sumNSquare);
	printf("\n %d", sumNSquare - sumofSquares);

	while (1);
	return 0;
}

long int sumSquares(int highestNumb){
	long int result = 0;
	int i = 0;
	for (i = 1; i <= highestNumb; i++){
		result += (i*i);
	}
	return result; 
}

long int sumNumbers(int highestNumb){
	if (highestNumb <= 0)
		return 0; 
	return highestNumb + (sumNumbers(highestNumb - 1));

}



/*	int numberArray[100]; 
	int result = 0;
	int i = 0, j = 0; 
	for (j = 0; j < 10; j++){
		numberArray[j] = 1; 
	}

	for (j = 10; j > 1; j--){
		for (i = 10; i > 1; i--){
			result = rootFind(j, i);
			if (result > 1){
				printf("\n i: %d , j:%d %d", i, j, result); /// i^result 
				numberArray[i] += 1; 
			}
		}
	}
	for (j = 0; j < 10; j++){
		printf("\n %d %d", j, numberArray[j] );
	}

	printf("\n debug \n\n");
	printf("\n %d ", rootFind(8, 2));*/

int rootFind(int value, int divisor){
	int root = 0;
	if ((value % divisor) && (value != divisor))
		return 0;

	while (!(value % divisor) && (value != 0)) {
	
		value /= divisor;
		root++;
	}
	
	if (value > divisor)
	   return 0;

	
	return root;
}

/*
int rootFind(int value, int divisor){
	if ((value % divisor) && (value != divisor))
		return 0;

	return 1 + (rootFind((value / divisor), divisor));
}*/