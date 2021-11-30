#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void enterArray(int** Array, int colum, int row) {  //функция ввода данных(заполение массива)
    for (int i = 0; i < colum; i++) {
        for (int j = 0; j < row; j++)
        {
            scanf("%3d", &Array[i][j]);
        }
    }
}

void printArray(int** Array, int colum, int row) { //функция вывода данных(вывод массива)
    if (Array) {
        for (int i = 0; i < colum; i++) {
            for (int j = 0; j < row; j++) {
                printf("%3d", Array[i][j]);
            }
            printf("\n");
        }
    }
}

int  main()
{
    int colum1 = 0, row1 = 0;
    while (colum1 <= 0) {                                                                  //
        printf("Enter colum of the first Array:");                                         //
        scanf("%d", &colum1);                                                              //ввод количества столбцов
        if (colum1 <= 0) {                                                                 //проверка входных данных
            printf("Colum1 cannot be <= 0, please enter a positive number > than 0\n");    // 
        }                                                                                  //
    }
    while (row1 <= 0) {                                                                    //
        printf("Enter row of the first Array:");                                           //
        scanf("%d", &row1);                                                                //ввод количества строк
        if (row1 <= 0) {                                                                   //проверка входных данных                                             
            printf("Row1 cannot be <= 0, please enter a positive number > than 0\n");      // 
        }
    }

    int** Array1 = malloc(sizeof(int) * colum1); //выделение памяти под указатели
    for (int i = 0; i < colum1; i++) {
        Array1[i] = malloc(sizeof(int) * row1);
    }
    enterArray(Array1, colum1, row1);//вызов функции ввода
    printArray(Array1, colum1, row1);//вызов функции вывода



    int colum2 = 0, row2 = 0;
    while (colum2 <= 0) {
        printf("Enter colum of the first Array:");
        scanf("%d", &colum2);
        if (colum2 <= 0) {
            printf("Colum2 cannot be <= 0, please enter a positive number > than 0\n");
        }
    }
    while (row2 <= 0) {
        printf("Enter row of the first Array:");
        scanf("%d", &row2);
        if (row2 <= 0) {
            printf("Row2 cannot be <= 0, please enter a positive number > than 0\n");
        }
    }

    int** Array2 = malloc(sizeof(int) * colum2);
    for (int i = 0; i < colum2; i++) {
        Array2[i] = malloc(sizeof(int) * row2);
    }
    enterArray(Array2, colum2, row2);
    printArray(Array2, colum2, row2);


    if (row1 == colum2) {                                    //проверка на корректность размерности матриц  
        int** resultArray = malloc(sizeof(int) * colum1);   //создаём и выделяем память под массив указателей
        for (int i = 0; i < colum1; i++) {                   //под каждый указатель из массива указателей выделяем память
            resultArray[i] = malloc(sizeof(int) * row2);    //
        }

        for (int i = 0; i < colum1; i++) {                   //i - отвечает за перемещение по строкам первой матрицы
            for (int j = 0; j < row2; j++) {                //j - отвечает за перемещение по столбцам второй матрицы      
                int sum = 0;                                //k - отвечает за перемещение по столбцам первой матрицы, за перемещение по строкам второй матрицы
                for (int k = 0; k < row1; k++) {            //сумма перемножение i-ой строки на j-ый столбец  
                    sum += Array1[i][k] * Array2[k][j];     //
                }
                resultArray[i][j] = sum;
            }
        }

        printf("Result is : \n");
        printArray(resultArray, colum1, row2);
    }
    else {
        printf("Matrices cannot be multiplied!\n");
    }
    return 0;

}