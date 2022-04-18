/*
* Title : Heaps and AVL Trees
* Author : alper kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : min heap header
*/

#pragma once
const int MIN_HEAP = 9999;
#include <iostream>
using namespace std;
class MinHeap {
public:
    MinHeap();                  // default constructor
    void insert (int value );   // inserts integer into heap
    int peek ();                // returns the value of the max element
    int extractMin();           // retrieves and removes the max element
    int size ();                // returns the number of elements in the heap
    bool heapIsEmpty() const;
protected:
    void heapRebuild(int root);
private:

    int items[MIN_HEAP];    //array of heap items
    int arrSize;            //number of heap items

};


