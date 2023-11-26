#include <stdio.h>
#include <Windows.h>
#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void lastEvenX2() {
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] % 2 == 0) {
			arr[i] *= 2;
			break;
		}
	}
}

void elementsMoreTenCount() {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) count++;
	}
	printf("%d ��������� ������ 10\n", count);
}

void printElements() {
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

void keyboardInput() {
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values: ", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}
void oddsX10() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] *= 10;
		}
	}
}
int findMin() {
	int min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int findIndexMin() {
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < arr[min]) {
			min = i;
		}
	}
	return min;
}

void makeEvenELementsNegative() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) arr[i] *= -1;
	}
}

void replaceElementsLess4() {
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) arr[i] = 4;
	}
}

void deleteElement(int ind) {
	for (int i = ind; i < n - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}
	n--;
}

void insertItem(int index, int value) {
	for (int i = n; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}
	n++;
	arr[index] = value;
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("���������� �������:");
		printElements();
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������ � ���������� ������\n");
		printf("2: x10 ��� ���� �������� ���������\n");
		printf("3: ����� ����������� �������\n");
		printf("4: ������� ��������� > 10\n");
		printf("5: x2 ��� ���������� �������\n");
		printf("6: ������� ������ ����� ������������\n");
		printf("7: ��� ������ �������� �������� �� -1\n");
		printf("8: �������� ��� �������� ������� 4 �� 4\n");
		printf("9: ������� �������� �������\n");
		printf("10: �������� ����� �������\n");
		printf("11: ������� ����������� �������\n");
		printf("12: ����� ����������� ��������� �������� 0\n");
		printf("\n");
		printf("0: ����� �� ���������\n");
		printf("��������� �������� >>>>>> ");

		scanf_s("%d", &item);
		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;
		case 4:
			elementsMoreTenCount();
			break;
		case 5:
			lastEvenX2();
			break;
		case 6:
		{
			int index = findIndexMin();
			printf("������ ������������ �������� ����� %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) cnt++;
			}
			printf("����� ������������ %d ������ ���������\n", cnt);
		}
		break;
		case 7:
			makeEvenELementsNegative();
			break;
		case 8:
			replaceElementsLess4();
			break;
		case 9:
			printf("������ ���������� �������� = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
			break;
		case 10:
			printf("����� ����� �������� �������� �������?: ");
			int ind;
			scanf_s("%d", &ind);
			printf("����� �������� ��������?: ");
			int val;
			scanf_s("%d", &val);
			insertItem(ind, val);
			break;
		case 11:
			ind = findIndexMin();
			deleteElement(ind);
			break;
		case 12:
			ind = findIndexMin();
			insertItem(ind, 0);
			break;
		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;

		}

	} while (item != 0);
}
