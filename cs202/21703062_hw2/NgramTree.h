/**
* Title: Trees
* Author: alper kandemir
* ID: 21703062
* Assignment: 2
* Description: tree functions header
*/


#include "BinaryNode.h"
using namespace std;

class NgramTree {

public:
    NgramTree();
    ~NgramTree();

    void addNgram( string ngram );
    int getTotalNgramCount();
    bool isComplete();
    bool isFull();
    void generateTree( string fileName, int n );
    int getHeight();
    void inorderTraverse();
private:
    BinaryNode* root;
    void destroyTree(BinaryNode*& root);
    void addNgram( string ngram,BinaryNode*& root );
    void getTotalNgramCount(BinaryNode*& root,int &counter);
    bool isComplete(BinaryNode*& root);
    bool isFull(BinaryNode*& root);
    int getHeight(BinaryNode*& node);
    void inorderTraverse(BinaryNode* root);

    friend ostream& operator<<( ostream& out, NgramTree& tree );


};

