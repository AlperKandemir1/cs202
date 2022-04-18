/*
* Title : Heaps and AVL Trees
* Author : alper kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : median heap header that use max and min heap. 
*/
#pragma once
#include "MaxHeap.h"
#include "MinHeap.h"

#include <iostream>
using namespace std;
class MedianHeap {
public:
    MedianHeap();
    void insert (int value );   // inserts an element into median heap
    int findMedian(); 		// returns the value of the median

private:
    int arrSize;            	//number of heap items
    int median;			//median variable
    MaxHeap maxHeap;		//max heap  
    MinHeap minHeap;		//min heap
};


