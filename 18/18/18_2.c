#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include "stdio.h"
#include "Windows.h"

//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//  printf("Задача 2\n");
//	int a, b, c;
//	FILE* fin = fopen("in2.txt", "rt");
//	if (fin == NULL) {
//		printf("Входной файл не найден");
//		return;
//	}
//	fscanf(fin, "%d%d%d", &a, &b, &c);
//	fclose(fin);
//	printf("Числа: %d, %d, %d\n", a, b, c);
//	printf("p = %d", a * b * c);
//	FILE* fout = fopen("out2.txt", "wt");
//	if (fout == NULL) {
//		printf("Выходной файл не найден");
//		return;
//	}
//	fprintf(fout, "%d", a * b * c);
//	fclose(fout);
//
//}