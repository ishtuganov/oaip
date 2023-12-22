#include <stdio.h>
#include <Windows.h>

int fact(int n) {
	if (n == 1) return 1;
	return fact(n - 1) * n;
}

void main() {
	int n = 5;
	int res = fact(n);
	printf("%d! = %d", n, res);
}