/**
* Title: Trees
* Author: alper kandemir
* ID: 21703062
* Assignment: 2
* Description: headers
*/



#include <iostream>
using namespace std;

class BinaryNode{

private:

    BinaryNode();
    BinaryNode(string value,int countNum);
    ~BinaryNode();

    int count;
    string item;
    BinaryNode* leftChildPtr;
    BinaryNode* rightChildPtr;

    friend class NgramTree;
};