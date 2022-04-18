/**
*Title: Algorithm Efficiency and Sorting
*Author: Alper Kandemir
*ID: 21703062
*Section: 1
*Assignment: 1
*Description: header file of sorting
*/

void insertionSort( int *arr , int arraysize , int &compCount , int &moveCount );
void quickSort( int* arr, int first, int last, int& compCount, int &moveCount );
void mergeSort( int* arr, int first, int last, int &compCount , int &moveCount );
void radixSort( int *arr , int arraySize );
void printArray(int *arr, int arraySize);
void performanceAnalysis();