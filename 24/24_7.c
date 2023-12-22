#include <stdio.h>
#include <Windows.h>

void F3(int n) {
	if (n > 0) {
		G3(n - 1);
	}
}

void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}

void main() {
	F3(11);
}