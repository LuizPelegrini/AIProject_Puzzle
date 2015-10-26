#include "myQueue.h"

int CreateQueue() {

	SetFinalState();

	if (!(myQueue = (Queue*)malloc(sizeof(Queue)))){
		printf("%s\n", "Creation of the Queue has failed!");
		return 0;
	}

	myQueue->numberOfElements = 0;
	myQueue->firstState = NULL;

	myMode = BFS;

	return 1;
}

// First Stage has no parent, param = NULL
int CreateFirstState() {
	if (!CreateNewState(NULL, NONE))
		return 0;
	return 1;
}

int IsEmpty() {
	if (myQueue->numberOfElements == 0)
		return 1;
	return 0;
}

void Insert(State *state, Mode mode) {
	State *aux;
	
	if (IsEmpty()) {
		myQueue->firstState = state;
		myQueue->numberOfElements++;
	}
	else {
		aux = myQueue->firstState;

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
			break;
		case 3:
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
		newState->matrixString = TurnMatrixIntoString(newState->matrix);
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
				newState->parent = parent;
				newState->action = action;
				newState->cost = parent->cost + 1;
				newState->matrix = MoveUp(parent->matrix);
				newState->matrixString = TurnMatrixIntoString(newState->matrix);
				newState->next = NULL;

				Insert(newState, myMode);
				break;
			case DOWN:
				newState->parent = parent;
				newState->action = action;
				newState->cost = parent->cost + 1;
				newState->matrix = MoveDown(parent->matrix);
				newState->matrixString = TurnMatrixIntoString(newState->matrix);
				newState->next = NULL;

				Insert(newState, myMode);
				break;
			case LEFT:
				newState->parent = parent;
				newState->action = action;
				newState->cost = parent->cost + 1;
				newState->matrix = MoveLeft(parent->matrix);
				newState->matrixString = TurnMatrixIntoString(newState->matrix);
				newState->next = NULL;

				Insert(newState, myMode);
				break;
			case RIGHT:
				newState->parent = parent;
				newState->action = action;
				newState->cost = parent->cost + 1;
				newState->matrix = MoveRight(parent->matrix);
				newState->matrixString = TurnMatrixIntoString(newState->matrix);
				newState->next = NULL;

				Insert(newState, myMode);
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

	currentState = myQueue->firstState;
	
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

		// Find the position where the number zero is
		FindZeroPosition(currentState->matrix);

		// Is it possible to change the numbers within the matrix?
		if (CanMoveUp()) {
			CreateNewState(currentState, UP);
		}
		if (CanMoveDown()) {
			CreateNewState(currentState, DOWN);
		}
		if (CanMoveLeft()) {
			CreateNewState(currentState, DOWN);
		}
		if (CanMoveRight()) {
			CreateNewState(currentState, DOWN);
		}
	}

	// Take out from the queue
	// Move the queue first state to the next element
	// Decrement one state of the queue, but we need to store it once we need to show the actions taken, at the end
	myQueue->firstState = myQueue->firstState->next;
	myQueue->numberOfElements--;

	// free(currentState);

	return 2;
}

int IsFinalState(State *state) {
	if (!strcmp(state->matrixString, finalState.matrixString))
		return 1;
	return 0;
}


// Check this for later setup <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SetFinalState(){
	finalState.action = NONE;
	finalState.cost = -1;
	finalState.matrixString = "123456780";
}

void ShowResults(){
	State *aux;
	aux = myQueue->firstState;

	while (aux->parent != NULL) {
		printf("Action taken: %d\n", aux->action);
		aux = aux->parent;
	}
}