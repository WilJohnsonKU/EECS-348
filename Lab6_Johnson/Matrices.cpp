#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

static const int MaxSize = 100;
int MatrixA[MaxSize][MaxSize];
int MatrixB[MaxSize][MaxSize];

int matrixRealSize = 0;

void ReadMatrices(FILE *file){
    char line[256];
    fgets(line, sizeof(line), file);
    int arraySize = atoi(line);

    if (arraySize > MaxSize) {
        printf("Matrix size exceeds maximum [100]");
        return;
    }

    matrixRealSize = arraySize;

    int row = 0;
    int col = 0;
    while (row < arraySize && fgets(line, sizeof(line), file)) {
        string temp = "";
        for (char c : line) {
            if (c == ' ') {
                if (!temp.empty()) {
                    MatrixA[row][col] = stoi(temp);
                    temp.clear();
                    col++;
                }
            } else {
                temp += c;
            }
        }
        row++;
        col = 0;
    }

    row = 0;
    col = 0;
    while (fgets(line, sizeof(line), file) && row < arraySize) {
        string temp = "";
        for (char c : line) {
            if (c == ' ') {
                if (!temp.empty()) {
                    MatrixB[row][col] = stoi(temp);
                    temp.clear();
                    col++;
                }
            } else {
                temp += c;
            }
        }
        row++;
        col = 0;
    }
}

void PrintMatrix(int (*matrix)[MaxSize]){
    for (int i=0; i<matrixRealSize; i++){
        for (int j=0; j<matrixRealSize; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void AddMatrices(int (*matrixA)[MaxSize], int (*matrixB)[MaxSize]){
    int resultMatrix[MaxSize][MaxSize];
     for (int i=0; i<matrixRealSize; i++){
        for (int j=0; j<matrixRealSize; j++){
            resultMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    PrintMatrix(resultMatrix);
}

void SubtractMatrices(int (*matrixA)[MaxSize], int (*matrixB)[MaxSize]){
    int resultMatrix[MaxSize][MaxSize];
     for (int i=0; i<matrixRealSize; i++){
        for (int j=0; j<matrixRealSize; j++){
            resultMatrix[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }

    PrintMatrix(resultMatrix);
}

void MultiplyMatrices(int (*matrixA)[MaxSize], int (*matrixB)[MaxSize]){
    int resultMatrix[MaxSize][MaxSize];
    for (int i=0; i<matrixRealSize; i++){
        for (int j=0; j<matrixRealSize; j++){
            resultMatrix[i][j] = 0;
            for (int k = 0; k < matrixRealSize; k++) {
                resultMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    PrintMatrix(resultMatrix);
}

int main(){

    char fileName[100];
    printf("Enter the name of the Input File (Example, try: Sample_Matrices.txt): ");
    scanf("%s", fileName);
    printf("Running on %s...\n\n", fileName);

    FILE *RawFile = fopen(fileName, "r");

    if (RawFile == NULL){
        printf("Failed to open file. File must be in the same directory as executable.\n");
        return 1;
    }

    ReadMatrices(RawFile);

    printf("Input Matrices:\n\nMatrixA:\n");
    PrintMatrix(MatrixA);
    printf("\nMatrixB:\n");
    PrintMatrix(MatrixB);

    printf("\nAdding MatrixA + MatrixB:\n");
    AddMatrices(MatrixA, MatrixB);

    printf("\nMultiplying MatrixA * MatrixB:\n");
    MultiplyMatrices(MatrixA, MatrixB);

    printf("\nSubtracting MatrixA - MatrixB:\n");
    SubtractMatrices(MatrixA, MatrixB);

    return 0;
}