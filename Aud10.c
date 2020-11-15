#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "include/intlist.h"

void task1(void);
void task2(void);
void task3(void);
void task4(void);

int main(void) {
	// task1();
	// task2();
	// task3();
	// task4();

	printf("\n");

	return 0;
}

void task1(void) {
	int n, nScan, nScanned = 0;

	printf("Введите количество точек: ");
	while(1) {
		nScan = scanf("%d", &n);
		while(getchar() != '\n');
		if (nScan == EOF || nScan != 1 || n <= 0) {
			if (n <= 0) {
				printf("\nКоличество не может быть отрицательным или равным нулю!\n");
			} else {
				printf("\nБыло введено не число!\n");
			}

			printf("Заново введите количество точек: ");
		} else {
			nScanned = 1;
			break;
		}
	}

	if (nScanned) {
		IntPList *list = CreateIntPList();
		int x, y, xyScan, xyScanned = 0, success = 1;

		for (int i = 0; i < n; i++) {
			printf("Введите координаты точки n%d (x, y): ", i);
			while(1) {
				xyScan = scanf("%d, %d", &x, &y);
				while(getchar() != '\n');
				if (xyScan == EOF || xyScan != 2) {
					printf("\nКоординаты были введены неверно! Следуйте формату (x, y) и вводите целые числа!\n");
					printf("Введите координаты точки n%d (x, y) заново: ", i);
				} else {
					xyScanned = 1;
					break;
				}
			}

			if (xyScanned) {
				if (y >= 0) {
					int *xy = malloc(sizeof(int) * 3);
					xy[0] = i;
					xy[1] = x;
					xy[2] = y;

					IntPListAppend(list, xy);
				}
			} else {
				success = 0;
				break;
			}
		}

		if (success) {
			int count = list->count;
			int **listValues = PopIntPList(list);
			FreeIntPList(list);
			
			for (int i = 0; i < count; i++) {
				printf("n%d: %d, %d\n", ((int**)listValues)[i][0], ((int**)listValues)[i][1], ((int**)listValues)[i][2]);
				free(listValues[i]);
			}

			free(listValues);
		} else {
			printf("\nПроизошла ошибка при записи координат точки. Перезапустите программу.");
		}
	} else {
		printf("\nПроизошла ошибка при записи количества точек. Перезапустите программу.");
	}
}

void task2(void) {
	int n, nScan, nScanned = 0;

	printf("Введите количество чисел: ");
	while(1) {
		nScan = scanf("%d", &n);
		while(getchar() != '\n');
		if (nScan == EOF || nScan != 1 || n <= 0) {
			if (n <= 0) {
				printf("\nКоличество не может быть отрицательным!\n");
			} else {
				printf("\nБыло введено не число!\n");
			}

			printf("Заново введите количество чисел: ");
		} else {
			nScanned = 1;
			break;
		}
	}

	if (nScanned) {
		IntList *odd = CreateIntList(),
			 	*even = CreateIntList();
		int number, numberScan, numberScanned = 0, success = 1;

		for (int i = 0; i < n; i++) {
			printf("Введите целое число: ");
			while (1) {
				numberScan = scanf("%d", &number);
				while(getchar() != '\n');

				if (numberScan == EOF || numberScan != 1) {
					printf("\nБыло введено не целое число!\n");
					printf("Введите целое число заново: ");
				} else {
					numberScanned = 1;
					break;
				}
			}

			if (numberScanned) {
				if (number % 2 == 0) {
					IntListAppend(even, number);
				} else {
					IntListAppend(odd, number);
				}
			} else {
				success = 0;
				break;
			}
		}

		if (success) {
			int evenCount = even->count,
				oddCount = odd->count;

			int *evenValues = PopIntList(even),
				*oddValues = PopIntList(odd);

			FreeIntList(even);
			FreeIntList(odd);

			printf("\nЧетные числа:\n");
			for (int i = 0; i < evenCount; i++) {
				printf(" %d\n", evenValues[i]);
			}

			printf("\nНечетные числа:\n");
			for (int i = 0; i < oddCount; i++) {
				printf(" %d\n", oddValues[i]);
			}

			free(evenValues);
			free(oddValues);
		} else {
			printf("\nПроизошла ошибка при записи целого числа. Перезапустите программу.");
		}
	} else {
		printf("\nПроизошла ошибка при записи количества точек. Перезапустите программу.");
	}
}

