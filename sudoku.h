#ifndef  __SUDOKU__
#define __SUDOKU__

void sudokuGame();
int getSize();
void inItMat(int* mat, int size);
void checkSudoku(int* mat,int size);
int checkRow(int* mat, int size, int* helpArr);
int checkColumn(int* mat, int size, int* helpArr);
int checkBlock(int* mat, int size, int* helpArr);

#endif
