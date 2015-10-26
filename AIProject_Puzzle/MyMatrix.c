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

	ShowMatrix(myMatrix);
	
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
	int i, j, k = 0;
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


int CanMoveDown() {
	if (positionY + 1 >= matrixSize)
		return 0;
	return 1;
}

int CanMoveLeft() {
	if (positionX - 1 < 0)
		return 0;
	return 1;
}

int CanMoveRight() {
	if (positionX + 1 >= matrixSize)
		return 0;
	return 1;
}

int** MoveUp(int **matrix) {
	int **newMatrix;
	int i, j;

	// Need to create a copy of the parent matrix
	newMatrix = (int**)malloc(matrixSize*sizeof(int*));
	for (i = 0; i < matrixSize; i++)
		newMatrix[i] = (int*)malloc(sizeof(int));

	for (i = 0; i < matrixSize; i++)
		for (j = 0; j < matrixSize; j++)
			newMatrix[i][j] = matrix[i][j];

	// Move '0' upwards
	newMatrix[positionY][positionX] = newMatrix[positionY - 1][positionX];
	newMatrix[positionY - 1][positionX] = 0;

	return newMatrix;
}

int** MoveDown(int **matrix) {
	int **newMatrix;
	int i, j;

	// Need to create a copy of the parent matrix
	newMatrix = (int**)malloc(matrixSize*sizeof(int*));
	for (i = 0; i < matrixSize; i++)
		newMatrix[i] = (int*)malloc(sizeof(int));

	for (i = 0; i < matrixSize; i++)
		for (j = 0; j < matrixSize; j++)
			newMatrix[i][j] = matrix[i][j];

	// Move '0' downwards
	newMatrix[positionY][positionX] = newMatrix[positionY + 1][positionX];
	newMatrix[positionY + 1][positionX] = 0;

	return newMatrix;
}

int** MoveLeft(int **matrix) {
	int **newMatrix;
	int i, j;

	// Need to create a copy of the parent matrix
	newMatrix = (int**)malloc(matrixSize*sizeof(int*));
	for (i = 0; i < matrixSize; i++)
		newMatrix[i] = (int*)malloc(sizeof(int));

	for (i = 0; i < matrixSize; i++)
		for (j = 0; j < matrixSize; j++)
			newMatrix[i][j] = matrix[i][j];

	// Move '0' leftwards
	newMatrix[positionY][positionX] = newMatrix[positionY][positionX - 1];
	newMatrix[positionY][positionX - 1] = 0;

	return newMatrix;
}

int** MoveRight(int **matrix) {
	int **newMatrix;
	int i, j;

	// Need to create a copy of the parent matrix
	newMatrix = (int**)malloc(matrixSize*sizeof(int*));
	for (i = 0; i < matrixSize; i++)
		newMatrix[i] = (int*)malloc(sizeof(int));

	for (i = 0; i < matrixSize; i++)
		for (j = 0; j < matrixSize; j++)
			newMatrix[i][j] = matrix[i][j];

	// Move '0' rightwards
	newMatrix[positionY][positionX] = newMatrix[positionY][positionX + 1];
	newMatrix[positionY][positionX + 1] = 0;

	return newMatrix;
}

void ShowMatrix(int **matrix) {
	int i, j;

	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++)
		{
			printf("%d | ", matrix[i][j]);
		}
		printf("\n");
	}
}


// Test Function
int **CreateDesiredMatrix(int size) {
	int **myMatrix;
	int i, j;
	int number = 1;

	matrixSize = size;
	myMatrix = (int**)malloc(size*sizeof(int*));


	for (i = 0; i < size; i++)
		myMatrix[i] = (int*)malloc(sizeof(int));

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			myMatrix[i][j] = number;
			number++;
		}
	}

	myMatrix[2][1] = 0;
	myMatrix[2][2] = 8;

	ShowMatrix(myMatrix);

	return myMatrix;
}
