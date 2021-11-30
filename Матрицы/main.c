#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void enterArray(int** Array, int colum, int row) {  //������� ����� ������(��������� �������)
    for (int i = 0; i < colum; i++) {
        for (int j = 0; j < row; j++)
        {
            scanf("%3d", &Array[i][j]);
        }
    }
}

void printArray(int** Array, int colum, int row) { //������� ������ ������(����� �������)
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
        scanf("%d", &colum1);                                                              //���� ���������� ��������
        if (colum1 <= 0) {                                                                 //�������� ������� ������
            printf("Colum1 cannot be <= 0, please enter a positive number > than 0\n");    // 
        }                                                                                  //
    }
    while (row1 <= 0) {                                                                    //
        printf("Enter row of the first Array:");                                           //
        scanf("%d", &row1);                                                                //���� ���������� �����
        if (row1 <= 0) {                                                                   //�������� ������� ������                                             
            printf("Row1 cannot be <= 0, please enter a positive number > than 0\n");      // 
        }
    }

    int** Array1 = malloc(sizeof(int) * colum1); //��������� ������ ��� ���������
    for (int i = 0; i < colum1; i++) {
        Array1[i] = malloc(sizeof(int) * row1);
    }
    enterArray(Array1, colum1, row1);//����� ������� �����
    printArray(Array1, colum1, row1);//����� ������� ������



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


    if (row1 == colum2) {                                    //�������� �� ������������ ����������� ������  
        int** resultArray = malloc(sizeof(int) * colum1);   //������ � �������� ������ ��� ������ ����������
        for (int i = 0; i < colum1; i++) {                   //��� ������ ��������� �� ������� ���������� �������� ������
            resultArray[i] = malloc(sizeof(int) * row2);    //
        }

        for (int i = 0; i < colum1; i++) {                   //i - �������� �� ����������� �� ������� ������ �������
            for (int j = 0; j < row2; j++) {                //j - �������� �� ����������� �� �������� ������ �������      
                int sum = 0;                                //k - �������� �� ����������� �� �������� ������ �������, �� ����������� �� ������� ������ �������
                for (int k = 0; k < row1; k++) {            //����� ������������ i-�� ������ �� j-�� �������  
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