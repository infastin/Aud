#include "intlist.h"

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
			*list = MergeIntLists(lower, *list);
		}

		if (bigger->count >= 1) {
			SortIntList(&bigger);
			*list = MergeIntLists(*list, bigger);
		}

		FreeIntList(lower);
		FreeIntList(bigger);
	}
}
