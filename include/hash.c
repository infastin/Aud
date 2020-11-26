#include "hash.h"

unsigned int HashRot13(char* str) {
	unsigned int hash = 0;
	for (; *str; str++) {
		hash += (unsigned char)(*str);
		hash -= (hash << 13) | (hash >> 19);
	}

	return hash;
}

unsigned int UnHashRot13Helper(unsigned int hash, unsigned int goal, int **output, int size, int index) {
	if (index == size-1) {
		for (int i = 65; i <= 122; i++) {
			int temp = hash;
			hash += i;
			hash -= (hash << 13) | (hash >> 19);

			if (hash == goal) {
				(*output)[index] = i;
				return 1;
			} else {
				hash = temp;
			}
		}

		return 0;
	} else {
		int oindex = index++;
		for (int i = 65; i <= 122; i++) {
			int temp = hash;
			hash += i;
			hash -= (hash << 13) | (hash >> 19);
			
			if (UnHashRot13Helper(hash, goal, output, size, index) == 1) {
				(*output)[oindex] = i;
				return 1;
			} else {
				hash = temp;
			}
		}

		return 0;
	}
}

unsigned int UnHashRot13(unsigned int goal, int **output, int size) {
	int hash = 0;
	
	for (int i = 65; i <= 122; i++) {
		hash += i;
		hash -= (hash << 13) | (hash >> 19);
		
		if (UnHashRot13Helper(hash, goal, output, size, 1) == 1) {
			(*output)[0] = i;
			return 1;
		} else {
			hash = 0;
		}
	}

	return 0;
}
