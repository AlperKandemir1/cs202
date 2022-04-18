/*
* Title : Hashing
* Author : Alper Kandemir
* ID : 21703062
* Section : 1
* Assignment : 4
* Description : HashTable header
*/


enum CollisionStrategy{LINEAR, QUADRATIC,DOUBLE};
class HashTable {
public:

    HashTable(const int tableSize, const CollisionStrategy option);
    ~HashTable();

    bool insert(const int item);
    bool remove(const int item);
    bool search(const int item,int&numProbes);
    void display();
    void analyze(double& numSuccProbes,double& numUnSuccProbes);
    int hashPrimary(const int item);
    int collisionHash(const int item);
    int doubleHash(const int item);
private:
    CollisionStrategy option;
    int* hashTable;
    int tableSize;
    bool* isEmpty;

};

