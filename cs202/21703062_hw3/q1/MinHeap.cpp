/*
* Title : Heaps and AVL Trees
* Author : alper kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : minheap functions
*/
#include <iostream>
#include <fstream>
#include "MinHeap.h"
using namespace std;

// default constructor
MinHeap::MinHeap(){
    arrSize=0;
}

// inserts integer into heap
void MinHeap::insert (int value ){
    if (arrSize >= MIN_HEAP)
        cout<<("Heap is full");

    // Place the new item at the end of the heap
    items[arrSize] = value;

    // Trickle new item up to its proper position
    int place = arrSize;
    int parent = (place - 1)/2;
    while ( (place > 0) && (items[place] < items[parent]) ) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1)/2;
    }
    ++arrSize;
}

// returns the value of the max element
int MinHeap::peek (){
    if (arrSize==0){
        //cout<< "Heap is empty";
        return 0;
    }
    else
        return items[0];
}

// retrieves and removes the max element
int MinHeap::extractMin(){
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

void MinHeap::heapRebuild(int root) {
    int child = 2 * root + 1;    // index of root's left child, if any
    if (child < arrSize) {
        // root is not a leaf so that it has a left child
        int rightChild = child + 1;    // index of a right child, if any
        // If root has right child, find larger child
        if ((rightChild < arrSize) &&
            (items[rightChild] < items[child]))
            child = rightChild;    // index of larger child

        // If root’s item is bigger than larger child, swap values
        if (items[root] > items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            // transform the new subtree into a heap
            heapRebuild(child);
        }

    }
}

//returns the number of elements in the heap
int MinHeap::size (){
    return arrSize;
}
//returns whether the heap is empty or not
bool MinHeap::heapIsEmpty() const {
    return (arrSize == 0);
}
