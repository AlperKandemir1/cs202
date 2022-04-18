/*
* Title : Heaps and AVL Trees
* Author : alper kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : median heap functions that use max and min heap. 
* logic is if value less than median, insert maxheap.
*/

#include "MedianHeap.h"

MedianHeap::MedianHeap(){
    arrSize=0;
    median=0;
}

void MedianHeap::insert(int value){
    //choosing insertion heap type
    if (value< median){
        maxHeap.insert(value);
    }
    else{
        minHeap.insert(value);
    }

    //balance heaps
    if (maxHeap.size()-minHeap.size()>1 || maxHeap.size()-minHeap.size()<-1){
        if (maxHeap.size()>minHeap.size()){
            minHeap.insert(maxHeap.peek());
            maxHeap.extractMax();
        }
        else{
            maxHeap.insert(minHeap.peek());
            minHeap.extractMin();
        }
    }
    //finding median
    if (minHeap.size()<maxHeap.size()){
        median = maxHeap.peek();
    }
    else if (minHeap.size()>maxHeap.size()){
        median = minHeap.peek();
    }
    else
        median = ((minHeap.peek()+maxHeap.peek()) / 2) + 1;

}

int MedianHeap::findMedian(){
    return median;
}

