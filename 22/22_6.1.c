#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <Windows.h>


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char s[80];
	printf("Введите строку:");
	fgets(s, 79, stdin);
	printf("\nВы ввели строку = \"%s\"", s);
	int cnt = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i])) s[i] = '$';
	}
	printf("\nСтрока после обработки= \"%s\"", s);

}