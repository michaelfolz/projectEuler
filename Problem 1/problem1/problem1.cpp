// problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

*/

char positiveFactor(int number, int *listAddr);
char multipleOf(int number, int limitNumber, int *listNum);
char sumofMultiples(int number, long &sum, int limit);

int _tmain(int argc, _TCHAR* argv[])
{
	int *factorListThree = NULL;
	int upperLimit = 10; 
	int firstNum = 3, secondNum = 5;
	long number = 0; 
	long finalSum = 0;

	printf("\nType first number: ");
	scanf_s("%d", &firstNum,1);
	printf("Type second number: ");
	scanf_s("%d", &secondNum, 1);

	//Add sums independently 
	sumofMultiples(firstNum, number, 1000);
	finalSum += number;
	sumofMultiples(secondNum, number, 1000);
	finalSum += number;

	// subtract all moments of intersection
	int *listofFact = (int *)calloc(100, (sizeof(int)));
	multipleOf(min(firstNum, secondNum), max(firstNum, secondNum), listofFact);
	
	for (int i = 0; i < sizeof(listofFact); i++){
		if (listofFact[i] == 0)
			break; 
		sumofMultiples((listofFact[i]*secondNum), number, 1000);
		finalSum -= number;
	}

	printf("sum of all multiples for (%d) & (%d) is (%d)\n", firstNum, secondNum, finalSum);
	return 0;
}

/* char sumofMultiples(int number, long &sum, int limit){
	purpose: return the sum of multiples for the input number till the limit
	input:
		number - number to find multiples 
		limit - limit

*/
char sumofMultiples(int number, long &sum, int limit){
	char err = 0;
	int multiples = ceil((double)((double)limit /(double)number) - 1);

	sum = 0;
	for (int i = 1; i <= multiples; i++){
		sum += (number*i); 
	}
	return err; 
}

/* char multipleOf(int number, int limitNumber, int *listNum)
	purpose: return a list of numbers which are a result of the number being a multiple of limitNumber
	input:
		number - number to compare with limit
		limitNumber - upper limit 
		listNum - allocated memory 

*/
char multipleOf(int number, int limitNumber, int *listNum){
	char err = 0;
	int value=0, i = 0, count =0;

	if (listNum == NULL)
		return -1;

	while (value < (limitNumber - number)){
		value = (++count)*number;
		listNum[i++] = value;

	}
	return err; 
}

/* char positiveFactor(int number, int *listAddr){
purpose: return a list of numbers which are a factor of the input number
input:
	number - number to find factors
	listNum - allocated memory

*/
char positiveFactor(int number, int *listAddr){
	char err = 0; 
	int count,i = 0;
	
	if (listAddr == NULL)
		return -1;
	
	for (count = 1; count <= number; ++count){
		if (number%count == 0){
			listAddr[i++] = count;
		}
	}

	return err;
}