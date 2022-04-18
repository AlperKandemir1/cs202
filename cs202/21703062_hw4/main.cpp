/*
* Title : Hashing
* Author : Alper Kandemir
* ID : 21703062
* Section : 1
* Assignment : 4
* Description : Driver file
*/
#include <iostream>
#include <string>
using namespace std;
#include "HashTable.h"
#include <fstream>
int main( int argc, char **argv ) {
    int probes;
    double succ=0;
    double unSucc=0;
    int lines=0;
    ifstream file;
    string fileName( argv[1] );
    int n = atoi( argv[2] );
    file.open( fileName);
    string input;
    while(getline(file,input)) {

        lines++;
    }
    file.close();
    HashTable table1(n,LINEAR);
    HashTable table2(n,QUADRATIC);
    HashTable table3(n,DOUBLE);

    string* operations = new string [lines];
    int* item = new int[lines];
    int counter=0;
    file.open( fileName);
    while (getline(file,input)){
        operations[counter]=input.substr(0,1);
        item[counter]=stoi(input.substr(2,input.size()));
        counter++;
    }
    //LINEAR
    cout<< "-------------------------------LINEAR-------------------------------"<<endl;
    for (int i = 0; i <lines; ++i) {
        if (operations[i]=="I"){
            if (!table1.insert(item[i])){
                cout<< item[i]<<" not inserted"<<endl;
            }
            else
                cout<< item[i]<<" inserted"<<endl;
        }
        if (operations[i]=="R"){
            if (!table1.remove(item[i])){
                cout<< item[i]<<" not removed"<<endl;
            }
            else
                cout<< item[i]<<" removed"<<endl;


        }
        if (operations[i]=="S"){
            if (!table1.search(item[i],probes)){
                cout<< item[i]<<" not found after "<<probes<<endl;
            }
            else
                cout<< item[i]<<" found after "<<probes<<endl;
        }
    }
    table1.display();
    cout <<"Table size: "<<n << endl;
    table1.analyze(succ,unSucc);
    cout <<"successful search: "<<succ << endl;
    cout <<"unsuccessful search: "<<unSucc << endl;


//QUADRATIC
    cout<< "-------------------------------QUADRATIC-------------------------------"<<endl;

    for (int i = 0; i <lines; ++i) {
        if (operations[i]=="I"){
            if (!table2.insert(item[i])){
                cout<< item[i]<<" not inserted"<<endl;
            }
            else
                cout<< item[i]<<" inserted"<<endl;
        }
        if (operations[i]=="R"){
            if (!table2.remove(item[i])){
                cout<< item[i]<<" not removed"<<endl;
            }
            else
                cout<< item[i]<<" removed"<<endl;


        }
        if (operations[i]=="S"){
            if (!table2.search(item[i],probes)){
                cout<< item[i]<<" not found after "<<probes<<endl;
            }
            else
                cout<< item[i]<<" found after "<<probes<<endl;
        }
    }
    table2.display();
    cout <<"Table size: "<<n << endl;
    table2.analyze(succ,unSucc);
    cout <<"successful search: "<<succ << endl;
    cout <<"unsuccessful search: "<<unSucc << endl;


    //DOUBLE
    cout<< "-------------------------------DOUBLE-------------------------------"<<endl;

    for (int i = 0; i <lines; ++i) {
        if (operations[i]=="I"){
            if (!table3.insert(item[i])){
                cout<< item[i]<<" not inserted"<<endl;
            }
            else
                cout<< item[i]<<" inserted"<<endl;
        }
        if (operations[i]=="R"){
            if (!table3.remove(item[i])){
                cout<< item[i]<<" not removed"<<endl;
            }
            else
                cout<< item[i]<<" removed"<<endl;


        }
        if (operations[i]=="S"){
            if (!table3.search(item[i],probes)){
                cout<< item[i]<<" not found after "<<probes<<endl;
            }
            else
                cout<< item[i]<<" found after "<<probes<<endl;
        }
    }
    table3.display();
    cout <<"Table size: "<<n << endl;
    table3.analyze(succ,unSucc);
    cout <<"successful search: "<<succ << endl;
    cout <<"unsuccessful search: -1"<< endl;


    return 0;
}
