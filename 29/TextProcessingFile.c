#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <Windows.h>


// ������������ ����� ����� � �������
#define MAX_LEN_WORD 80

int getNextDelim(FILE* fp, char token[]);
int getNextWord(FILE* fp, char token[]);



char filenameDict[] = "C:\\29\\dict0.txt";
//char filenameIn[] = "C:\\29\\Alice.txt";
//char filenameOut[] = "C:\\29\\Alice_out.html";

char filenameIn[] = "C:\\29\\Tolkien.txt";
char filenameOut[] = "C:\\29\\Tolkien_out.html";

void main() {
	// �������� ����� ����� ��������������
	printf("HTML file %s\nis created from text file %s\nwith highlighting words from %s\ndictionary\n\n\n",
		filenameOut, filenameIn, filenameDict);

	// t0 - ������� ������ ������� �� ������ ��������� �� ������� ����� � ������� main()
	long t0 = clock();
	printf("t0 = %.3f sec \n", t0 / (float)CLOCKS_PER_SEC);
	// t1 - ������� ������ ������� �� ������ ��������� �� ��������� �������� �������
	int t1 = clock();
	printf("t1 = %.3f sec \n", t1 / (float)CLOCKS_PER_SEC);

	TextProcessing(filenameIn, filenameOut);

	// t2 - ������� ������ ������� �� ������ ��������� �� ��������� ����������� ������
	long t2 = clock();
	printf("t2 = %.3f sec \n", t2 / (float)CLOCKS_PER_SEC);


	// t3 - ������� ������ ������� �� ��������� ����������� ������ �� ��������� ����������� ������� 
	long t3 = clock();

	printf("t3 = %.3f sec \n", t3 / (float)CLOCKS_PER_SEC);

	printf("t1 - t0 = %.3f sec (Run time of dictionary loading)\n", (t1 - t0) / (float)CLOCKS_PER_SEC);
	printf("t2 - t1 = %.3f sec (Run time of HTML generating)\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
	printf("t3 - t2 = %.3f sec (Run time of dictionary destroying )\n", (t2 - t1) / (float)CLOCKS_PER_SEC);
}

// ��������, ���� �� ����� word � �������, ���������� � ����� filenameDict
int Member(char* word) {
	// ������� ����
	FILE* fin = fopen(filenameDict, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameDict);
		return 0;
	}

	char token[MAX_LEN_WORD + 1];


	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token)) {
			if (strcmp(token, word) == 0) {
				// ����� � ����� ����!
				fclose(fin);
				return 1;
			}
		}
	}
	// ��������� ���� � �������
	fclose(fin);
	return 0;
}


int TextProcessing(char* filenameIn, char* filenameOut) {
	// ������� ����
	FILE* fin = fopen(filenameIn, "rt");
	if (fin == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameIn);
		return 0;
	}

	// ������� ����
	FILE* fout = fopen(filenameOut, "wt");
	if (fout == NULL) {
		// ���� ���� �� ������ ������� - �������� �� ����
		printf("File %s doesn't opened!\n", filenameOut);

		fclose(fin);
		return 0;
	}

	// ������� � �������� ���� ��������� HTML ���������
	fprintf(fout, "<!DOCTYPE html>");
	fprintf(fout, "<html>");
	fprintf(fout, "<head>");
	fprintf(fout, "<meta http - equiv = \"Content-Type\" content = \"text/html; charset=utf-8\" />");
	fprintf(fout, "<title>HTML Document</title>");
	fprintf(fout, "</head>");
	fprintf(fout, "<body>");



	char token[MAX_LEN_WORD + 1];

	// ���� �� ����� �����
	while (!feof(fin)) {
		// ���� ���� ����������� - ����� ���
		while (getNextDelim(fin, token)) {
			// ������� ����������� 
			fprintf(fout, "%s", token);
			if (strcmp(token, "\n") == 0) {
				fprintf(fout, "<br>");
			}
		}
		// ���� ���� ����� - ����� ���
		if (getNextWord(fin, token)) {
			// ���� ����� ���� � ������� � �� �������� ���
			if (Member(token)) {
				fprintf(fout, "<b>%s</b>", token);
			}
			else {
				fprintf(fout, "%s", token);
			}
		}
	}

	// ������� � HTML ����������� ���� ��������� HTML
	fprintf(fout, "</body>");
	fprintf(fout, "</html>");
	// ��������� ������� � �������� �����
	fclose(fin);
	fclose(fout);

	return 1;
}





// ���������� 0 - ���� ch - �� �����.
// ���������� 1 - ���� ch - �����.
// ��������� �������� ��� ��������� ���� (� ������ < 128)
// � ��� ������� ���� �� ��������� ANSI
int isalpha_my(unsigned char ch) {

	if (isalpha(ch))
		return 1;

	// ANSI ���������!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	return 0;
}




int isalpha_my(unsigned char ch);

// ���������� 1 - ����  �� ����� �������� �����������.
// � ���� ������ � token ������������ ������, ���������� 
// ���� �����������.
// ���� � ����� ��� �� ����������� - ���������� 0.
// � ���� ������ ��������� token ������������.
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
	return 1;
}


// ���������� 1 - ����  �� ����� ��������� �����.
// � ���� ������ � token ������������ ������, ���������� 
// ��� �����. ������������� ��� ����� �� ����� MAX_LEN_WORD ��������.
// ���� � ����� �� ���� ����� - ���������� 0.
// � ���� ������ token �������� ������ ������.
int getNextWord(FILE* fp, char token[])
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < MAX_LEN_WORD)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
	if (i == 0)
		return 0;
	return 1;
}
