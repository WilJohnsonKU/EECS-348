#include <stdio.h>
#include <stdlib.h>

#define _MAX_LENGTH 12
char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 

void readData(FILE *filePointer, double values[]) {
    int i = 0;
    char line[256];
    while (fgets(line, sizeof(line), filePointer) && i < _MAX_LENGTH) {
        values[i] = atof(line);
        i++;
    }
}

void printSalesReport(double values[]) {
    printf("Monthly sales report for 2023:\n\n");
    printf("%-15s%s\n\n", "Month", "Sales");
    for (int i = 0; i < _MAX_LENGTH; i++) {
        printf("%-15s$%.2f\n", months[i], values[i]);
    }
}

void minMaxAvg(double values[]) {
    double min = values[0];
    int minIndex = 0;
    double max = values[0];
    int maxIndex = 0;
    double sum = 0;
    for (int i = 0; i < _MAX_LENGTH; i++) {
        if (values[i] < min){
            min = values[i];
            minIndex = i;
        }
        if (values[i] > max){
            max = values[i];
            maxIndex = i;
        }
        sum += values[i];
    }
    double avg = sum / _MAX_LENGTH;

    printf("\n\nSales Summary:\n\n");
    printf("Minimum sales: %.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: %.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: %.2f\n", avg);
}

void printSixMonthAvg(double values[]) {
    printf("\n\nSix-Month Moving Average Report:\n\n");
    for (int i = 0; i <= 6; i++){
        float avg = 0;
        for (int j = i; j < 6+i; j++){
            avg += values[j];
        }
        printf("%-15s%-5c%-15s$%.2f\n", months[i], '-', months[i+5], avg / 6);
    }
}

void printSortedReport(double values[]) {
    double sortedValues[_MAX_LENGTH];
    char *sortedMonths[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    for (int i = 0; i < _MAX_LENGTH; i++) {
        sortedValues[i] = values[i];
    }

    printf("\n\nSales Report (Highest to Lowest):\n\n");
    printf("%-15s%s\n\n", "Month", "Sales");
    for (int i = 0; i < _MAX_LENGTH; i++) {
        for (int j = i + 1; j < _MAX_LENGTH; j++) {
            if (sortedValues[i] < sortedValues[j]) {
                double temp = sortedValues[i];
                char* temp2 = sortedMonths[i];
                sortedValues[i] = sortedValues[j];
                sortedValues[j] = temp;
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = temp2;
            }
        }
    }

    // Print sorted array
    for (int i = 0; i < _MAX_LENGTH; i++) {
        printf("%-15s$%.2f\n", sortedMonths[i], sortedValues[i]);
    }
}

int main(){

    char fileName[100];
    printf("Enter the name of the Input File (Example, try: SalesReport_SampleInputFile.txt): ");
    scanf("%s", fileName);
    printf("Running on %s...\n\n", fileName);

    FILE *RawFile = fopen(fileName, "r");

    if (RawFile == NULL){
        printf("Failed to open file.\n");
        return 1;
    }

    double values[_MAX_LENGTH];
    readData(RawFile, values);

    printSalesReport(values);
    minMaxAvg(values);
    printSixMonthAvg(values);
    printSortedReport(values);

    fclose(RawFile);
    return 0;
}