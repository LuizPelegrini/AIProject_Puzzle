#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"

int main() {
	int found;
	
	CreateQueue();
	CreateHashTable();
	CreateFirstState();
	
	clock_t start = clock();
	do {
		found = Pop();
	} while (found !=0 && found!=1);
	clock_t end = clock();

	if (found == 0) {
		printf("%s\n", "I am sorry, I could not find a reasonable result for you.");
	}
	else if (found == 1) {
		printf("\n\n%s\n\n", " >>>>>>> The actions must be followed FROM THE BOTTOM TO THE TOP!!! <<<<<<");
		printf("%s\n", "The actions needed to find the result is stated above.");
		printf("\n\nSpent time: %.4f\n\n", (float)(end - start) / CLOCKS_PER_SEC);
	}

	system("PAUSE");

	return 0;
}