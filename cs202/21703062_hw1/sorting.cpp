/**
*Title: Algorithm Efficiency and Sorting
*Author: Alper Kandemir
*ID: 21703062
*Section: 1
*Assignment: 1
*Description: sorting algos that sort ascending order
*/
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include "sorting.h"
#include <chrono>
#include <time.h>
using namespace std;

//-----------------------------------------------------------------------------------------------

void insertionSort(int* arr, const int size, int& countComp, int& countMove) {

    for (int unsorted = 1; unsorted < size; ++unsorted) {

        int nextItem = arr[unsorted];
        int loc = unsorted;

        for (; (loc > 0) && (arr[loc - 1] > nextItem); --loc) {
            arr[loc] = arr[loc - 1];
            countMove = countMove + 1;
            countComp = countComp + 1;
        }
        countComp = countComp + 1;
        arr[loc] = nextItem;
    }
}
//-----------------------------------------------------------------------------------------------

void merge(int* arr, int first, int mid, int last, int& countComp, int& countMove) {
    int tempArray[500000]; //temporary array​

    int first1 = first;     // beginning of first subarray​
    int last1 = mid;        // end of first subarray​
    int first2 = mid + 1;   // beginning of second subarray​
    int last2 = last;       // end of second subarray​
    int index = first1;     // next available location in tempArray​

    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        countMove = countMove + 1;
        countComp = countComp + 1;
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
        }
        else {
            tempArray[index] = arr[first2];
            ++first2;
        }
    }
    for (; first1 <= last1; ++first1, ++index) {
        tempArray[index] = arr[first1];
        countMove = countMove + 1;
    }
    for (; first2 <= last2; ++first2, ++index) {
        tempArray[index] = arr[first2];
        countMove = countMove + 1;
    }
    for (index = first; index <= last; ++index) {
        arr[index] = tempArray[index];
        countMove = countMove + 1;
    }
}

void mergeSort(int* arr, int first, int last, int& countComp, int& countMove) {
    if (first < last) {
        int mid = (first + last) / 2; // index of midpoint
        mergeSort(arr, first, mid, countComp, countMove);
        mergeSort(arr, mid + 1, last, countComp, countMove);
        merge(arr, first, mid, last, countComp, countMove);


    }
}


//-----------------------------------------------------------------------------------------------

void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}


void partition(int* arr, int first, int last, int& pivotIndex, int& countComp, int& countMove) {
    int pivot = arr[first];

    // initially, everything but pivot is in unknown​
    int lastS1 = first;        // index of last item in S1​
    int firstUnknown = first + 1; // index of first item in unknown​

    // move one item at a time until unknown region is empty​
    for (; firstUnknown <= last; ++firstUnknown) {

        // Invariant: theArray[first+1..lastS1] < pivot​
        // theArray[lastS1+1..firstUnknown-1] >= pivot​

        // move item from unknown to proper region​
        if (arr[firstUnknown] < pivot) {  // belongs to S1​
            ++lastS1;
            countMove = countMove + 3;
            swap(arr[firstUnknown], arr[lastS1]);
        } // else belongs to S2​
        countComp = countComp + 1;
    }
    // place pivot in proper position and mark its location​
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    countMove = countMove + 3;
}

void quickSort(int* arr, int first, int last, int& countComp, int& countMove) {
    // Precondition: theArray[first..last] is an array
    // Postcondition: theArray[first..last] is sorted

    int pivotIndex;


    if (first < last) {

        // create the partition: S1, pivot, S2
        partition(arr, first, last, pivotIndex, countComp, countMove);

        // sort regions S1 and S2
        quickSort(arr, first, pivotIndex - 1, countComp, countMove);
        quickSort(arr, pivotIndex + 1, last, countComp, countMove);
    }
}

//-----------------------------------------------------------------------------------------------

int findMax(int *arr , int size ){
    
    int max = arr[size];
    for (int i = size-1; i >= 0; i--)
        if (arr[i] > max)
            max = arr[i];
    return max;

    } 
    
