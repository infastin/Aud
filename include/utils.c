#include "utils.h"

int IsAlpha(wchar_t alpha) {
	if ((alpha >= L'A' && alpha <= L'Z') || (alpha >= L'a' && alpha <= 'z') || (alpha >= L'А' && alpha <= L'я')) {
		return 1;
	} else {
		return 0;
	}
}

int FindWChar(wchar_t *mass, int size, wchar_t wc) {
	for (int mi = 0; mi < size && mass[mi] != '\0'; ++mi) {
		if (mass[mi] == wc) {
			return mi;
		}
	}

	return -1;
}
