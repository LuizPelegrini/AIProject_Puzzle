#include "MyMatrix.h"

int **CreateRandomMatrix(int size) {
	int **myMatrix;
	int i, j;
	
	matrixSize = size;
	
	myMatrix = (int**)malloc(size*sizeof(int*));
	
	InitiliazeNumberVector(size);
	
	for (i = 0; i < size; i++)
		myMatrix[i] = (int*)malloc(sizeof(int));

	for (i = 0; i < size; i++) {
		for  (j = 0; j < size; j++){
			myMatrix[i][j] = GetRandomNumber();
		}
	}

	return myMatrix;
}

void InitiliazeNumberVector(int arraySize) {
	int i;

	arrayLength = arraySize*arraySize;

	numberArray = (int*)malloc(arrayLength*sizeof(int));

	for (i = 0; i < arrayLength; i++) {
		numberArray[i] = i;
	}
}

int GetRandomNumber() {
	int index;
	int number;

	srand((unsigned)time(NULL));

	index = rand() % arrayLength;
	number = numberArray[index];
	RemoveAt(index);

	return number;
}

void RemoveAt(int index) {
	int i;

	for (i = index; i < arrayLength-1; i++) {
		numberArray[i] = numberArray[i + 1];
	}

	arrayLength--;
}

char* TurnMatrixIntoString(int **matrix) {
	char *string;
	int i, j, k;
	int n = matrixSize*matrixSize;

	string = (char*)malloc(n*sizeof(char));

	for (i = 0; i < matrixSize; i++) {
		for ( j = 0; j < matrixSize; j++)
		{
			string[k] = matrix[i][j] + '0';
			k++;
		}
	}

	return string;
}


void FindZeroPosition(int **matrix) {

	int found = 0;

	for (positionY = 0; positionY < matrixSize; positionY++)
	{
		for (positionX = 0; positionX < matrixSize; positionX++)
		{
			if (matrix[positionY][positionX] == 0) {
				found = 1;
				break;
			}
		}

		if (found)
			break;
	}
}

int CanMoveUp() {
	
	if (positionY - 1 < 0)
		return 0;

	return 1;
}

int** MoveUp(int **matrix) {
	int **newMatrix;

	newMatrix = matrix;

	newMatrix[positionY][positionX] = newMatrix[positionY - 1][positionX];
	newMatrix[positionY - 1][positionX] = 0;

	return newMatrix;
}

int CanMoveDown() {
	if (positionY + 1 > matrixSize)
		return 0;
	return 1;
}

int CanMoveLeft() {
	if (positionX - 1 < 0)
		return 0;
	return 1;
}

int CanMoveRight() {
	if (positionX + 1 > matrixSize)
		return 0;
	return 1;
}