void countingSort(int *arr , int size, int div){
    
    const int n = 10;
    int counter[n];

    for (int i = 0; i < n; i++) {
    
        counter[i] =0 ;
    } 
    
    int result[size];
  
    for (int i = 0; i < size; i++){ 
        counter[ (arr[i] / div) % n ]=counter[ (arr[i] / div) % n ]+1;
    } 
  
    for (int i = 1; i < n; i++) {
        counter[i] =counter[i] + counter[i - 1]; 
    }
    
    for (int i = size - 1; i >= 0; i--) 
    { 
        result[ counter[ (arr[i] / div) % n] - 1] = arr[i]; 
        counter[ (arr[i] / div) % n ]=counter[ (arr[i] / div) % n ]-1;   
//      cout<<(arr[i] / div) % n<<"\n";
//      cout<<arr[i]<<"\n";
//      cout<<result[ counter[ (arr[i] / div) % n] - 1]<<"\n";
    } 
  
    for (int i = 0; i < size; i++) {
        arr[i] = result[i]; 
//        cout<<arr[i]<<"\n";
    }
}     
    
    
void radixSort( int *arr , int size ){
    
    int max = findMax(arr, size);
    
    for (int div = 1; max / div > 0; div =div * 10){
        countingSort(arr, size, div);
    }
}

//-----------------------------------------------------------------------------------------------



void createRandomArrays(int*& arr1, int*& arr2, int*& arr3,int*& arr4, const int size) {
    if (size < 0) {
        cout << "size cannot be negative";
        return;
    }
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];
    
    for (int i = 0; i < size; i++) {
        int x = rand();
        arr1[i] = x;
        arr2[i] = x;
        arr3[i] = x;
        arr4[i] = x;
    }
//    for (int i = 0; i < size; i++) {
//
//        cout << arr1[i]<< "\n";
//    }
//    cout << "-----------------------------\n";
//    for (int i = 0; i < size; i++) {
//
//        cout << arr2[i]<< "\n";
//    }
//    cout << "-----------------------------\n";
//    for (int i = 0; i < size; i++) {
//
//        cout << arr3[i]<< "\n";
//    }
//    cout << "-----------------------------\n";
}
    
    
//-----------------------------------------------------------------------------------------------

void performanceAnalysis() {
    int size;
    int countComp1=0;
    int countMove1=0;
    int* arr1;
    int* arr2;
    int* arr3;
    int* arr4;


    //random 2000

    size = 2000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);

    //insertion sort random 2000
    double duration1;
    clock_t startTime1 = clock();
    insertionSort(arr1, size, countComp1, countMove1);
    duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;

    // mergeSort random 2000
    int countComp2 = 0;
    int countMove2 = 0;
    double duration2;
    clock_t startTime2 = clock();
    mergeSort(arr2,0 , size-1, countComp2, countMove2);
    duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;

    // quickSort random 2000
    int countComp3 = 0;
    int countMove3 = 0;
    double duration3;
    clock_t startTime3 = clock();
    quickSort(arr3,0 , size-1, countComp3, countMove3);
    duration3 = 1000 * double(clock() - startTime3) / CLOCKS_PER_SEC;
    
    // radixSort random 2000
    int countComp25 = 0;
    int countMove25 = 0;
    double duration25;
    clock_t startTime25 = clock();
    radixSort(arr4,size);
    duration25 = 1000 * double(clock() - startTime25) / CLOCKS_PER_SEC;  

  
//    for (int i = 0; i < size; i++) {
//
//        cout << arr1[i]<< "\n";
//    }
//    cout << "-----------------------------\n";
//    for (int i = 0; i < size; i++) {
//
//        cout << arr2[i]<< "\n";
//    }
//    cout << "-----------------------------\n";
//    for (int i = 0; i < size; i++) {
//
//        cout << arr3[i]<< "\n";
//    }
//    cout << "-----------------------------\n";
//
//    for (int i = 0; i < size; i++) {
//        cout << arr4[i]<< "\n";
//    }
//    cout << "-----------------------------\n";

    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    
