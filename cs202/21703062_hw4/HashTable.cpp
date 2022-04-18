/*
* Title : Hashing
* Author : Alper Kandemir
* ID : 21703062
* Section : 1
* Assignment : 4
* Description : HashTable functions 

*/#include <iostream>
using namespace std;
#include "HashTable.h"

HashTable::HashTable(const int tableSize, const CollisionStrategy option){
    hashTable= new int[tableSize];
    isEmpty= new bool[tableSize];
    for(int i =0; i <tableSize;i++){
        hashTable[i] = 0;                   //initially all items are 0
    }
    for(int i =0; i <tableSize;i++){
        isEmpty[i]= true;                   //initially all locations are available for inserting
    }
    this->tableSize=tableSize;
    this->option=option;

}
HashTable::~HashTable(){
    delete [] hashTable;
    delete [] isEmpty;
}

bool HashTable::insert(const int item){
    if (item==0){
        cout<<"0 cannot be added"<<endl;
        return false;
    }
    else {
        for (int i = 0; i < tableSize; ++i) {
            if (hashTable[i] == item) {
                cout << "Item:"<<item<<" is already exist" << endl;
                return false;
            }
        }
    }
    int i = hashPrimary(item);
    if(isEmpty[i]){
        hashTable[i]=item;
        isEmpty[i]=false;
        return true;
    }
        //collision occurs
    else{
        i = collisionHash(item);
        //cout<<"i:"<<i<<endl;
        if(isEmpty[i]){
            hashTable[i]=item;
            isEmpty[i]=false;
            return true;
        }
        else
            return false;
    }
}
bool HashTable::remove(const int item){
    for(int i =0;i<tableSize; i++){
        if(hashTable[i]==item){
            hashTable[i]=0;
            isEmpty[i]=true;
            return true;
        }
    }
    return false;
}
bool HashTable::search(const int item,int&numProbes){
    numProbes=1;
    int result=item % tableSize;
    int index = hashPrimary(item);
    if(hashTable[index] == item){

        //cout << "Item:" << item<<endl;
        //cout << "Succ search" << "number of probes:" << numProbes << endl;

        return true;
    }
    else{
        if(option == LINEAR){
            for(int i=0; i<tableSize;i++) {

                if (hashTable[result] != item) {
                    result = (index + (i + 1)) % tableSize;

                } else{
                    //cout << "Item:" << item << endl;
                    //cout << "Succ search" << "number of probes:" << numProbes << endl;
                    return true;
                }
                numProbes++;
            }
        }
        else if(option == QUADRATIC){
            for(int i=1; i<tableSize;i++) {

                if (hashTable[result] != item) {
                    result = (index+(i * i)) % tableSize;

                } else{
                    //cout << "Item:" << item << endl;
                    //cout << "Succ search" << "number of probes:" << numProbes << endl;
                    return true;
                }
                numProbes++;
            }
        }
        else if(option == DOUBLE){
            for(int i=1; i<tableSize;i++) {

                if (hashTable[result] != item) {
                    result= (i*doubleHash(item)) % tableSize;

                } else{
                    //cout << "Item:" << item << endl;
                    //cout << "Succ search" << "number of probes:" << numProbes << endl;
                    return true;
                }
                numProbes++;
            }
        }
    }
    numProbes--;
    //cout << "Item:" << item<<endl;
    //cout << "Unsucc search " << "number of probes:" << numProbes << endl;
    return false;
}
void HashTable::display(){
    int item=0;
    for(int i = 0; i < tableSize; i++){
        item = hashTable[i];
        if (isEmpty[i])
            cout<<i<<":"<<"\n";
        else
            cout << i << ": " << item << "\n";
    }
}


//primary hash function
int HashTable::hashPrimary(const int item){
    if(item >= 0){
        return item % tableSize;
    }
    else{
        return ((item % tableSize) + tableSize) % tableSize;
    }
}


int HashTable::collisionHash(const int item){
    int index =item % tableSize;
    int result=item % tableSize;

    if(option == LINEAR){
        for(int i=0; i<tableSize;i++) {
            if (!isEmpty[result]){
                result = (index+(i + 1)) % tableSize;
                //cout<<"result:"<<result<<endl;
                //cout<<"hashTable[result]:"<<hashTable[result]<<endl;
                //cout<<"isEmpty[result]:"<<isEmpty[result]<<""<<endl;
            }
            else
                return  result;
        }
    }
    if(option== QUADRATIC){
        for(int i=1; i<tableSize;i++) {
            if (!isEmpty[result]) {
                result = (index+(i * i)) % tableSize;
                //cout<<item<<","<<result<<endl;
            }
            else
                return  result;
        }
    }
    if(option== DOUBLE){
        for(int i=1; i<tableSize;i++) {
            if (!isEmpty[result]) {
                result= (i*doubleHash(item)) % tableSize;
                //cout<<item<<","<<result<<endl;
            }
            else
                return  result;
        }
    }
}
//reverse the digits of the item
int HashTable::doubleHash(const int item){
    int tempItem=item;
    int result=0;
    int temp = 0;
    while(tempItem != 0){
        temp = tempItem % 10;
        result = temp + (result * 10);
        tempItem = tempItem / 10;
    }
    if(item < 0){
        result=result * -1;
    }
    return result;
}


void HashTable::analyze(double& numSuccProbes,double& numUnSuccProbes){
    numSuccProbes=0;
    numUnSuccProbes=0;
    double size = 0;
    int probes = 0;
    // successful search
    for (int i = 0; i <tableSize ; i++) {
        if (!isEmpty[i]){                               //check not empty index
            size++;                                     //update number of values
            search(hashTable[i],probes);       //get number of probes
            numSuccProbes=numSuccProbes + probes;       //add to succ probes
            //cout<<"probes:"<<probes<<endl;
            //cout<<"numSuccProbes:"<<numSuccProbes<<endl;
            //cout<<"size:"<<size<<endl;
        }
    }
    numSuccProbes=numSuccProbes/size;


    // unsuccessful search

    if (option==LINEAR){
        for (int i = 0; i <tableSize ; i++) {
            if (isEmpty[i]){
                numUnSuccProbes = numUnSuccProbes + probes;
                probes=1;
            }
            else{
                int j = i;
                for (int k = 0; k <tableSize ; k++) {
                    if (!isEmpty[j]) {                  //find next free location
                        probes++;
                        j=(j+1)%tableSize;
                    } else
                        break;
                }
                numUnSuccProbes=numUnSuccProbes+probes;
                //cout<<"probes:"<<probes<<endl;
                //cout<<"item:"<<hashTable[i]<<endl;
                probes=1;
            }
        }
    }

    else if(option==QUADRATIC){
        for (int i = 0; i <tableSize ; i++) {
            if (isEmpty[i]){
                numUnSuccProbes = numUnSuccProbes + probes;
                probes=1;
            }
            else{
                int j = i;
                for (int k = 0; k <tableSize ; k++) {
                    if (!isEmpty[j]) {
                        probes++;                       //find next free location
                        j = (i+(j * j)) % tableSize;
                    } else
                        break;
                }
                numUnSuccProbes=numUnSuccProbes+probes;
                //cout<<"probes:"<<probes<<endl;
                //cout<<"item:"<<hashTable[i]<<endl;
                probes=1;
            }
        }
    }
    else{
        numUnSuccProbes=-1;
    }

    //cout<<"numUnSuccProbes:"<<numUnSuccProbes<<endl;
    numUnSuccProbes=numUnSuccProbes/(double)tableSize;

}
