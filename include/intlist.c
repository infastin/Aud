#include "intlist.h"
#include <stdio.h>

DeclareList(Int, int)
DeclareList(IntP, int*)

void SortIntList(IntList **list) {
	if ((*list)->count > 1) {
		int base = (*list)->first->value;
		IntList *bigger = CreateIntList();
		IntList *lower = CreateIntList();

		list_foreach(Int, *list, curr) {
			if (curr != (*list)->first) {
				if (curr->value >= base) {
					IntListAppend(bigger, curr->value);
				} else {
					IntListAppend(lower, curr->value);
				}
			}
		}

		ClearIntList(*list);
		IntListAppend(*list, base);

		if (lower->count >= 1) {
			SortIntList(&lower);
			PMergeBeforeIntLists(list, lower);
		}	

		if (bigger->count >= 1) {
			SortIntList(&bigger);
			PMergeIntLists(list, bigger);
		}

		FreeIntList(lower);
		FreeIntList(bigger);
	}
}

void RSortIntList(IntList **list) {
	if ((*list)->count > 1) {
		int base = (*list)->first->value;
		IntList *bigger = CreateIntList();
		IntList *lower = CreateIntList();

		list_foreach(Int, *list, curr) {
			if (curr != (*list)->first) {
				if (curr->value >= base) {
					IntListAppend(bigger, curr->value);
				} else {
					IntListAppend(lower, curr->value);
				}
			}
		}

		ClearIntList(*list);
		IntListAppend(*list, base);

		if (lower->count >= 1) {
			RSortIntList(&lower);
			PMergeIntLists(list, lower);
		}	

		if (bigger->count >= 1) {
			RSortIntList(&bigger);
			PMergeBeforeIntLists(list, bigger);
		}

		FreeIntList(lower);
		FreeIntList(bigger);
	}

}