//----------------------------------------------------------------------------------------------- 
    
    //random 6000
    size = 6000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);
    int countComp4 = 0;
    int countMove4 = 0;
    //insertion sort random 6000
    double duration4;
    clock_t startTime4 = clock();
    insertionSort(arr1, size, countComp4, countMove4);
    duration4 = 1000 * double(clock() - startTime4) / CLOCKS_PER_SEC;

    // mergeSort random 6000
    int countComp5 = 0;
    int countMove5 = 0;
    double duration5;
    clock_t startTime5 = clock();
    mergeSort(arr2,0 , size-1, countComp5, countMove5);
    duration5 = 1000 * double(clock() - startTime5) / CLOCKS_PER_SEC;

    // quickSort random 6000
    int countComp6 = 0;
    int countMove6 = 0;
    
    double duration6;
    clock_t startTime6 = clock();
    quickSort(arr3,0 , size-1, countComp6, countMove6);
    duration6 = 1000 * double(clock() - startTime6) / CLOCKS_PER_SEC;
    
    // radixSort random 6000
    int countComp26 = 0;
    int countMove26 = 0;
    double duration26;
    clock_t startTime26 = clock();
    radixSort(arr4,size);
    duration26 = 1000 * double(clock() - startTime26) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    
//-------------------------------------------------------------------------------
    
    //random 10000
    size = 10000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);

    int countComp7 = 0;
    int countMove7 = 0;
    //insertion sort random 1000
    double duration7;
    clock_t startTime7 = clock();
    insertionSort(arr1, size, countComp7, countMove7);
    duration7 = 1000 * double(clock() - startTime7) / CLOCKS_PER_SEC;


    // mergeSort random 10000
    int countComp8 = 0;
    int countMove8 = 0;
    double duration8;
    clock_t startTime8 = clock();
    mergeSort(arr2,0 , size-1, countComp8, countMove8);
    duration8 = 1000 * double(clock() - startTime8) / CLOCKS_PER_SEC;


    // quickSort random 10000
    int countComp9 = 0;
    int countMove9 = 0;
    
    double duration9;
    clock_t startTime9 = clock();
    quickSort(arr3,0 , size-1, countComp9, countMove9);
    duration9 = 1000 * double(clock() - startTime9) / CLOCKS_PER_SEC;

    // radixSort random 10000
    int countComp27 = 0;
    int countMove27 = 0;
    double duration27;
    clock_t startTime27 = clock();
    radixSort(arr4,size);
    duration27 = 1000 * double(clock() - startTime27) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    
//-------------------------------------------------------------------------------     
    
    
 
    //random 14000
    size = 14000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);
    
    int countComp10 = 0;
    int countMove10 = 0;
    //insertion sort random 14000
    double duration10;
    clock_t startTime10 = clock();
    insertionSort(arr1, size, countComp10, countMove10);
    duration10 = 1000 * double(clock() - startTime10) / CLOCKS_PER_SEC;

    
    // mergeSort random 14000
    int countComp11 = 0;
    int countMove11 = 0;
    double duration11;
    clock_t startTime11 = clock();
    mergeSort(arr2, 0 , size-1, countComp11, countMove11);
    duration11 = 1000 * double(clock() - startTime11) / CLOCKS_PER_SEC;

    
    // quickSort random 14000
    int countComp12 = 0;
    int countMove12 = 0;
    
    double duration12;
    clock_t startTime12 = clock();
    quickSort(arr3, 0 , size-1, countComp12, countMove12);
    duration12 = 1000 * double(clock() - startTime12) / CLOCKS_PER_SEC;

    // radixSort random 14000
    int countComp28 = 0;
    int countMove28 = 0;
    double duration28;
    clock_t startTime28 = clock();
    radixSort(arr4,size);
    duration28 = 1000 * double(clock() - startTime28) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    
