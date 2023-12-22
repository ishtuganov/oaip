#include <stdio.h>
#include <Windows.h>

void F2(int n) {
	if (n < 5) {
		printf("%d\n", n);
		F1(n + 1);
		F1(n + 3);
	}
}

void main() {
	F2(1);
}