#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include "vector.h"

void task1(void);

int main(void)
{
	task1();
	return 0;
}

int func1(int numb) {
	int *temp = CreateIntVector();
	int i;
	if (numb == 1) IntVectorPush(&temp, 1);
	while (numb > 1) {
		for (i = 9; i > 0; i--) {
			if (numb % i == 0) {
				numb /= i;
				IntVectorPush(&temp, i);
				break;
			}
		}

		if (i == 1 && numb > 9) {
			return -1;
		}
	}

	int result = 0;
	ReverseIntVector(&temp);
	for (int i = 0; i < VectorGetCount(temp); ++i) {
		if (result <= (INT_MAX / 10)) {
			result *= 10;
			if (result <= (INT_MAX - temp[i])) {
				result += temp[i];
			} else {
				return -1;
			}
		} else {
			return -1;
		}
	}

	FreeVector(temp);
	return result;
}

voi

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
		int r1 = func1(n);

		printf("%d\n", r1);
	} else {
		printf("\nПроизошла ошибка при записи количества точек. Перезапустите программу.");
	}
}