void task3(void) {
	int a, b, c, abcScan, abcScanned = 0;

	printf("Введите коэффициенты уравнения прямой (A, B, C): ");
	while(1) {
		abcScan = scanf("%d, %d, %d", &a, &b, &c);
		while(getchar() != '\n');

		if (abcScan == EOF || abcScan != 3 || (a == 0 && b == 0)) {
			if (a == 0 && b == 0) {
				printf("\nКоэффиценты были введены неверно! A и B не должны быть одновременно равны нулю!\n");
			} else {
				printf("\nКоэффиценты были введены неверно! Следуйте формату (A, B, C) и вводите целые числа!\n");
			}

			printf("Введите коэффициенты заново (A, B, C): ");
		} else {
			abcScanned = 1;
			break;
		}
	}

	if (abcScanned) {
		int x, y, xyScan, xyScanned = 0;

		printf("Введите координаты точки (x, y): ");
		while (1) {
			xyScan = scanf("%d, %d", &x, &y);
			while(getchar() != '\n');

			if (xyScan == EOF || xyScan != 2) {
				printf("\nКоординаты были введены неверно! Следуйте формату (x, y) и вводите целые числа!\n");
				printf("Введите координаты заново (x, y): ");
			} else {
				xyScanned = 1;
				break;
			}
		}

		if (xyScanned) {
			char *aStr, *bStr, *cStr;

			if (a != 0) {
				asprintf(&aStr, "%dx ", a);
			} else {
				asprintf(&aStr, "");
			}

			if (b != 0) {
				if (a != 0) {
					char sign;
					if (b > 0) {
						sign = '+';
					} else {
						sign = '-';
					}

					asprintf(&bStr, "%c %dy ", sign, abs(b));
				} else {
					asprintf(&bStr, "%dy ", b);
				}
			} else {
				asprintf(&bStr, "");
			}

			if (c != 0) {	
				char sign;
				if (c > 0) {
					sign = '+';
				} else {
					sign = '-';
				}

				asprintf(&cStr, "%c %d ", sign, abs(c));
			} else {
				asprintf(&cStr, "");
			}

			if ((a*x*x + b*y + c) == 0) {
				printf("\nТочка (%d, %d) лежит на прямой, заданной уравнением %s%s%s= 0", x, y, aStr, bStr, cStr);
			} else {
				printf("\nТочка (%d, %d) не лежит на прямой, заданной уравнением %s%s%s= 0", x, y, aStr, bStr, cStr);
			}
			
			free(aStr);
			free(bStr);
			free(cStr);
		} else {
			printf("\nПроизошла ошибка при записи координат точки. Перезапустите программу.");
		}
	} else {
		printf("\nПроизошла ошибка при записи числа n. Перезапустите программу.");
	}
}

void task4(void) {
	int n, nScan, nScanned = 0;

	printf("Введите количество разрядов: ");
	while(1) {
		nScan = scanf("%d", &n);
		while(getchar() != '\n');
		if (nScan == EOF || nScan != 1 || n <= 0) {
			if (n <= 0) {
				printf("\nКоличество не может быть отрицательным или равным нулю!\n");
			} else {
				printf("Было введено не число!\n");
			}

			printf("Заново введите количество чисел: ");
		} else {
			nScanned = 1;
			break;
		}
	}

	if (nScanned) {
		int c, 
			i = 0, 		// Счетчик введеных 1 и 0
			j = 0, 		// Счетчик количества символов
			err = 0,
			success = 0;
		char *bin = calloc(sizeof(char), n);
		printf("Введите двоичное представление положительного целого числа с %d разрядами: ", n);
		while ((c = getchar()) != EOF) {
			j++;

			if (c == '\n') {
				if (i != n) {
					err = 1;
				} else {
					success = 1;
					break;
				}
			} else if (c != '0' && c != '1') {
				err = 2;
			} else {
				bin[i] = c;
				i++;
			}

			if (err != 0) {
				if (err == 2) {
					while(getchar() != '\n');
					printf("\nБыло введено не двоичное число!\n");
				} else if (err == 1) {
					printf("\nБыло введено двоичное число с %d разрядов вместо %d\n", j-1, n);
				}
		
				j = 0;
				i = 0;
				err = 0;
				printf("Введите двоичное число заново: ");
			}
		}

		if (success) {
			int dec = 0;
			for (int i = 0; i < n; i++) {
				dec = dec*2 + (bin[i]-48);
			}

			printf("Десятичная запись числа %s: %d\n", bin, dec);
		} else {
			printf("\nПроизошла ошибка при записи двоичного числа. Перезапустите программу.");
		}
	} else {
		printf("\nПроизошла ошибка при записи количества разрядов. Перезапустите программу.");
	}
}
