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
	char *matrixToString;
	Action action;
	struct state *parent;
	struct state *next;
	int custo;
}State;

typedef struct queue {
	int numberOfElements;
	State *firstState;
}Queue;

Queue *myQueue;
Mode myMode = BFS;
State finalState;

int CreateQueue();
int Insert(Queue *queue);
int IsEmpty(Queue *queue);
State* CreateNewState(State* parent);
void CreateFirstState();

#endif
