#include "myQueue.h"

int CreateQueue() {

	SetFinalState();
	
	if (!(myQueue = (Queue*)malloc(sizeof(Queue))))
		return 0;
	
	myQueue->numberOfElements = 0;
	myQueue->firstState = NULL;

	return 1;
}

// First Stage has no parent, param = NULL
void CreateFirstState() {
	State *state;
	Action action = NONE;
	state = CreateNewState(NULL);
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

State *CreateNewState(State *parent) {
	
	// If action is NONE, then it is the first generated state ---> no parent
	if (parent == NULL)
	{
		State *state;
		if (!(state = (State*)malloc(sizeof(State))))
			return NULL;

		state->parent = NULL;
		state->matrix = CreateRandomMatrix(3);
		state->matrixToString = TurnMatrixIntoString(state->matrix);
		state->custo = 0;
		state->action = NONE;
		state->next = NULL;

		Insert(state, myMode);

		return state;
	}
	else{
		FindZeroPosition(parent->matrix);
		if (CanMoveUp()) {
			// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< RIGHT HERE MAN!
		}
	}

}

int PopAndCheck() {
	State state;
	State *currentState;

	currentState = myQueue->firstState;
	state = *currentState;

	if (Verify(currentState)) {
		ShowResults();
		return 1;
	}
	else {
		CreateNewState(currentState);
		return 0;
	}

	myQueue->firstState = currentState->next;

	free(currentState);

}

int Verify(State *state) {
	if (!strcmp(state->matrixToString, finalState.matrixToString))
		return 1;
	return 0;
}


// Check this for later setup <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void SetFinalState(){
	finalState.action = NONE;
	finalState.custo = -1;
	finalState.matrixToString = "123456780";
}

void ShowResults(){}