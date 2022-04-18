/**
* Title: Trees
* Author: alper kandemir
* ID: 21703062
* Assignment: 2
* Description: tree functions 
*/

#include <iostream>
#include <fstream>
#include "NgramTree.h"
using namespace std;



// Default constructor
NgramTree::NgramTree() : root(NULL) {

}
NgramTree::~NgramTree(){
    destroyTree(root);
}

void NgramTree::destroyTree(BinaryNode*& root){

    if (root != NULL){
        destroyTree(root->leftChildPtr);
        destroyTree(root->rightChildPtr);
        delete root;
        root = NULL;

    }
}

void NgramTree::addNgram( string ngram ){

    addNgram( ngram,root );
}

void NgramTree::addNgram( string ngram,BinaryNode*& rootPtr ){

    if(rootPtr == NULL){

        rootPtr = new BinaryNode();
        rootPtr->item=ngram;
	rootPtr->leftChildPtr=NULL;
	rootPtr->rightChildPtr=NULL;
        //cout<<rootPtr->item;
        //cout<<" ";
        rootPtr->count=1;
    }
    else if (rootPtr->item.compare(ngram)<0)
    {
        addNgram(ngram,rootPtr->leftChildPtr);
    }
    else if (rootPtr->item.compare(ngram)>0){
        addNgram(ngram,rootPtr->rightChildPtr);
    }
    else if (rootPtr->item.compare(ngram)==0)
    {   //repeated
        rootPtr->count++;
        //cout<<"    repeated"<<rootPtr->count<<"    ";
        //cout<<"    repeated"<<rootPtr->item<<"    ";
    }
}

int NgramTree::getTotalNgramCount(){
    int counter = 0;
    getTotalNgramCount(root,counter);
    return counter;
}
void NgramTree::getTotalNgramCount(BinaryNode*& rootptr,int &counter){

    if(rootptr== NULL){
        return;
    }
    else{
        getTotalNgramCount(rootptr->leftChildPtr,counter);
        getTotalNgramCount(rootptr->rightChildPtr,counter);
        counter++;
    }
}


bool NgramTree::isComplete(){
    return isComplete(root);
}
bool NgramTree::isComplete(BinaryNode*& rootptr){
    int result1;
    int result2;
    int result3;
    if (rootptr == NULL)
        return true;
    if(rootptr->leftChildPtr != NULL && rootptr->rightChildPtr != NULL){
        result1 = getHeight(rootptr->leftChildPtr);
        result2 = getHeight(rootptr->rightChildPtr);
        result3=result1-result2;
        if(result3==-1 || result3==1 || result3==0)
        	return true;
	else
		return false;
    }
    if(rootptr->leftChildPtr == NULL && rootptr->rightChildPtr == NULL){
        return true;
    }

    return false;
}



void NgramTree::generateTree( string fileName, int n ){
        bool flag;
        string control;
        string input;
        ifstream file;
        file.open( fileName);

        while(file>>input) {
            if(input.size()>=n){
            for(int k=0; k<(input.size()-n)+1; k++){
                control=input.substr(k,n);
                //cout<<" ";
                for(int i=0; i<n;i++){
                   if(control[i]==' '){
                       flag=false;
                       break;
                    }
                   else
                        flag=true;
                }
                if(flag)
                    addNgram(control);
            }
        }
            
        }
}
int NgramTree::getHeight(){
    return getHeight(root);
    }
int NgramTree::getHeight(BinaryNode*& rootptr){
    if(rootptr!=NULL){
        int leftHeight= getHeight(rootptr->leftChildPtr);
        int rightHeight= getHeight(rootptr->rightChildPtr);
        return max(leftHeight, rightHeight) + 1;
    }
    else
        return -1;
}

bool NgramTree::isFull(){
    return isFull(root);
}
bool NgramTree::isFull(BinaryNode*& rootptr){
    int result1;
    int result2;
    if (rootptr == NULL)
        return true;
    if(rootptr->leftChildPtr != NULL && rootptr->rightChildPtr != NULL){
        result1 = getHeight(rootptr->leftChildPtr);
        result2 = getHeight(rootptr->rightChildPtr);
        return (result1==result2);
    }
    if(rootptr->leftChildPtr == NULL && rootptr->rightChildPtr == NULL){
        return true;
    }

    return false;
}

//string NgramTree::getData(){
    //return root->item;
//}

void NgramTree::inorderTraverse(BinaryNode* rootptr) {

    if (rootptr != NULL) {

        inorderTraverse(rootptr->leftChildPtr);
        cout<<rootptr->item<<" appears "<<rootptr->count<<" time(s) "<<"\n";
        inorderTraverse(rootptr->rightChildPtr);
    }
}


//-----------------------------------------------------------------------------------------------
ostream& operator <<( ostream& out, NgramTree& tree ){
    tree.inorderTraverse(tree.root);
    out << endl;

    return out;
}