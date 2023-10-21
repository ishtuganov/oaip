#include <stdio.h>

void task5() {
	int n;
	int a;
	int num = 0;
	int i = 1;
	printf("N = ");
	scanf_s("%d", &n);
	printf("A = ");
	scanf_s("%d", &a);
	do {
		num += a;
		printf("%d ", num);
		i++;
	} while (i <= n);
}