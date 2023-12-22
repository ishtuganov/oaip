#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include "stdio.h"
#include "Windows.h"

//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	int a, b, c, d, e;
//	FILE* fin = fopen("in4.txt", "rt");
//	if (fin == NULL) {
//		printf("Входной файл не найден");
//		return;
//	}
//	fscanf(fin, "%d%d%d%d%d", &a, &b, &c, &d, &e);
//	fclose(fin);
//	printf("Ввод: %d, %d, %d, %d, %d\n", a, b, c, d, e);
//	printf("p = %d", a + b + c + d + e);
//	FILE* fout = fopen("out4.txt", "wt");
//	if (fout == NULL) {
//		printf("Выходной файл не найден");
//		return;
//	}
//	fprintf(fout, "%d", a + b + c + d + e);
//	fclose(fout);
//}