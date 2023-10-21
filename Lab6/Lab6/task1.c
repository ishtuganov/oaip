#include <stdio.h>

void task1() {
	int n;
	int i = 1;
	printf("n = ");
	scanf_s("%d", &n);
	do {
		printf("%d ", i);
		i++;
	} while (i <= n);
}