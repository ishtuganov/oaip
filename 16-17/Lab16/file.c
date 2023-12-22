#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
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
	printf("%d элементов больше 10\n", count);
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

void Read() {
	FILE* fin = fopen("in1.txt", "rt");
	if (fin == NULL) {
		printf("not opened\n");
		return;
	}
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &arr[i]);
	}
	fclose(fin);
}

void Save() {
	FILE* fout;
	fout = fopen("out1.txt", "wt");
	if (fout == NULL) {
		printf("not opened\n");
		return;
	}
	fprintf(fout, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", arr[i]);
	}
	fclose(fout);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: сколько элементов > 10\n");
		printf("5: x2 для последнего четного\n");
		printf("6: Сколько четных левее минимального\n");
		printf("7: Все четные элементы умножить на -1\n");
		printf("8: Заменить все элементы меньшие 4 на 4\n");
		printf("9: Удалить заданный элемент\n");
		printf("10: Вставить новый элемент\n");
		printf("11: Удалить минимальный элемент\n");
		printf("12: Перед минимальным элементом вставить 0\n");
		printf("15: ввести массив из файла\n");
		printf("16: сохранить массив в файл\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

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
			printf("Индекс минимального элемента равен %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) cnt++;
			}
			printf("левее минимального %d четных элементов\n", cnt);
		}
		break;
		case 7:
			makeEvenELementsNegative();
			break;
		case 8:
			replaceElementsLess4();
			break;
		case 9:
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
			break;
		case 10:
			printf("перед каким индексом вставить элемент?: ");
			int ind;
			scanf_s("%d", &ind);
			printf("какое значение вставить?: ");
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
		case 15:
			Read();
			break;
		case 16:
			Save();
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
