#include <stdio.h>

void task6() {
	printf("N = ");
	int n;
	int i = 1;
	scanf_s("%d", &n);
	do {
		printf("%d%d ", i, i);
		i++;
	} while (i <= n);
}