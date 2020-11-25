#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(int argc, char *argv[]) 
{
	FILE *in = fopen("crypted.txt", "r");

	if (in != NULL) {
		char c;
		int *input = (int*)calloc(sizeof(int), 3),
			*output = (int*)calloc(sizeof(int), 5),
			isNeg = 0, newLine = 1, i = 0, err = 0;
		unsigned int *goal = (unsigned int*)calloc(sizeof(int), 3);

		while(1) {
			c = fgetc(in);

			if ((c >= '0' && c <= '9') || (c == '-' && newLine) || c == '\n' || feof(in)) {
				if (c == '-') {
					isNeg = 1;
					newLine = 0;
				} else if (c == '\n') {
					if (isNeg) {
						input[i] *= -1;
					}

					goal[i] = (unsigned int) input[i];

					newLine = 1;
					i++;
				} else {
					input[i] = (input[i] * 10) + (c - 48);
				}
			} else {
				err = 1;
				break;
			}

			if (feof(in) || ferror(in)) break;
		}

		free(input);
		fclose(in);

		if (!err) {
			for (int i = 0; i < 3; ++i) {
				UnHashRot13(0, goal[i], &output, 5);

				printf("%d: ", goal[i]);
				for (int i = 0; i < 5; ++i) {
					printf("%c", output[i]);
				}
				printf("\n");
			}
		} else {
			printf("Файл содержит не только числа!\n");
		}

		free(output);
	} else {
		fprintf(stderr, "%s\n", strerror(errno));
	}
}
