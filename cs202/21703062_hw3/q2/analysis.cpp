//
// Created by MacBook Pro on 2.12.2021.
//


#include "AVLTree.h"
int n1;
int n2;
int n3;


void experiment(int size){
    AVLTree tree;
    AVLTree tree2;
    AVLTree tree3;

    for (int i = 0; i <size ; ++i) {
        tree.insert(rand() % 1000000);

    }

    n1=tree.getNumberOfRotations();

    for (int i = 0; i < size; i++) {

        tree2.insert(i);

    }
    n2 = tree2.getNumberOfRotations();
    for (int i = 0; i < size; i++) {

        tree3.insert((i - size)* - 1);

    }
    n3 = tree3.getNumberOfRotations();
}

void rotationAnalysis(){
    int size;
    size=1000;
    experiment(size);

    cout<< "arrSize"<<"\t"<<"Random"<<"\t"<<"Ascending"<<"\t"<<"Descending"<<"\n";

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";

    size=2000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";

    size=3000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";

    size=4000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";

    size=5000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";


    size=6000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";
    size=7000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";
    size=8000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";
    size=9000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";

    size=10000;
    experiment(size);

    cout<< size<<"\t"<<n1<<"\t"<<n2<<"\t\t"<<n3<<"\n";
}