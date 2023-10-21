#include <stdio.h>

void task4() {
	int n;
	int i = 2;
	printf("n = ");
	scanf_s("%d", &n);
	do {
		printf("%d ", i);
		i += 2;
	} while (i <= 2 * n);
}