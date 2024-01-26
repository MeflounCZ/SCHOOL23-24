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
                cout << setw(4) << matrix[row][col] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

// Print Array
void printResults(double results[100], int amount){
    for(int i = 0; i < amount; i++){
        cout << setw(4) << results[i] << " ";
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

// Transform matrix into correct format for Gauss-Seidel method
void prepareMatrix(double matrix[100][101],int amount)
{
    for(int i = 0; i < amount; i++){
        multiplyRow(matrix, amount, i, -(1/matrix[i][i]));
        matrix[i][i] = 0;
        matrix[i][amount] *= -1;
    }
}

// Calculate matrix using Gauss-Seidel method
void Gauss_Seidel(double matrix[100][101], int amount, double results[100], bool check[100]){
    bool next = false;
    int k = 0;
    prepareMatrix(matrix, amount);
    while (!next){
        next = true;

        for(int i = 0; i < amount; i++){
            int nextNum = 0;
            for(int j = 0; j < amount-1; j++) nextNum += matrix[i][j] * results[j];
            nextNum += matrix[i][amount];
            if(abs(nextNum - results[i]) < 0.0001) check[i] = true;
            results[i] = nextNum;
        }
        k = 0;
        while (k < amount && next){
            if (next) next = check[k];
            k++;
        }
    }
}

int main()
{
    int amount;
    double matrix[100][101];
    double result[100];
    bool check[100];

    loadMatrix("matice.txt", matrix, &amount);

    for(int i = 0; i < amount-1; i++){
        result[i] = 0;
        check[i] = false;
    }

    printMatrix(matrix, amount);

    Gauss_Seidel(matrix, amount, result, check);

    printResults(result, amount);
}