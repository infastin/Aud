#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "include/intlist.h"

IntList *func1(int numb);
IntList *func2(int numb);
int func3(int numb);
int func4(int numb);

void task1(void);

int main(void)
{
	task1();
	return 0;
}

IntList *func1(int numb) {
	IntList *result = CreateIntList();
	int i;
	while (numb > 1) {
		for (i = 9; i > 0; i--) {
			if (numb % i == 0) {
				numb /= i;
				IntListAppend(result, i);
				break;
			}
		}

		if (i == 1 && numb > 9) {
			return NULL;
		}
	}

	int temp = 0;
	ReverseIntList(&result);
	list_foreach(Int, result, curr) {
		if (temp < (INT_MAX / 10)) {
			temp *= 10;
			if (temp < (INT_MAX - curr->value)) {
				temp += curr->value;
			} else {
				return NULL;
			}
		} else {
			return NULL;
		}
	}

	return result;
}

IntList *func2(int numb) {

}


void task1(void) {
	int n, nScan, nScanned = 0;

	printf("Введите целое положительное число: ");
	while(1) {
		nScan = scanf("%d", &n);
		while(getchar() != '\n');
		if (nScan == EOF || nScan != 1 || n < 0) {
			if (n <= 0) {
				printf("\nЧисло не может быть отрицательным!\n");
			} else {
				printf("\nБыло введено не число!\n");
			}

			printf("Заново введите число точек: ");
		} else {
			nScanned = 1;
			break;
		}
	}

	if (nScanned) {
		IntList *result1 = func1(n);

		list_foreach(Int, result1, curr) {
			printf("%d", curr->value);
		}
	} else {
		printf("\nПроизошла ошибка при записи количества точек. Перезапустите программу.");
	}
}
