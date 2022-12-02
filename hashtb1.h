#pragma warning( disable : 4290 )
#include <stdexcept>
#include <new>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "listlnk.cpp"
using namespace std;


template < class T, class KF >
class HashTbl
{
public:
    HashTbl(int initTableSize);
    ~HashTbl();
    int hash(string key);//new add

    void insert(const T& newDataItem) throw (bad_alloc);
    bool remove(KF searchKey);
    bool retrieve(KF searchKey, T& dataItem);
    void clear();

    bool isEmpty() const;
    bool isFull() const;

    void showStructure() const;

private:
    int tableSize;
    List<T>* dataTable;
};