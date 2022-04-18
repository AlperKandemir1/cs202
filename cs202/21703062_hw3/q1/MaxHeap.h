/*
* Title : Heaps and AVL Trees
* Author : alper kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : max heap header file
*/


#pragma once
#include <iostream>
using namespace std;

class MaxHeap {
public:
    MaxHeap();                  //default constructor
    void insert (int value );   // inserts integer into heap
    int peek();                	// returns the value of the max element
    int peek2();		//not used tracing purpose only
    int extractMax();           // retrieves and removes the max element
    int size ();                // returns the number of elements in the heap
    bool heapIsEmpty() const;
protected:
    void heapRebuild(int root);
private:

    int items[9999];        //max size
    int arrSize;            //number of heap items

};