//-------------------------------------------------------------------------------    
    
    
    //randoms 18000
    size = 18000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);
    int countComp13 = 0;
    int countMove13 = 0;
    
    //insertion sort random 18000
    double duration13;
    clock_t startTime13 = clock();
    insertionSort(arr1, size, countComp13, countMove13);
    duration13 = 1000 * double(clock() - startTime13) / CLOCKS_PER_SEC;

    
    // mergeSort random 18000
    int countComp14 = 0;
    int countMove14 = 0;
    double duration14;
    clock_t startTime14 = clock();
    mergeSort(arr2, 0 , size-1, countComp14, countMove14);
    duration14 = 1000 * double(clock() - startTime14) / CLOCKS_PER_SEC;

    
    // quickSort random 18000
    int countComp15 = 0;
    int countMove15 = 0;
    
    double duration15;
    clock_t startTime15 = clock();
    quickSort(arr3, 0 , size-1, countComp15, countMove15);
    duration15 = 1000 * double(clock() - startTime15) / CLOCKS_PER_SEC;
    
    // radixSort random 18000
    int countComp29 = 0;
    int countMove29 = 0;
    double duration29;
    clock_t startTime29 = clock();
    radixSort(arr4,size);
    duration29 = 1000 * double(clock() - startTime29) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    
//-------------------------------------------------------------------------------    
    

    //randoms 22000
    size = 22000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);
    int countComp16 = 0;
    int countMove16 = 0;
    
    //insertion sort random 22000
    double duration16;
    clock_t startTime16 = clock();
    insertionSort(arr1, size, countComp16, countMove16);
    duration16 = 1000 * double(clock() - startTime16) / CLOCKS_PER_SEC;

    
    // mergeSort random 22000
    int countComp17 = 0;
    int countMove17 = 0;
    double duration17;
    clock_t startTime17 = clock();
    mergeSort(arr2, 0 , size-1, countComp17, countMove17);
    duration17 = 1000 * double(clock() - startTime17) / CLOCKS_PER_SEC;

    
    // quickSort random 22000
    int countComp18 = 0;
    int countMove18 = 0;
    
    double duration18;
    clock_t startTime18 = clock();
    quickSort(arr3, 0 , size-1, countComp18, countMove18);
    duration18 = 1000 * double(clock() - startTime18) / CLOCKS_PER_SEC;
    
    // radixSort random 22000
    int countComp30 = 0;
    int countMove30 = 0;
    double duration30;
    clock_t startTime30 = clock();
    radixSort(arr4,size);
    duration30 = 1000 * double(clock() - startTime30) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    //-------------------------------------------------------------------------------    
    

    //randoms 26000
    size = 26000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);
    
    int countComp19 = 0;
    int countMove19 = 0;
    //insertion sort random 26000
    double duration19;
    clock_t startTime19 = clock();
    insertionSort(arr1, size, countComp19, countMove19);
    duration19 = 1000 * double(clock() - startTime19) / CLOCKS_PER_SEC;

    
    // mergeSort random 26000
    int  countComp20 = 0;
    int countMove20 = 0;
    double duration20;
    clock_t startTime20 = clock();
    mergeSort(arr2, 0 , size-1, countComp20, countMove20);
    duration20 = 1000 * double(clock() - startTime20) / CLOCKS_PER_SEC;

    
    // quickSort random 26000
    int countComp21 = 0;
    int countMove21 = 0;
    
    double duration21;
    clock_t startTime21 = clock();
    quickSort(arr3, 0 , size-1, countComp21, countMove21);
    duration21 = 1000 * double(clock() - startTime21) / CLOCKS_PER_SEC;
    
    // radixSort random 26000
    int countComp31 = 0;
    int countMove31 = 0;
    double duration31;
    clock_t startTime31 = clock();
    radixSort(arr4,size);
    duration31 = 1000 * double(clock() - startTime31) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    //-------------------------------------------------------------------------------    
    

    //randoms 30000
    size = 30000;
    createRandomArrays(arr1, arr2, arr3,arr4, size);
    
    int countComp22 = 0;
    int countMove22 = 0;
    //insertion sort random 30000
    double duration22;
    clock_t startTime22 = clock();
    insertionSort(arr1, size, countComp22, countMove22);
    duration22 = 1000 * double(clock() - startTime22) / CLOCKS_PER_SEC;

    
    // mergeSort random 30000
    int countComp23 = 0;
    int countMove23 = 0;
    double duration23;
    clock_t startTime23 = clock();
    mergeSort(arr2, 0 , size-1, countComp23, countMove23);
    duration23 = 1000 * double(clock() - startTime23) / CLOCKS_PER_SEC;

    
    // quickSort random 30000
    int countComp24 = 0;
    int countMove24 = 0;
    
    double duration24;
    clock_t startTime24 = clock();
    quickSort(arr3, 0 , size-1, countComp24, countMove24);
    duration21 = 1000 * double(clock() - startTime24) / CLOCKS_PER_SEC;
    
    // radixSort random 30000
    int countComp32 = 0;
    int countMove32 = 0;
    double duration32;
    clock_t startTime32 = clock();
    radixSort(arr4,size);
    duration32 = 1000 * double(clock() - startTime32) / CLOCKS_PER_SEC;
    
    delete []arr1;
    delete []arr2;
    delete []arr3;
    delete []arr4;
    
    arr1=NULL;
    arr2=NULL;
    arr3=NULL;
    arr4=NULL;
    
    
    //------------------------------------------------------------------------------- 
    //printing
    
    cout <<"-----------------------------------------------------------------";
    cout << "\n";
    cout << "\n";
    cout <<"Analysis of insertionSort:";
    cout << "\n";
    cout << "Array Size\t";
    cout << "Time elapsed\t";
    cout << "countComp\t";
    cout << "countMove\t";
    cout << "\n";
    cout << "2000" << "\t\t";
    cout << duration1<<"ms" << "\t\t";
    cout << countComp1 << "\t\t";
    cout << countMove1 << "\t\t";
    cout << "\n";
    cout << "6000" << "\t\t";
    cout << duration4<<"ms" << "\t\t";
    cout << countComp4 << "\t\t";
    cout << countMove4 << "\t\t";
    cout << "\n";
    cout << "10000" << "\t\t";
    cout << duration7<<"ms" << "\t\t";
    cout << countComp7 << "\t";
    cout << countMove7 << "\t\t";
    cout << "\n";
    cout << "14000" << "\t\t";
    cout << duration10<<"ms" << "\t\t";
    cout << countComp10 << "\t";
    cout << countMove10 << "\t\t";
    cout << "\n";
    cout << "18000" << "\t\t";
    cout << duration13<<"ms" << "\t\t";
    cout << countComp13 << "\t";
    cout << countMove13 << "\t\t";
    cout << "\n";
    cout << "22000" << "\t\t";
    cout << duration16<<"ms" << "\t\t";
    cout << countComp16 << "\t";
    cout << countMove16 << "\t\t";
    cout << "\n";
    cout << "26000" << "\t\t";
    cout << duration19<<"ms" << "\t\t";
    cout << countComp19 << "\t";
    cout << countMove19 << "\t\t";
    cout << "\n";
    cout << "30000" << "\t\t";
    cout << duration22<<"ms" << "\t\t";
    cout << countComp22 << "\t";
    cout << countMove22 << "\t\t";
    cout << "\n";

