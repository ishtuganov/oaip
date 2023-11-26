#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void task1() {
	printf("Задача 1\n");
	printf("введите числа: ");
	int a, b, c;
	int p;
	scanf("%d%d%d", &a, &b, &c);
	printf("ввели: %d, %d, %d\n", a, b, c);
	p = a * b * c;
	printf("p =  %d\n", p);
}

void task2() {
	printf("Задача 2\n");
	printf("введите числа: ");
	int a, b, c;
	int p;
	scanf("%d%d%d", &a, &b, &c);
	printf("ввели: %d, %d, %d\n", a, b, c);
	FILE* fin = fopen("D:\\программирование\\AiP\\18\\test.txt", "wt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fprintf(fin, "%d", a*b*c);
	fclose(fin);
	printf("результат %d сохранен в файл", a*b*c);
}

void task3() {
	printf("Задача 3\n");
	printf("введите числа: ");
	int a, b, c, d, e;
	int p;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("ввели: %d, %d, %d, %d, % d\n", a, b, c, d, e);
	p = a + b + c + d + e;
	printf("Сумма равна = %d", p);
}

void task4() {
	printf("Задача 4\n");
	int a, b, c, d, e;
	FILE* fFrom = fopen("D:\\программирование\\AiP\\18\\in4.txt", "rt");
	if (fFrom == NULL) {
		printf("Входной файл не найден");
		return;
	}
	fscanf(fFrom, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("числа: %d, %d, %d, %d, %d\n", a, b, c, d, e);
	
	FILE* fTo = fopen("D:\\программирование\\AiP\\18\\out4.txt", "wt");
	if (fFrom == NULL) {
		printf("Выходной файл не найден");
		return;
	}
	fprintf(fTo, "%d", a + b + c + d + e);
	fclose(fFrom);
	fclose(fTo);
	printf("результат %d сохранен в файл", a + b + c + d + e);
}

void task5() {
	printf("Задача 5\n");
	FILE* fFrom = fopen("D:\\программирование\\AiP\\18\\in5.txt", "rt");
	if (fFrom == NULL) {
		printf("Входной файл не найден");
		return;
	}
	int n;
	fscanf(fFrom, "%d", &n);
	int a[10];
	for (int i = 0; i < n; i++) {
		fscanf(fFrom, "%d", &a[i]);
	}

	FILE* fTo = fopen("D:\\программирование\\AiP\\18\\out5.txt", "wt");
	if (fFrom == NULL) {
		printf("Выходной файл не найден");
		return;
	}
	fprintf(fTo, "%d", a + b + c + d + e);
	fclose(fFrom);
	fclose(fTo);
	printf("результат %d сохранен в файл", a + b + c + d + e);
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Иштуганов Азамат\n");
	task3();
}




// 