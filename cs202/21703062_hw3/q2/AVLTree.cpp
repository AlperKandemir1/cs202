/*
* Title : Heaps and AVL Trees
* Author : Alper Kandemir
* ID : 21703062
* Section : 1
* Assignment : 3
* Description : avl tree functions
*/

#include "AVLTree.h"
#include <cstdlib>

//construction
AVLTree::AVLTree(){
    numberOfRotations=0;
    root=NULL;
}
AVLTree::~AVLTree(){
    destroyTree(root);
}

//delete the tree
void AVLTree::destroyTree(treeNode* root){

    if (root != NULL){
        destroyTree(root->leftChild);
        destroyTree(root->rightChild);
        delete root;
        root = NULL;

    }
}

//initialize the new node
AVLTree::treeNode* AVLTree::buildTreeNode(int value){
    treeNode* newNode=new treeNode;
    newNode->rightChild=NULL;
    newNode->leftChild=NULL;
    newNode->height=1;
    newNode->item=value;
    return newNode;

}


void AVLTree::insert(int value){

    root=insert(value,root);
}
AVLTree::treeNode* AVLTree::insert(int value,treeNode* rootPtr){

    int balanceFactor=0;
    if (rootPtr==NULL){
        //cout<<"value"<<value;
        rootPtr= buildTreeNode(value);

    }
    else if (rootPtr->item > value){
        rootPtr->leftChild=insert(value,rootPtr->leftChild);

    }
    else if (rootPtr->item < value){
        rootPtr->rightChild=insert(value,rootPtr->rightChild);

    }
    else{ //if equals
        //cout<<"value is already exits"<<endl;
        return rootPtr;
    }

    // 4-cases
    // right-right,left-left,
    // right-left,left-right;
    balanceFactor=getBalanceFactor(rootPtr);
    //cout<<"value"<<rootPtr->item<<endl;
    //cout<<"balanceFactor"<<balanceFactor<<endl;
    if (balanceFactor < -1){
        if (value > rootPtr->rightChild->item){
            numberOfRotations++;
            return leftRotate(rootPtr);
        }
        if (value < rootPtr->rightChild->item){
            numberOfRotations=numberOfRotations+2;
            rootPtr->rightChild= rightRotate(rootPtr->rightChild);
            return leftRotate(rootPtr);
        }
        else
            return rootPtr;
    }
    if (balanceFactor > 1){
        if (value < rootPtr->leftChild->item){
	    //increase the rotation	
            numberOfRotations++;
            return rightRotate(rootPtr);
        }
        if (value > rootPtr->leftChild->item){
	    //increase the rotation
            numberOfRotations=numberOfRotations+2;
            rootPtr->leftChild= leftRotate(rootPtr->leftChild);
            return rightRotate(rootPtr);
        }
        else
            return rootPtr;

    }
    return rootPtr;

}

// balance = left subtree-right subtree
int AVLTree::getBalanceFactor(treeNode *rootPtr) {
    int balanceFactor=0;
    if (rootPtr!=NULL){
        balanceFactor = getHeight(rootPtr->leftChild)-getHeight(rootPtr->rightChild);

    }
    return balanceFactor;
}

AVLTree::treeNode* AVLTree::rightRotate(treeNode* rootPtr){
    treeNode* ptr = rootPtr->leftChild;
    treeNode* ptr2 = ptr->rightChild;
    //rotate
    ptr->rightChild = rootPtr;
    rootPtr->leftChild = ptr2;
    return ptr;
}
AVLTree::treeNode* AVLTree::leftRotate(treeNode* rootPtr){
    treeNode* ptr = rootPtr->rightChild;
    treeNode* ptr2 = ptr->leftChild;
    //rotate
    ptr->leftChild = rootPtr;
    rootPtr->rightChild = ptr2;
    return ptr;
}
int AVLTree::getNumberOfRotations(){
    return numberOfRotations;
}

//get height functions from bst implemantation
int AVLTree::getHeight(treeNode* rootPtr){
    if(rootPtr!=NULL){
        int leftHeight= getHeight(rootPtr->leftChild);
        int rightHeight= getHeight(rootPtr->rightChild);
        return max(leftHeight,rightHeight)+1;
    }
    else
        return -1;
}









