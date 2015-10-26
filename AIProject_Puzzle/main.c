#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

int main() {
	int found;
	CreateQueue();
	CreateFirstState();

	do {
		found = Pop();
	} while (found !=0 && found!=1);

	if (found == 0) {
		printf("%s\n", "I am sorry, I could not find a reasonable result for you.");
	}
	else if (found == 1) {
		printf("%s\n", "The actions needed to find the result is stated above.");
	}

	system("PAUSE");

	return 0;
}