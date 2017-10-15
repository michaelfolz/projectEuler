// Problem 4.cpp : Defines the entry point for the console application.
/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/



#include "stdafx.h"
int palindromic(long int num); 
long int reverse(long int num);

int _tmain(int argc, _TCHAR* argv[])
{
	int result = 0;
	long int highestpalendrome = 0; 
	
	int i = 0, j = 0; 

	for (i = 1; i <= 999; i++)
	{
		for (j = 1; j <= 999; j++){
			result = palindromic(j*i);
			if (result)
			{
				printf("\n %d %d %d", j, i, j*i);
				if (i*j > highestpalendrome)
				highestpalendrome = i*j;
			}
			
		}
	}

	printf("\n The highest palendrome is  %d", highestpalendrome);

	while (1);
}


//check if number is palindromic 
int palindromic(int long num){
	long int result = 0; 
	if (num <= 0)
		return -1;
	result = reverse(num);
	if (result == num)
		return 1;
	return 0; 
}

// Reverse input number 
long int reverse(long int num) {
	long int rev = 0;

	// Algorithm doesnt support negative numbers
	if (num <= 0)
		return -1; 

	while (num != 0) {
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	return rev;
}