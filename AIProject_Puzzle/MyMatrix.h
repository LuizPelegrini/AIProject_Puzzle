#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <stdlib.h>
#include <time.h>

int *numberArray;
int arrayLength;
int matrixSize;
int positionX;
int positionY;

int **CreateRandomMatrix(int matrixSize);
void InitiliazeNumberVector(int arraySize);
int GetRandomNumber();
void RemoveAt(int index);
char* TurnMatrixIntoString(int **matrix);
void FindZeroPosition(int **matrix);
int CanMoveUp();
int CanMoveDown();
int CanMoveLeft();
int CanMoveRight();

#endif