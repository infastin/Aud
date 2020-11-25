#include "str.h"
#include <stdlib.h>

DeclareVector(String, char*, Pointer)

int StringLength(const char *string) {
	if (string != NULL) {
		int i;
		for (i = 0; string[i] != '\0'; i++);
		return i;
	} else {
		return 0;
	}
}

int **FindString(const char *string, const char *find) {
	if (StringLength(string) > 0) {
		int **output = CreateIntPVector();

		int start = 0, end = 0, entryFound = 0;
		for (int si = 0, fi = 0; ; si++) {
			if (string[si] == find[fi] && string[si] != '\0') {
				if (!entryFound) {
					entryFound = 1;
					start = si;
				}

				fi++;
			} else {
				if (find[fi] == '\0' && entryFound) {
					end = si-1;

					int *found = (int*)calloc(sizeof(int), 2);
					found[0] = start;
					found[1] = end;

					IntPVectorPush(&output, found);
				}

				entryFound = 0;
				fi = 0;
			}

			if (string[si] == '\0') break;
		}

		return output;
	} else {
		return NULL;
	}
}

int CountString(const char *string, const char *find) {
	if (StringLength(string) > 0) {
		int entryFound = 0, count = 0;
		for (int si = 0, fi = 0; ; si++) {
			if (string[si] == find[fi] && string[si] != '\0') {
				entryFound = 1;
				fi++;
			} else {
				if (find[fi] == '\0' && entryFound) {
					count++;
				}

				entryFound = 0;
				fi = 0;
			}

			if (string[si] == '\0') break;
		}

		return count;
	} else {
		return 0;
	}
}

char *ReplaceString(const char *string, const char *find, const char *replace) {
	int stringlen = StringLength(string);

	if (stringlen > 0) {
		int findlen = StringLength(find),
			replacelen = StringLength(replace),
			count = CountString(string, find),
			outputlen = stringlen - (count * (findlen - replacelen)),
			entryFound = 0;

		char *output;

		if (stringlen > outputlen) {
			output = (char*)calloc(sizeof(char), stringlen);
		} else {
			output = (char*)calloc(sizeof(char), outputlen);
		}
			
		for (int si = 0, oi = 0, fi = 0; ; oi++, si++) {
			if (string[si] == find[fi] && si != stringlen) {
				if (!entryFound) {
					entryFound = 1;
				}

				fi++;
			} else {
				if (find[fi] == '\0') {
					oi -= findlen;

					for (int ri = 0; ri < replacelen; ri++, oi++) {
						output[oi] = replace[ri];
					}

					if (si == stringlen) {
						for (int ri = replacelen; ri < findlen; ri++, oi++) {
							output[oi] = '\0';
						}
					}
				}

				entryFound = 0;
				fi = 0;
			}
			
			if (si == stringlen) break;

			output[oi] = string[si];
		}

		if (stringlen != outputlen) {
			output = (char*)realloc(output, outputlen);
		}

		return output;
	} else {
		return NULL;
	}
}

char **SplitString(const char *string, char delimiter) {
	int stringlen = StringLength(string);

	if (stringlen > 0) {
		int startInput = 0;
		char **output = CreateStringVector(),
			 *entry;

		if (output == NULL) {
			return NULL;
		}

		for (int i = 0; ; ++i) {
			if (!startInput && i != stringlen) {
				entry = CreateCharVector();

				if (entry == NULL) {
					return NULL;
				}

				startInput = 1;
			}

			if (string[i] == delimiter || (i == stringlen && startInput)) {
				CharVectorPush(&entry, '\0');
				StringVectorPush(&output, entry);
				startInput = 0;
			} else {
				CharVectorPush(&entry, string[i]);
			}

			if (i == stringlen) break;
		}

		return output;
	} else {
		return NULL;
	}
}