//-------------------------------------------------------------------------------  

    cout <<"-----------------------------------------------------------------";
    cout << "\n";
    cout <<"Analysis of mergeSort:";
    cout << "\n";
    cout << "\n";
    cout << "Array Size\t";
    cout << "Time elapsed\t";
    cout << "countComp\t";
    cout << "countMove\t";
    cout << "\n";
    cout << "2000" << "\t\t";
    cout << duration2 << " ms" << "\t\t";
    cout << countComp2 << "\t\t";
    cout << countMove2 << "\t\t";
    cout << "\n";
    cout << "6000" << "\t\t";
    cout << duration5 << " ms" << "\t\t";
    cout << countComp5 << "\t\t";
    cout << countMove5 << "\t\t";
    cout << "\n";
    cout << "10000" << "\t\t";
    cout << duration8 << " ms" << "\t\t";
    cout << countComp8 << "\t\t";
    cout << countMove8 << "\t\t";
    cout << "\n";
    cout << "14000" << "\t\t";
    cout << duration11 << " ms" << "\t\t";
    cout << countComp11 << "\t\t";
    cout << countMove11 << "\t\t";
    cout << "\n";
    cout << "18000" << "\t\t";
    cout << duration14 <<" ms" << "\t\t";
    cout << countComp14 << "\t\t";
    cout << countMove14 << "\t\t";
    cout << "\n";
    cout << "22000" << "\t\t";
    cout << duration17 <<" ms" << "\t\t";
    cout << countComp17 << "\t\t";
    cout << countMove17 << "\t\t";
    cout << "\n";
    cout << "26000" << "\t\t";
    cout << duration20 <<" ms" << "\t\t";
    cout << countComp20 << "\t\t";
    cout << countMove20 << "\t\t";
    cout << "\n";
    cout << "30000" << "\t\t";
    cout << duration23 <<" ms" << "\t\t";
    cout << countComp23 << "\t\t";
    cout << countMove23 << "\t\t";
    cout << "\n";
    
