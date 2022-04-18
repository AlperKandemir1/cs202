/*
* Title : Heaps and AVL Trees
* Author : alper kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : max heap functions
*/
#include <iostream>
#include <fstream>
#include "MaxHeap.h"
using namespace std;

// default constructor
MaxHeap::MaxHeap(){
    arrSize=0;
}

// inserts integer into heap
void MaxHeap::insert (int value ){
    if (arrSize >= 9999)
        cout<<("Heap is full");

    // Place the new item at the end of the heap
    items[arrSize] = value;

    // Trickle new item up to its proper position
    int place = arrSize;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place] > items[parent]) ) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++arrSize;
}

// returns the value of the max element
int MaxHeap::peek (){
    if (arrSize==0){
        //cout<< "Heap is empty";
        return 0;
    }
    else
        return items[0];
}
//not used
int MaxHeap::peek2 (){

        return items[1];
}

// retrieves and removes the max element
int MaxHeap::extractMax(){
    int rootItem;
    if (heapIsEmpty())
        cout<< ("Heap is empty");
    else {
        rootItem = items[0];
        items[0] = items[--arrSize];
        heapRebuild(0);
    }
    return rootItem;
}

void MaxHeap::heapRebuild(int root) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < arrSize) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < arrSize) &&
            (items[rightChild] > items[child]))
            child = rightChild;    // index of larger child

        // If root’s item is smaller than larger child, swap values
        if (items[root] < items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }

    }
}

//returns the number of elements in the heap
int MaxHeap::size (){
    return arrSize;
}

bool MaxHeap::heapIsEmpty() const {
    return (arrSize == 0);
}
