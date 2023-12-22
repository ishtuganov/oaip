#include <stdio.h>
#include <Windows.h>

void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}

void main() {
	recEGE1(3);
}
