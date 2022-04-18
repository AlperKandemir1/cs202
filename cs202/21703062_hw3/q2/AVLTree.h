/*
* Title : Heaps and AVL Trees
* Author : Alper Kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : avl tree header
*/

#include <iostream>
using namespace std;

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int value); 	//inserts an element into the tree
    int getNumberOfRotations(); //returns the number of rotations performed so far while constructing the tree


private:
    // node structure
    struct treeNode{

        treeNode* leftChild;
        treeNode* rightChild;
        int height;
        int item;
    };
    void destroyTree(treeNode* root);			//delete the tree
    treeNode* root;					
    treeNode* insert(int value,treeNode* rootPtr);	//inserts an element into the tree
    treeNode* buildTreeNode(int value);			//initialize the new node
    int getBalanceFactor(treeNode* rootPtr);		//check the balance
    int getHeight(treeNode* rootPtr);			//get height of the subtrees
    treeNode* rightRotate(treeNode* rootPtr);		//right rotation
    treeNode* leftRotate(treeNode* rootPtr);		//left rotation 
    int numberOfRotations;				//holds the rotation number

};

