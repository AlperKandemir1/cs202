/**
*Title: Algorithm Efficiency and Sorting
*Author: Alper Kandemir
*ID: 21703062
*Section: 1
*Assignment: 1
*Description: main
*/

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <stdio.h>
#include "sorting.h"

using namespace std;

int main()
{
    int countComp1=0;
    int countMove1=0;
    int countComp2=0;
    int countMove2=0;
    int countComp3=0;
    int countMove3=0;
    int countComp4=0;
    int countMove4=0;
    
    int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;
    
    arr1 = new int[16];
    arr2 = new int[16];
    arr3 = new int[16];
    arr4 = new int[16];
    arr1[0] = 7;
    arr1[1] = 3;
    arr1[2] = 6;
    arr1[3] = 12;
    arr1[4] = 13;
    arr1[5] = 4;
    arr1[6] = 1;
    arr1[7] = 9;
    arr1[8] = 15;
    arr1[9] = 0;
    arr1[10] = 11;
    arr1[11] = 14;
    arr1[12] = 2;
    arr1[13] = 8;
    arr1[14] = 10;
    arr1[15] = 5;
    
    
    for (int i = 0; i < 16; i++) {
    
        arr2[i] =arr1[i] ;
        arr3[i] =arr1[i] ;
        arr4[i] =arr1[i] ;
    }

    performanceAnalysis();

    insertionSort(arr1, 16, countComp1, countMove1);
    printArray(arr1,16);
    cout << "\n";
    
    mergeSort(arr2, 0 , 15, countComp2, countMove2);
    printArray(arr2,16);
    cout << "\n";

    quickSort(arr3, 0 , 15, countComp3, countMove3);
    printArray(arr3,16);
    cout << "\n";
    
    radixSort(arr4, 16);
    printArray(arr4,16);
    cout << "\n";

    

    return 0;
}