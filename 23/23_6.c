#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>



#define MAX_LEN 100
char s[MAX_LEN];



void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("��������� ������\n");
	printf("��23 ������ 6\n");
	// ������� ����
	FILE* fin = fopen("in6.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}

	// �������� ����
	FILE* fout;
	fout = fopen("out6.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
		return;
	}
	// � ����� ��� ���� �����
	while (!feof(fin)) {
		// ��������� ������
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			int n = 0;
			for (int i = 0; s[i] != '\0'; i++) {
				if (s[i] == ';') {
					n++;
				}
			}
			char str[10];
			snprintf(str, sizeof str, "%d", n);
			strcat(s, str);
			fprintf(fout, "%s", s);
			printf(">>%s<<\n", s);
		}
	}
	fclose(fin);
	fclose(fout);
	printf("��23 ������ 6 FINISH\n");
}
