#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char s[80];
	printf("������� ������:");
	fgets(s, 79, stdin);
	printf("\n�� ����� ������ = \"%s\"", s);
	int cnt = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = toupper(s[i]);
	}
	printf("\n������ ����� ���������= \"%s\"", s);

}