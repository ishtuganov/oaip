#include <stdio.h>

void task2() {
	int i = 0;
	int pow = 1;
	do {
		printf("2^%d = %d\n", i, pow);
		i++;
		pow *= 2;
	} while (i <= 5);
}