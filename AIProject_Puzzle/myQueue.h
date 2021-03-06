#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdlib.h>
#include <string.h>
#include "MyMatrix.h"

typedef enum mode{
	BFS = 1, DFS, GREEDY
}Mode;

typedef enum action {
	NONE = 1, RIGHT, LEFT, UP, DOWN
}Action;

typedef struct hashTablePosition {
	int num;
	int i;
	int j;
}Position;

typedef struct state {
	int **matrix;
	int id;
	Action action;
	struct state *parent;
	struct state *next;
	int cost;
	int value;
}State;

typedef struct queue {
	int numberOfElements;
	State *firstState;
	State *queueHead;
}Queue;

Queue *myQueue;
Position *positions;
Mode myMode;
State finalState;


int CreateQueue();
int CreateFirstState();
int IsEmpty();
void Insert(State *state, Mode mode);
int CreateNewState(State* parent, Action action);
int Pop();
int IsFinalState(State *state);
int IsInTheQueue(State *state);
void SetFinalState();
void ShowResults();
void CreateHashTable();
int CalculateValue(State *state);
int DistanceValue(int num, int i, int j);
int IsOnPlace(int num, int i, int j);
#endif
