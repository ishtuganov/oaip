#include <stdio.h>
#include <Windows.h>

void Task1() {
	printf("Task1() start\n");
	int n;
	int m;
	printf("введите N (< 10) = ");
	scanf_s("%d", &n);

	printf("введите M (< 10) = ");
	scanf_s("%d", &m);

	int i = 1;
	do
	{
		int j = 1;
		do
		{
			printf("%d%d ", i, j);
			j++;
		} while (j <= m);

		printf("\n");
		i++;
	} while (i <= n);
	printf("Task1() finish\n");
}

void Task2() {
	printf("Task2() start\n");
	int start = 1;
	int curr = start;
	int end = start * 10;
	do {
		do {
			printf("%d\t", curr);
			curr += start;
		} while (curr < end);
		start++;
		curr = start;
		end = start * 10;
		printf("\n");
	} while (start <= 10);
	printf("Task2() finish\n");
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		printf("\n");
		printf("\n");
		printf("Выберите нужную вам опцию\n");
		printf("1. Задача 1\n");
		printf("2. Задача 2\n");
		printf("\n");
		printf("0. выйти из программы\n");

		int num;
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 0:
			return;
		}
	} while (TRUE);
}