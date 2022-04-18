/**
* Title: binarynode
* Author: alper kandemir
* ID: 21703062
* Assignment: 2
* Description: constructors
*/

/*
* Title: Binary Search Trees
* Author: alper kandemir
* ID: 21703062
* Assignment: 2
* Description: nodecpp
*/
#include <cstddef>
#include "BinaryNode.h"

//default constructor
BinaryNode::BinaryNode() {

}

//constructor
BinaryNode::BinaryNode(string value,int countNum) {
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    item = value;
    count=countNum;
}
BinaryNode::~BinaryNode() {

}

