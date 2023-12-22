#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <Windows.h> 

#define MAX_N 8 
#define MAX_M 10 



int arr[MAX_N][MAX_M] = {
 { 0,  1,  2,  3},
 {4, 5, 6, 7},
 {8, 9, 10, 11}
};
int n = 3;
int m = 4;

void print() {
    printf("!!!! print() !!!!\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

void fillIx10() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = i * 10 + j;
        }

    }
}
void fillZero() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = 0;
        }

    }
}
void randFill0_9() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % 10;
        }
    }
}
void increaseOddBy10() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 2 != 0) {
                arr[i][j] = arr[i][j] * 10;
            }
        }
    }
}
void ReduceallMultiplesof10by10() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] % 10 == 0) {
                arr[i][j] = arr[i][j] / 10;
            }
        }
    }
}
void KeyboardInput() {
    int val;
    printf("введите n");
    scanf_s("%d", &n);
    printf("введите m");
    scanf_s("%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf_s("%d", &val);
            arr[i][j] = val;
        }
    }
}
void save() {
    FILE* fout = fopen("out.txt", "wt");
    if (fout == NULL) {
        printf("Выходной файл не создался");
        return;
    }

    fprintf(fout, "%d ", n);
    fprintf(fout, "%d\n", m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(fout, "%d ", arr[i][j]);
        }
        fprintf(fout, "\n");
    }

    fclose(fout);
}
void load() {

    FILE* fin = fopen("in.txt", "rt");
    if (fin == NULL) {
        printf("Входной файл не найден");
        return;
    }

    fscanf(fin, "%d", &n);
    fscanf(fin, "%d", &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(fin, "%d", &arr[i][j]);
        }
    }
    fclose(fin);
}
void deleteRow(int delRow) {
    printf("!!!! deleteRow(%d) !!!!\n", delRow);
    for (int i = delRow; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    n--;
}
void addColumn(int ins) {
    if (m < MAX_M) {
        m++;
        for (int i = 0; i < n; i++) {
            for (int j = m; j > ins; j--) {
                arr[i][j] = arr[i][j - 1];
            }
        }

    }

}
void a5() {
    int i1, j1;
    int max = arr[1][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                i1 = i;
                j1 = j;
            }
        }
    }
    for (int i = i1; i < m; i++) {
        if (arr[i][j1] % 2 == 0) {

            arr[i][j1] = max;
        }
    }
    printf("\n%d %d %d", max, i1, j1);
}


void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0;
    do
    {
        printf("------------------------------\n");
        printf("Содержимое массива:");
        print();
        printf("1: заполнить значаениями i*10+j\n");
        printf("2: заполнить нулями\n");
        printf("3: заполнить случайными значениями\n");
        printf("4: все нечетные увеличить в 10 раз\n");
        printf("5: все кратные 10 уменьшить в 10 раз\n");
        printf("6: ввод с клавиатуры\n");
        printf("7: сохранение массива\n");
        printf("8: загрузка массива\n");
        printf("9: удалить заданную строку массива\n");
        printf("10: продублировать столбец\n");

        scanf_s("%d", &n);
        switch (n)
        {
        case 1: {
            fillIx10();
            break;
        }
        case 2: {
            fillZero();
            break;
        }
        case 3: {
            randFill0_9();
            break;
        }
        case 4: {
            increaseOddBy10();
            break;
        }
        case 5: {
            ReduceallMultiplesof10by10();
            break;
        }
        case 6: {
            KeyboardInput();
            break;
        }
        case 7: {
            save();
            break;
        }
        case 8: {
            load();
            break;
        }
        case 9: {
            int num;
            printf("Номер строки, которую нужно удалить: ");
            scanf_s("%d", &num);
            deleteRow(num);
            break;
        }
        case 10: {
            printf("какой столбец продублировать ");
            int num;
            scanf_s("%d", &num);
            addColumn(num);
            break;
        }
        default:
            break;
        }

    } while (n != 0);
}