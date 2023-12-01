#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void loadMatrix(char *fileName,
                double matrix[100][101],
                int *amount)
{
    int n;
    ifstream file;
    file.open(fileName);
    file >> n;

    for (int row = 0; row < n; row++){
        for (int col = 0; col <= n; col++){
            file >> matrix[row][col];
        }
    }
    file.close();
    *amount = n;
}

void printMatrix(double matrix[100][101],
                 int amount)
{
        for (int row = 0; row < amount; row++){
            for (int col = 0; col <=amount; col++){
                cout << setw(4) << matrix[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

void multiplyRow(double matrix[100][101],
              int amount,
              int row,
              double constant)
{
    for (int col = 0; col <=amount; col++){
        matrix[row][col] *= constant;
    }
}

void addRows(double matrix[100][101],
         int amount,
         int row1,
         int row2)
{
    for (int col = 0; col <=amount; col++){
        matrix[row1][col] += matrix[row2][col];
    }
}

void swapRows(double matrix[100][101],
         int amount,
         int row1,
         int row2)
{
    int n;
    for (int col = 0; col <=amount; col++){
        n = matrix[row1][col];
        matrix[row1][col] = matrix[row2][col];
        matrix[row2][col] = n;
    }
}

void GElimination(double matrix[100][101], int amount){
    for (int i = 1; i < amount; i++){
        for (int j = i; j < amount; j++){

            multiplyRow(matrix, amount, j, -(matrix[i-1][i-1] / matrix[j][i-1]));

            addRows(matrix, amount, j, i-1);
    }}
    for (int i = amount-1; i > 0; i--){
        for (int j = i; j > 0; j--){
            printMatrix(matrix, amount);
            multiplyRow(matrix, amount, i, 1/matrix[i][i]);
            printMatrix(matrix, amount);

            multiplyRow(matrix, amount, j-1, -(matrix[i][i] / matrix[j-1][i]));

            printMatrix(matrix, amount);

            addRows(matrix, amount, j-1, i);

            printMatrix(matrix, amount);
    }}
}

int main()
{
    int amount;
    double matrix[100][101];

    loadMatrix("matice.txt", matrix, &amount);

    printMatrix(matrix, amount);

    GElimination(matrix, amount);

    printMatrix(matrix, amount);

/*
    loadMatrix("matice.txt", matrix, &amount);
    printMatrix(matrix, amount);

    multiplyRow(matrix, amount, 0, 7);
    printMatrix(matrix, amount);

    addRows(matrix, amount, 0, 1);
    printMatrix(matrix, amount);

    swapRows(matrix, amount, 0, 2);
    printMatrix(matrix, amount);

    return 0;
    */
}
