#include <iostream>

#include "MinHeap.h"
#include "MaxHeap.h"
#include "MedianHeap.h"

using namespace std;
int main() {
    cout<<"----- max_heap -------"<<endl;
    MaxHeap heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(15);
    heap.insert(5);
    heap.insert(30);
    heap.insert(25);
    heap.insert(6);
    heap.insert(2);
    heap.insert(26);
    cout<<"max:"<<heap.peek()<<endl;
    cout<<"size:"<<heap.size()<<endl;
    cout<<"deleted:"<<heap.extractMax()<<endl;
    cout<<"size:"<<heap.size()<<endl;

    cout<<"----- min_heap -------"<<endl;
    MinHeap heap2;
    heap2.insert(10);
    heap2.insert(20);
    heap2.insert(15);
    heap2.insert(5);
    heap2.insert(30);
    heap2.insert(25);
    heap2.insert(6);
    heap2.insert(2);
    heap2.insert(26);
    cout<<"max:"<<heap2.peek()<<endl;
    cout<<"size:"<<heap2.size()<<endl;
    cout<<"deleted:"<<heap2.extractMin()<<endl;
    cout<<"size:"<<heap2.size()<<endl;

    cout<<"----- odd median_heap -------"<<endl;
    MedianHeap heap3;
    MedianHeap heap4;
    heap3.insert(10);
    heap3.insert(20);
    heap3.insert(15);
    heap3.insert(5);
    heap3.insert(30);
    heap3.insert(25);
    heap3.insert(6);
    heap3.insert(2);
    heap3.insert(26);
    cout<<"median:"<< heap3.findMedian()<<endl;

    cout<<"----- even median_heap -------"<<endl;
    heap4.insert(10);
    heap4.insert(20);
    heap4.insert(15);
    heap4.insert(5);
    heap4.insert(30);
    heap4.insert(25);
    heap4.insert(6);
    heap4.insert(2);
    heap4.insert(26);
    heap4.insert(16);
    cout<<"median:"<< heap4.findMedian()<<endl;

    return 0;
}
