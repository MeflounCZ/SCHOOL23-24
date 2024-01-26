#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Load matrix
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

// Print Matrix
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

// Multiply a row of a matrix by a constant
void multiplyRow(double matrix[100][101],
              int amount,
              int row,
              double constant)
{
    for (int col = 0; col <=amount; col++){
        matrix[row][col] *= constant;
    }
}

// Add a row (row2) of a matrix to second row (row1) - changes row 2
void addRows(double matrix[100][101],
         int amount,
         int row1,
         int row2)
{
    for (int col = 0; col <=amount; col++){
        matrix[row1][col] += matrix[row2][col];
    }
}

// Swap two rows of a matrix
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

// Calculate greatest common denominator of two numbers
int GCD (int num1, int num2){
    while (num1 != num2){
        if (num1 > num2) num1 = num1 - num2;
        else num2 = num2 - num1;
    }
    return num1;
}

// Calculate a matrix using Gauss Elimination
void GElimination(double matrix[100][101], int amount){
    for (int i = 0; i < amount-1; i++){
        if (matrix[i][i] < 0) multiplyRow(matrix, amount, i, -1);
        for (int j = i+1; j < amount; j++){
            if (matrix[j][i] < 0) multiplyRow(matrix, amount, j, -1);
            
            int gcd = GCD(matrix[i][i], matrix[j][i]);
            int num = matrix[i][i];

            multiplyRow(matrix, amount, i, matrix[j][i]/gcd);
            multiplyRow(matrix, amount, j, -(num/gcd));

            addRows(matrix, amount, j, i);
    }}
    for (int i = amount-1; i >= 0; i--){
        multiplyRow(matrix, amount, i, 1/matrix[i][i]);
        for (int j = i-1; j >= 0; j--){
            if (matrix[j][i] != 0){
                if (matrix[j][i] < 0) multiplyRow(matrix, amount, j, -1);

                int gcd = GCD(matrix[i][i], matrix[j][i]);
                int num = matrix[i][i];

                multiplyRow(matrix, amount, i, matrix[j][i]/gcd);
                multiplyRow(matrix, amount, j, -(num/gcd));

                addRows(matrix, amount, j, i);
                multiplyRow(matrix, amount, i, 1/matrix[i][i]);
    }}}
}

int main()
{
    int amount;
    double matrix[100][101];

    loadMatrix("matice.txt", matrix, &amount);

    printMatrix(matrix, amount);

    GElimination(matrix, amount);

    printMatrix(matrix, amount);
}
