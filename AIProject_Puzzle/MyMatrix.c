#include "MyMatrix.h"

int **CreateRandomMatrix(int size) {
	int **myMatrix;
	int i, j;
	
	matrixSize = size;
	myMatrix = (int**)malloc(size*sizeof(int*));
	
	InitiliazeNumberVector(size);
	
	for (i = 0; i < size; i++)
		myMatrix[i] = (int*)malloc(matrixSize*sizeof(int));

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
	char *temp;
	int i, j, k = 0;
	int n = matrixSize*matrixSize;
	int num = 10;

	if (n > 9)
		num = 100;
	else if (n > 99)
		num = 1000;

	string = (char*)malloc(n*sizeof(char));
	temp = (char*)malloc(sizeof(char));
	string[0] = '\0';
	for (i = 0; i < matrixSize; i++) {
		for ( j = 0; j < matrixSize; j++)
		{
			/*temp = (char)matrix[i][j];
			strcat(string, temp);
			k++;*/

			/*sprintf_s(temp, sizeof(int), "%d", matrix[i][j]);
			strcat_s(string, n*sizeof(char), temp);*/

			_itoa_s(matrix[i][j], temp, sizeof(int)*8+1, 10);
			//strcpy_s(string, sizeof(int), temp);
			strcat_s(string, num*sizeof(char), temp);
		}
	}
	//free(temp);
	return string;
}

int TurnMatrixIntoInt(int** matrix) {
	int id = 0;
	int power;
	int i, j;
	int k = matrixSize*matrixSize;

	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++)
		{
			k--;
			power = (int)pow(10, k);
			id += matrix[i][j]*power;
			
		}
	}

	return id;
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
		newMatrix[i] = (int*)malloc(matrixSize*sizeof(int));

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
		newMatrix[i] = (int*)malloc(matrixSize*sizeof(int));

	for (i = 0; i < matrixSize; i++)
		for (j = 0; j < matrixSize; j++)
			newMatrix[i][j] = matrix[i][j];

	// Move '0' downwards
	newMatrix[positionY][positionX] = newMatrix[positionY + 1][positionX];
	newMatrix[positionY + 1][positionX] = 0;

	return newMatrix;

	free(newMatrix);
}

int** MoveLeft(int **matrix) {
	int **newMatrix;
	int i, j;

	// Need to create a copy of the parent matrix
	newMatrix = (int**)malloc(matrixSize*sizeof(int*));
	for (i = 0; i < matrixSize; i++)
		newMatrix[i] = (int*)malloc(matrixSize*sizeof(int));

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
		newMatrix[i] = (int*)malloc(matrixSize*sizeof(int));

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
		myMatrix[i] = (int*)malloc(matrixSize*sizeof(int));

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			myMatrix[i][j] = number;
			number++;
		}
	}


	/*myMatrix[0][0] = 6;
	myMatrix[0][1] = 1;
	myMatrix[0][2] = 9;
	myMatrix[0][3] = 4;
	myMatrix[1][0] = 5;
	myMatrix[1][1] = 2;
	myMatrix[1][2] = 8;
	myMatrix[1][3] = 14;
	myMatrix[2][0] = 7;
	myMatrix[2][1] = 0;
	myMatrix[2][2] = 12;
	myMatrix[2][3] = 3;
	myMatrix[3][0] = 15;
	myMatrix[3][1] = 13;
	myMatrix[3][2] = 11;
	myMatrix[3][3] = 10;*/

	myMatrix[0][0] = 2;
	myMatrix[0][1] = 8;
	myMatrix[0][2] = 5;
	myMatrix[1][0] = 6;
	myMatrix[1][1] = 3;
	myMatrix[1][2] = 0;
	myMatrix[2][0] = 4;
	myMatrix[2][1] = 7;
	myMatrix[2][2] = 1;

	ShowMatrix(myMatrix);

	return myMatrix;
}
