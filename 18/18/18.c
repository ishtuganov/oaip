#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void task1() {
	printf("������ 1\n");
	printf("������� �����: ");
	int a, b, c;
	int p;
	scanf("%d%d%d", &a, &b, &c);
	printf("�����: %d, %d, %d\n", a, b, c);
	p = a * b * c;
	printf("p =  %d\n", p);
}

void task2() {
	printf("������ 2\n");
	printf("������� �����: ");
	int a, b, c;
	int p;
	scanf("%d%d%d", &a, &b, &c);
	printf("�����: %d, %d, %d\n", a, b, c);
	FILE* fin = fopen("D:\\����������������\\AiP\\18\\test.txt", "wt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fprintf(fin, "%d", a*b*c);
	fclose(fin);
	printf("��������� %d �������� � ����", a*b*c);
}

void task3() {
	printf("������ 3\n");
	printf("������� �����: ");
	int a, b, c, d, e;
	int p;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("�����: %d, %d, %d, %d, % d\n", a, b, c, d, e);
	p = a + b + c + d + e;
	printf("����� ����� = %d", p);
}

void task4() {
	printf("������ 4\n");
	int a, b, c, d, e;
	FILE* fFrom = fopen("D:\\����������������\\AiP\\18\\in4.txt", "rt");
	if (fFrom == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fFrom, "%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("�����: %d, %d, %d, %d, %d\n", a, b, c, d, e);
	
	FILE* fTo = fopen("D:\\����������������\\AiP\\18\\out4.txt", "wt");
	if (fFrom == NULL) {
		printf("�������� ���� �� ������");
		return;
	}
	fprintf(fTo, "%d", a + b + c + d + e);
	fclose(fFrom);
	fclose(fTo);
	printf("��������� %d �������� � ����", a + b + c + d + e);
}

void task5() {
	printf("������ 5\n");
	FILE* fFrom = fopen("D:\\����������������\\AiP\\18\\in5.txt", "rt");
	if (fFrom == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	int n;
	fscanf(fFrom, "%d", &n);
	int a[10];
	for (int i = 0; i < n; i++) {
		fscanf(fFrom, "%d", &a[i]);
	}

	FILE* fTo = fopen("D:\\����������������\\AiP\\18\\out5.txt", "wt");
	if (fFrom == NULL) {
		printf("�������� ���� �� ������");
		return;
	}
	fprintf(fTo, "%d", a + b + c + d + e);
	fclose(fFrom);
	fclose(fTo);
	printf("��������� %d �������� � ����", a + b + c + d + e);
}



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("��������� ������\n");
	task3();
}




// 