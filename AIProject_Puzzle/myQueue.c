#include "myQueue.h"

int CreateQueue() {

	SetFinalState();

	if (!(myQueue = (Queue*)malloc(sizeof(Queue)))){
		printf("%s\n", "Creation of the Queue has failed!");
		return 0;
	}

	myQueue->numberOfElements = 0;
	myQueue->firstState = NULL;

	return 1;
}

int CreateTree() {

	if (!(myTree = (Queue*)malloc(sizeof(Queue)))) {
		printf("%s\n", "Creation of the Tree has failed!");
		return 0;
	}

	myTree->numberOfElements = 0;
	myTree->firstState = NULL;

	return 1;
}

// First Stage has no parent, param = NULL
void CreateFirstState() {
	State *state;
	state = CreateNewState(NULL, NONE);
}

int IsEmpty() {
	if (myQueue->numberOfElements == 0)
		return 1;
	return 0;
}

int Insert(State *state, int mode) {
	State *aux;
	aux = myQueue->firstState;

	if (IsEmpty()) {
		myQueue->firstState = state;
		myQueue->numberOfElements++;
	}
	else {
		switch (mode)
		{
			// Breadth First Search
		case 1:

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
/*
	while (aux->next != NULL) {

		aux = aux->next;
	}*/
}

State *CreateNewState(State *parent, Action action) {
	
	// If action is NONE, then it is the first generated state ---> no parent
	if (parent == NULL)
	{
		State *newState;
		if (!(newState = (State*)malloc(sizeof(State))))
			return NULL;

		newState->parent = NULL;
		newState->matrix = CreateRandomMatrix(3);
		newState->matrixToString = TurnMatrixIntoString(newState->matrix);
		newState->cost = 0;
		newState->action = action;
		newState->next = NULL;

		Insert(newState, myMode);

		return newState;
	}
	else{
		State *newState;
		if (!(newState = (State*)malloc(sizeof(State))))
			return NULL;
		
		switch (action) {
			case UP:
				newState->parent = parent;
				newState->action = action;
				newState->cost = parent->cost + 1;
				newState->matrix = MoveUp(parent->matrix);
				newState->matrixToString = TurnMatrixIntoString(newState->matrix);
				
				// Is it the first element I am trying to insert?
				if (IsEmpty())
					newState->next = NULL;

				// If not, just insert it normally
				Insert(newState, myMode);
				break;
			case DOWN:
				break;
			case LEFT:
				break;
			case RIGHT:
				break;
			default:
				printf("%s\n", "INVALID ACTION!");
				break;
		}
	}

}

int Pop() {
	State *currentState;

	if (IsEmpty()) {
		printf("%s", "The queue is empty, Pop operation cannot be done!");
		return 0;
	}

	currentState = myQueue->firstState;

	// Is it the final state?
	if (IsFinalState(currentState)) {
		ShowResults();
		return 1;
	}
	else {
		// Low the number of elements in the queue
		myQueue->numberOfElements--;

		// Find the position where the number zero is
		FindZeroPosition(currentState->matrix);

		// Is it possible to change the numbers within the matrix?
		if (CanMoveUp()) {
			CreateNewState(currentState, UP);
		}
		if (CanMoveDown()) {
			CreateNewState(currentState, DOWN);
		}
	}

	// Take out from the queue
	myQueue->firstState = currentState->next;

	free(currentState);

	return 0;
}

int IsFinalState(State *state) {
	if (!strcmp(state->matrixToString, finalState.matrixToString))
		return 1;
	return 0;
}


// Check this for later setup <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SetFinalState(){
	finalState.action = NONE;
	finalState.cost = -1;
	finalState.matrixToString = "123456780";
}

void ShowResults(){}