//-------------------------------------------------------------------------------     
    cout <<"-----------------------------------------------------------------";
    cout << "\n";
    cout <<"Analysis of quickSort:";
    cout << "\n";
    cout << "\n";
    cout << "Array Size\t";
    cout << "Time elapsed\t";
    cout << "countComp\t";
    cout << "countMove\t";
    cout << "\n";
    cout << "2000" << "\t\t";
    cout << duration3 <<" ms" << "\t\t";
    cout << countComp3 << "\t\t";
    cout << countMove3 << "\t\t";
    cout << "\n";
    cout << "6000" << "\t\t";
    cout << duration6 <<" ms" << "\t\t";
    cout << countComp6 << "\t\t";
    cout << countMove6 << "\t\t";
    cout << "\n";
    cout << "10000" << "\t\t";
    cout << duration9 <<" ms" << "\t\t";
    cout << countMove9 << "\t\t";
    cout << countComp9 << "\t\t";
    cout << "\n";
    cout << "14000" << "\t\t";
    cout << duration12 <<" ms" << "\t\t";
    cout << countComp12 << "\t\t";
    cout << countMove12 << "\t\t";
    cout << "\n";
    cout << "18000" << "\t\t";
    cout << duration15 <<" ms" << "\t\t";
    cout << countComp15 << "\t\t";
    cout << countMove15 << "\t\t";
    cout << "\n";
    cout << "22000" << "\t\t";
    cout << duration18 <<" ms" << "\t\t";
    cout << countComp18 << "\t\t";
    cout << countMove18 << "\t\t";
    cout << "\n";
    cout << "26000" << "\t\t";
    cout << duration21 <<" ms" << "\t\t";
    cout << countComp21 << "\t\t";
    cout << countMove21 << "\t\t";
    cout << "\n";
    cout << "30000" << "\t\t";
    cout << duration24 <<" ms\t\t";
    cout << countComp24 << "\t\t";
    cout << countMove24 << "\t\t";
    cout << "\n";


    //-------------------------------------------------------------------------------     
    cout <<"-----------------------------------------------------------------";
    cout << "\n";
    cout <<"Analysis of radixSort:";
    cout << "\n";
    cout << "\n";
    cout << "Array Size\t";
    cout << "Time elapsed\t";

    cout << "\n";
    cout << "2000" << "\t\t";
    cout << duration25 <<" ms" << "\t\t";

    cout << "\n";
    cout << "6000" << "\t\t";
    cout << duration26 <<" ms" << "\t\t";

    cout << "\n";
    cout << "10000" << "\t\t";
    cout << duration27 <<" ms" << "\t\t";

    cout << "\n";
    cout << "14000" << "\t\t";
    cout << duration28 <<" ms" << "\t\t";

    cout << "\n";
    cout << "18000" << "\t\t";
    cout << duration29 <<" ms" << "\t\t";

    cout << "\n";
    cout << "22000" << "\t\t";
    cout << duration30 <<" ms" << "\t\t";
   
    cout << "\n";
    cout << "26000" << "\t\t";
    cout << duration31 <<" ms" << "\t\t";
    
    cout << "\n";
    cout << "30000" << "\t\t";
    cout << duration32 <<" ms\t\t";
   
    cout << "\n";

}


//Printing array elements
void printArray(int *arr, int size){
    
    for (int i = 0; i < size; i++) {
        if(i == size-1)
            cout << arr[i];
        else
            cout << arr[i]<< ",";
    }
}