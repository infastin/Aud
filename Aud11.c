#include <stdio.h>
#include <time.h>
#include "include/intlist.h"

int main(void)
{
	IntList *randomList = CreateIntList();
	srand(time(0));

	for (int i = 0; i < 50; i++) {
		int random = rand() % 100;
		IntListAppend(randomList, random);
		printf("%d ", random);
	}

	RSortIntList(&randomList);

	printf("\n");

	list_foreach(Int, randomList, curr) {
		printf("%d ", curr->value);
	}

	return 0;
}
