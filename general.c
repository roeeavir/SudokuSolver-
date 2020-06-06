
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#include  "general.h"

#define MAXRANGE 500//Random max value to the range (Picked by programmer).

//Picks a random range.
int random()
{
	return ((rand() % MAXRANGE) + 1);

}

//Inserts numbers into an array from the user.
void inItArr(int* arr, int size)
{
	printf("Fill the array:\n");
	for(int i = 1; i <= size; i++, arr++)
	{
		printf("Number %d out of %d:\n", i, size);
		scanf("%d", arr);
		printf("\n");
	}
}

//Prints an array.
void printArr(const int* arr, int size)
{
	for(int i = 0; i < size; i++, arr++)
		printf("%5d", *arr);
	printf("\n");
}

//Sets the highest and lowest values into the wanted addresses.
void getMostLeast(int* arr, int* most, int* least,int* mostIndex, int* leastIndex, int size)
{
	*most = *arr;
	*least = *arr;
	for(int i = 1; i < size; i++)
	{
		if(*(arr+i) > *most)
		{
			*most = *(arr+i);
			*mostIndex = i;
		}
		if(*(arr+i) < *least)
		{
			*least = *(arr+i);
			*leastIndex = i;
		}
	}
}

//Prints a matrix.
void printMat(const int* mat, int rows, int columns)
{
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			printf("%5d", *mat);
			mat++;
		}
		printf("\n");
	}
}

