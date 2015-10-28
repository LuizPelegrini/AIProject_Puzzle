#ifndef MYMATRIX_H
#define MYMATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int *numberArray;
int arrayLength;
int matrixSize;
int positionX;
int positionY;

int **CreateRandomMatrix(int matrixSize);
int **CreateDesiredMatrix(int matrixSize);
void InitiliazeNumberVector(int arraySize);
int GetRandomNumber();
void RemoveAt(int index);
char* TurnMatrixIntoString(int **matrix);
int TurnMatrixIntoInt(int **matrix);
void FindZeroPosition(int **matrix);
int CanMoveUp();
int CanMoveDown();
int CanMoveLeft();
int CanMoveRight();
int** MoveUp(int** matrix);
int** MoveDown(int** matrix);
int** MoveLeft(int** matrix);
int** MoveRight(int** matrix);
void ShowMatrix(int** matrix);
#endif