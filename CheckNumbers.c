
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "CheckNumbers.h"
#include "general.h"

#define MAXSIZE 12//Max size of the array.

void checkNumbers()
{
	printf("Please enter the size of the array (max size is %d): ", MAXSIZE);
	int n;
	scanf("%d", &n);
	if(n > 12)
		n = 12;
	int arr[n];
	
	int max = 0, min = 0;	
	getRange(&max, &min);//Sets a random min and max range.

	inItArr(arr, n);

	checkGame(arr, n, min, max);	
}




//Sets a max and min range.
void getRange(int* max, int* min)
{
	while(!(*max > *min))
	{
		*max = random();
		*min = random();
	}
	
	printf("Max = %d, Min = %d\n", *max, *min);
}

//Checks the numbers.
void checkGame(int* arr, int n, int min, int max)
{
	int one = 0, two = 0, three = 0, isOk = 1;
	
	printf("Your numbers:\n");
	printArr(arr, n);

	for(int i = 0; i < n; i++)
	{
		if(*(arr + i) < min || *(arr + i) > max)
			isOk = 0;
		else if(*(arr + i)/100 != 0)
			three++;
		else if(*(arr + i)/10 != 0)
			two++;
		else
			one++;
	}

	allNumbers(isOk);
	
	printf("%d -> 1-digit numbers, %d -> 2-digit numbers, %d -> 3 digit numbers.\n", one, two, three);

}

//Checks if all numbers are ok.
void allNumbers(int isOk)
{
	if(isOk == 1)
		printf("\nAll numbers are OK!\n");
	else
		printf("\nNOT all numbers are OK!\n");
}
