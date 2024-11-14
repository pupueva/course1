//��������
#define _CRT_SECURE_NO_WARNINGS  
#include <stdio.h>  
#include <stdlib.h>  
#include <locale.h>  
#include <math.h>  
#include <time.h>

void initialize_array_random(double** array, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = ((double)rand() / RAND_MAX) * 20 - 10;  // ��������� ����� �� -10 �� 10
        }
    }
}

void initialize_array_manual(double** array, int rows, int cols) {
    printf("������� �������� �������:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("������� [%d][%d]: ", i, j);
            scanf("%lf", &array[i][j]);
        }
    }
}

void print_array(double** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", array[i][j]);
        }
        printf("\n");
    }
}

void transform_array(double** array, int rows, int cols) {
    // ������ ��������������: ��������� ��� �������� ������� �� 1.5
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] += 1.5;
        }
    }
}

void free_array(double** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

int main() {
    int rows, cols, choice;
    double** array = NULL;
    setlocale(LC_CTYPE, "RUS");


    while (1) {
        printf("\n����:\n");
        printf("1. ���������������� ������ � �������\n");
        printf("2. ���������������� ������ ���������� ����������\n");
        printf("3. ������� �������� ������\n");
        printf("4. ������������� � ������� ������\n");
        printf("5. ��������� ���������\n");
        printf("�������� �����: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        case 2:
            if (array != NULL) {
                free_array(array, rows);
            }
            printf("������� ���������� ����� � �������� �������: ");
            scanf("%d %d", &rows, &cols);

            // ��������� ������ ��� ���������� �������
            array = (double**)malloc(rows * sizeof(double*));
            for (int i = 0; i < rows; i++) {
                array[i] = (double*)malloc(cols * sizeof(double));
            }

            if (choice == 1) {
                initialize_array_manual(array, rows, cols);
            }
            else {
                initialize_array_random(array, rows, cols);
            }
            printf("������ ������� ���������������.\n");
            break;

        case 3:
            if (array != NULL) {
                printf("�������� ������:\n");
                print_array(array, rows, cols);
            }
            else {
                printf("������ �� ���������������. ����������, �������� ����� 1 ��� 2.\n");
            }
            break;

        case 4:
            if (array != NULL) {
                transform_array(array, rows, cols);
                printf("��������������� ������:\n");
                print_array(array, rows, cols);
            }
            else {
                printf("������ �� ���������������. ����������, �������� ����� 1 ��� 2.\n");
            }
            break;

        case 5:
            if (array != NULL) {
                free_array(array, rows);
            }
            printf("���������� ���������.\n");
            return 0;

        default:
            printf("������������ �����. ����������, �������� ����� �� ����.\n");
        }
    }
}
