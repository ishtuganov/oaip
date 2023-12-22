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
    printf("������� n");
    scanf_s("%d", &n);
    printf("������� m");
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
        printf("�������� ���� �� ��������");
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
        printf("������� ���� �� ������");
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
        printf("���������� �������:");
        print();
        printf("1: ��������� ����������� i*10+j\n");
        printf("2: ��������� ������\n");
        printf("3: ��������� ���������� ����������\n");
        printf("4: ��� �������� ��������� � 10 ���\n");
        printf("5: ��� ������� 10 ��������� � 10 ���\n");
        printf("6: ���� � ����������\n");
        printf("7: ���������� �������\n");
        printf("8: �������� �������\n");
        printf("9: ������� �������� ������ �������\n");
        printf("10: �������������� �������\n");

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
            printf("����� ������, ������� ����� �������: ");
            scanf_s("%d", &num);
            deleteRow(num);
            break;
        }
        case 10: {
            printf("����� ������� �������������� ");
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