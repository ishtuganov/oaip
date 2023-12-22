#include <stdio.h>
#include <Windows.h>

void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}

void main() {
	F1(10);
}