#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h>
#include <string.h>
#include "MyMatrix.h"

typedef enum mode{
	BFS = 1, DFS
}Mode;

typedef enum action {
	NONE = 1, RIGHT, LEFT, UP, DOWN
}Action;

typedef struct state {
	int **matrix;
	char *matrixString;
	Action action;
	struct state *parent;
	struct state *next;
	int cost;
}State;

typedef struct queue {
	int numberOfElements;
	State *firstState;
}Queue;

Queue *myQueue;
Mode myMode;
State finalState;


int CreateQueue();
int CreateFirstState();
int IsEmpty();
void Insert(State *state, Mode mode);
int CreateNewState(State* parent, Action action);
int Pop();
int IsFinalState(State *state);
void SetFinalState();
void ShowResults();
#endif
