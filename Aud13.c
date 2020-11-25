#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include "str.h"
#include "utils.h"
#include "vector.h"

void task1(void);
void task2(void);
void task3(void);
void task4(void);

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	// task1();
	// task2();
	// task3();
	// task4();

	return 0;
}

void task1(void) {
	// ввести 1234567890
	
	char str[10];
	fgets(str, 10, stdin);

	// Решил
	while(fgetc(stdin) != '\n' || feof(stdin) || ferror(stdin));

	puts(str);

	int h = 99;
	printf("before %d\n", h);
	scanf("%d", &h);
	printf("after %d\n", h);
}

void task2(void) {
	char string[] = "Something  cool  maybe  ";
	char *replaced = ReplaceString(string, "  ", "");

	printf("%s\n", replaced);
	free(replaced);
}

void task3(void) {
	wchar_t string[] = L"Это исходный текст.";

	wchar_t *chars = CreateWCharVector();
	int *count = CreateIntVector(),
		amount = 0;

	for (int si = 0, fi = 0; string[si] != L'\0'; si++) {
		fi = FindWChar(chars, amount, string[si]);

		if (fi == -1) {
			WCharVectorPush(&chars, string[si]);
			IntVectorPush(&count, 1);
			amount++;
		} else {
			count[fi]++;
		}
	}

	wprintf(L"Символы этого текста: \n");
	for (int i = 0; i < amount; i++) {
		wprintf(L"%lc", chars[i]);
		if (i != (amount - 1)) {
			wprintf(L",");
		}
	}

	FreeWCharVector(chars);

	wprintf(L"\nЧастота вхождения этих символов: \n");
	for (int i = 0; i < amount; i++) {
		wprintf(L"%d", count[i]);
		if (i != amount - 1) {
			wprintf(L" ");
		}
	}
	
	FreeIntVector(count);
}

void task4(void) {	
	char months[] = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
	char **tokens = SplitString(months, ',');
	int count = VectorGetCount(tokens);

	if (tokens != NULL) {
		for (int i = 0; i < count; i=i+1) {
			printf("month=[%s]\n", tokens[i]);
			VFreeStringVectorValue(tokens, i);
		}

		VFreeStringVector(tokens);
		printf("\n");
	}
}
