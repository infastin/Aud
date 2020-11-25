#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "vector.h"
#include "utils.h"

void task1(void);
void task2(void);
void task3(void);
void task4(void);

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	
	// srand((unsigned int) time(0));
	// task1();
	// task2();
	// task3();

	// task4();

	printf("\n");

	return 0;
}

void task1(void) {
	int even = 0, odd = 0;
	for (int i = 0; i < 1000000; i++) {
		if (rand() % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	}

	printf("Четных: %d\n", even);
	printf("Нечетных: %d\n", odd);
}

void task2(void) {
	int mass[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; i < 1000000; i++) {
		int random = rand() % 10;

		if (random >= 2) {
			mass[random-2]++;
		}
	}

	for (int i = 0; i < 8; ++i) {
		printf("%d: %d\n", i+2, mass[i]);
	}
}

void task3(void) {
	int even = 0, odd = 0;
	time_t start,
			end;

	time(&start);
	
	do {
		if (rand() % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	
		time(&end);
	} while (difftime(end, start) < 5);

	printf("Четных: %d\n", even);
	printf("Нечетных: %d\n", odd);
}

void task4(void) {
	wchar_t *str1 = CreateWCharVector(),
		 	*str2 = CreateWCharVector(),
		 	c;

	int count1, count2, badInput;

	printf("Введите первую строку: ");
	do {
		while ((c = getwchar()) != L'\n') {
			if (IsAlpha(c)) {
				WCharVectorPush(&str1, c);
			}
		}

		if ((count1 = VectorGetCount(str1)) == 0) {
			badInput = 1;
			printf("Не было введено ни одной буквы! Введите первую строку заново: ");
		} else {
			badInput = 0;
		}
	} while (badInput);


	printf("Введите вторую строку: ");
	do {
		while ((c = getwchar()) != L'\n') {
			if (IsAlpha(c)) {
				WCharVectorPush(&str2, c);
			}
		}

		if ((count2 = VectorGetCount(str2)) == 0) {
			badInput = 1;
			printf("Не было введено ни одной буквы! Введите вторую строку заново: ");
		} else {
			badInput = 0;
		}
	} while (badInput);

	if (VectorGetCount(str1) > 0 && VectorGetCount(str2) > 0) {
		int canBe = 0;
		for (int i = 0; i < VectorGetCount(str2); i++) {
			for (int j = 0; j < VectorGetCount(str1); j++) {
				if (str2[i] == str1[j]) {
					canBe = 1;
					str1[j] = L'\0';
					break;
				} else {
					canBe = 0;
				}
			}

			if (!canBe) break;
		}

		if (canBe) {
			printf("Из букв первой строки можно составить вторую строку\n");
		} else {
			printf("Из букв первой строки нельзя составить вторую строку\n");
		}
	} else {
		printf("Произошла ошибка при вводе строк! Перезапустите программу!\n");
	}

	FreeWCharVector(str1);
	FreeWCharVector(str2);
}
