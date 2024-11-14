//курсовая
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
            array[i][j] = ((double)rand() / RAND_MAX) * 20 - 10;  // Случайные числа от -10 до 10
        }
    }
}

void initialize_array_manual(double** array, int rows, int cols) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Элемент [%d][%d]: ", i, j);
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
    // Пример преобразования: увеличить все элементы массива на 1.5
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
        printf("\nМеню:\n");
        printf("1. Инициализировать массив с консоли\n");
        printf("2. Инициализировать массив случайными значениями\n");
        printf("3. Вывести исходный массив\n");
        printf("4. Преобразовать и вывести массив\n");
        printf("5. Завершить программу\n");
        printf("Выберите пункт: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        case 2:
            if (array != NULL) {
                free_array(array, rows);
            }
            printf("Введите количество строк и столбцов массива: ");
            scanf("%d %d", &rows, &cols);

            // Выделение памяти для двумерного массива
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
            printf("Массив успешно инициализирован.\n");
            break;

        case 3:
            if (array != NULL) {
                printf("Исходный массив:\n");
                print_array(array, rows, cols);
            }
            else {
                printf("Массив не инициализирован. Пожалуйста, выберите пункт 1 или 2.\n");
            }
            break;

        case 4:
            if (array != NULL) {
                transform_array(array, rows, cols);
                printf("Преобразованный массив:\n");
                print_array(array, rows, cols);
            }
            else {
                printf("Массив не инициализирован. Пожалуйста, выберите пункт 1 или 2.\n");
            }
            break;

        case 5:
            if (array != NULL) {
                free_array(array, rows);
            }
            printf("Завершение программы.\n");
            return 0;

        default:
            printf("Некорректный выбор. Пожалуйста, выберите пункт из меню.\n");
        }
    }
}
