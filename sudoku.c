
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "sudoku.h"
#include "general.h"

void sudokuGame()
{
	printf("Enter a valid sudoku board size (1,4,9,16,25):\n");
	int size = getSize();
	int mat[size][size];
	inItMat(*mat, size);
	printMat(*mat, size, size);
	checkSudoku(*mat, size);
}

//Inserts a size from the user and checks it for validation.
int getSize()
{
	int size;
	double isSqrt;
	do 
	{
		scanf("%d", &size);
		isSqrt = sqrt(size);
		if(isSqrt -(int)isSqrt != 0)
		{
			printf("Size must have a perfect square root!\nEnter a different size(1,4,9,16,25):\n");
			size = 0;
		}
		else if(size > 25)
			printf("Size cannot be higher than 25\nEnter a different size(1,4,9,16,25):\n");
	} while(size == 0 || size > 25);	
	return size;
}

//Inserts values into a matrix from the user.
void inItMat(int* mat, int size)
{
	int powSize = pow(size, 2);
	for(int i = 0; i < powSize; i++, mat++)
	{
		do
		{
			printf("Fill the number (%d) out of %d:\n ", i+1, powSize);
			scanf("%d", mat);
			if(*mat > size || *mat < 1)
				printf("Number cannot be bigger than the size of the board!\nTry again:");
		} while(*mat > size || *mat < 1);
	}  
}

//Checks the sudoku board.
void checkSudoku(int* mat,int size)
{
	int isValid = 0;
	int helpArr[size];
	isValid += checkRow(mat, size, helpArr);
	isValid += checkColumn(mat, size, helpArr);
	isValid += checkBlock(mat, size, helpArr);
	if(isValid == 0)
		printf("Board is valid!");
} 

//Checks the rows.
int checkRow(int* mat, int size, int* helpArr)
{	
	printf("\n");
	memset(helpArr, 0, size*sizeof(int));
	//Runs on every row and checks it for repeated values.
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			helpArr += (*(mat + i*size + j) - 1);
			*helpArr += 1;
			if(*helpArr > 1)
			{
				printf("Sudoku board has an invalid row!\n");
				return -1;
			}
			helpArr -= (*(mat + i*size + j) - 1);
		}
		memset(helpArr, 0, size*sizeof(int));//Resets array.
	}
	return 0;
	
}

//Checks the columns.
int checkColumn(int* mat, int size, int* helpArr)
{
	memset(helpArr, 0, size*sizeof(int));
	//Runs on every column and checks it for repeated values.
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			helpArr += (*(mat + j*size + i) - 1);
			*helpArr += 1;
			if(*helpArr > 1)
			{
				printf("Sudoku board has an invalid column!\n");
				return 1;
			}
			helpArr -= (*(mat + j*size + i) - 1);
		}
		memset(helpArr, 0, size*sizeof(int));//Resets array.
	}
	return 0;
}

//Checks the blocks.
int checkBlock(int* mat, int size, int* helpArr)
{
	memset(helpArr, 0, size*sizeof(int));
	int counter = 1;
	int sqrtSize = sqrt(size);
	//Makes the pointer jump a block.
	for(int k = 0; k <= pow(size,2)-size; k += sqrtSize, counter++)
	{
		//Runs in the block and checks it for repeated values.
		for(int i = 0; i < sqrtSize; i++)
		{
			for(int j = 0; j < sqrtSize; j++)
			{			
				helpArr += (*(mat + i*size + j + k) - 1);
				*helpArr += 1;
				if(*helpArr > 1)
				{
					printf("Sudoku board has an invalid block!\n");
					return 1;
				}
				helpArr -= (*(mat + i*size + j + k) - 1);
				}
		}
		if(counter % sqrtSize == 0)
			k += size*(sqrtSize-1);
		memset(helpArr, 0, size*sizeof(int));//Resets array.
	}
	return 0;
}
