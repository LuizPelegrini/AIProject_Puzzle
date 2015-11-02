#include "myQueue.h"

int CreateQueue() {

	SetFinalState();

	if (!(myQueue = (Queue*)malloc(sizeof(Queue)))){
		printf("%s\n", "Creation of the Queue has failed!");
		return 0;
	}

	myQueue->numberOfElements = 0;
	myQueue->firstState = NULL;
	myQueue->queueHead = NULL;

	myMode = GREEDY;

	return 1;
}

// First Stage has no parent, param = NULL
int CreateFirstState() {
	if (!CreateNewState(NULL, NONE))
		return 0;
	return 1;
}

void CreateHashTable() {
	int i, j, k = 0;

	positions = (Position*)malloc(10 * sizeof(Position));

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			positions[k].num = k + 1;
			positions[k].i = i;
			positions[k].j = j;
			k++;
		}
	}
}

int IsEmpty() {
	if (myQueue->numberOfElements == 0)
		return 1;
	return 0;
}

void Insert(State *state, Mode mode) {
	State *aux;
	
	if (IsEmpty()) {
		state->value = CalculateValue(state);
		myQueue->firstState = state;
		myQueue->queueHead = state;
		myQueue->numberOfElements++;
	}
	else {
		aux = myQueue->queueHead;

		switch (mode)
		{
			// Breadth First Search
		case 1:
			while (aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = state;
			myQueue->numberOfElements++;
			break;

			// Depth First Search
		case 2:
			state->next = aux->next;
			aux->next = state;
			myQueue->numberOfElements++;
			break;

			// Greedy best-first search
		case 3:
			state->value = CalculateValue(state);
			while ((aux->next != NULL) && (aux->next->value <= state->value)) {
				aux = aux->next;
			}
			state->next = aux->next;
			aux->next = state;
			myQueue->numberOfElements++;
			break;
		case 4:
			break;
		default:
			break;
		}
	}
}

int CreateNewState(State *parent, Action action) {
	State *newState;

	if (!(newState = (State*)malloc(sizeof(State))))
		return 0;

	// The first (randomly) generated state ---> no parent
	if (parent == NULL)
	{
		newState->parent = NULL;
		newState->matrix = CreateDesiredMatrix(3);
		newState->id = TurnMatrixIntoInt(newState->matrix);
		newState->cost = 0;
		newState->action = action;
		newState->next = NULL;

		Insert(newState, myMode);
		//free(newState);
		return 1;
	}
	else{
		
		switch (action) {
			case UP:
				newState->matrix = MoveUp(parent->matrix);
				newState->id = TurnMatrixIntoInt(newState->matrix);
				if (!IsInTheQueue(newState)) {
					newState->parent = parent;
					newState->action = action;
					newState->cost = parent->cost + 1;
					
					newState->next = NULL;

					Insert(newState, myMode);
				}else
					free(newState);
				break;
			case DOWN:
				newState->matrix = MoveDown(parent->matrix);
				newState->id = TurnMatrixIntoInt(newState->matrix);
				if (!IsInTheQueue(newState)) {
					newState->parent = parent;
					newState->action = action;
					newState->cost = parent->cost + 1;
					
					newState->next = NULL;

					Insert(newState, myMode);
				}else
					free(newState);
				break;
			case LEFT:
				newState->matrix = MoveLeft(parent->matrix);
				newState->id = TurnMatrixIntoInt(newState->matrix);
				//newState->matrixString = TurnMatrixIntoString(newState->matrix);
				if (!IsInTheQueue(newState)) {
					newState->parent = parent;
					newState->action = action;
					newState->cost = parent->cost + 1;
					
					newState->next = NULL;

					Insert(newState, myMode);
				}else
					free(newState);
				break;
			case RIGHT:
				newState->matrix = MoveRight(parent->matrix);
				newState->id = TurnMatrixIntoInt(newState->matrix);
				if (!IsInTheQueue(newState)) {
					newState->parent = parent;
					newState->action = action;
					newState->cost = parent->cost + 1;
					newState->next = NULL;

					Insert(newState, myMode);
				}else
					free(newState);
				break;
			default:
				printf("%s\n", "INVALID ACTION!");
				break;
		}
		//free(newState);
		return 1;
	}

}

int Pop() {
	State *currentState;

	currentState = myQueue->queueHead;
	
	if (IsEmpty()) {
		printf("%s", "The queue is empty, Pop operation cannot be done!");
		return 0;
	}

	// Is it the final state?
	if (IsFinalState(currentState)) {
		ShowResults();
		return 1;
	}
	else {

		// Find the position where the number zero of the current matrix is
		FindZeroPosition(currentState->matrix);

		// Is it possible to change the numbers within the matrix?
		if (CanMoveUp()) {
			CreateNewState(currentState, UP);
		}
		if (CanMoveDown()) {
			CreateNewState(currentState, DOWN);
		}
		if (CanMoveLeft()) {
			CreateNewState(currentState, LEFT);
		}
		if (CanMoveRight()) {
			CreateNewState(currentState, RIGHT);
		}
	}

	// Take out from the queue
	// Move the queue first state to the next element
	// Decrement one state of the queue, but we need to store it once we need to show the actions taken, at the end
	myQueue->queueHead = myQueue->queueHead->next;
	myQueue->numberOfElements--;

	// free(currentState);

	return 2;
}

int IsFinalState(State *state) {
	/*if (!strcmp(state->matrixString, finalState.matrixString))
		return 1;
	return 0;*/

	if (state->id == finalState.id)
		return 1;
	return 0;
}

int IsInTheQueue(State *state) {
	State *aux;
	aux = myQueue->firstState;

	do {
		if (aux->id == state->id)
			return 1;
		aux = aux->next;
	} while (aux != NULL);

	return 0;
}

// How far the state is from the goal?
int CalculateValue(State *state) {
	int i, j;
	int total = 0;

	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++) {
			if(!IsOnPlace(state->matrix[i][j], i, j)){
				total += DistanceValue(state->matrix[i][j], i, j);
			}
		}
	}

	return total;
}

int DistanceValue(int num, int i, int j) {
	int temp = 0;
	int tempi = i;
	int tempj = j;
	int index;

	if (num != 0)
		index = num - 1;
	else
		index = 8;


	// ***** Position i ******
	if (positions[index].i > i) {
		do {
			temp++;
			tempi++;
		} while (positions[index].i > tempi);
	}
	else {
		while (positions[index].i < tempi) {
			temp++;
			tempi--;
		}
	}
	

	// ******* Position j *******
	if (positions[index].j > j) {
		do {
			temp++;
			tempj++;
		} while (positions[index].j > tempj);
	}
	else {
		while (positions[index].j < tempj) {
			temp++;
			tempj--;
		}
	}

	return temp;
}

int IsOnPlace(int num, int i, int j) {
	int index;

	if (num != 0)
		index = num - 1;
	else
		index = 8;

	if (positions[index].i == i && positions[index].j == j)
		return 1;
	return 0;
}

































// Check this for later setup <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SetFinalState(){
	finalState.action = NONE;
	finalState.cost = -1;
	finalState.id = 123456780;
}

void ShowResults(){
	State *aux;
	aux = myQueue->queueHead;

	while (aux->parent != NULL) {
		switch (aux->action)
		{
		case UP:
			printf("Action taken: %s\n", "UP");
			break;
		case DOWN:
			printf("Action taken: %s\n", "DOWN");
			break;
		case LEFT:
			printf("Action taken: %s\n", "LEFT");
			break;
		case RIGHT:
			printf("Action taken: %s\n", "RIGHT");
			break;
		}
		aux = aux->parent;
	}
}