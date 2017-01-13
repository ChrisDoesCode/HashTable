//
//  HashTable.hpp
//  Practice_HashTable
//
//  Created by Christopher Watson on 10/25/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "LinkedList.hpp"

class HashTable{
    
public:
    
    HashTable(int size=12);
    ~HashTable();
    
    void insertItem(Item *newItem);
    bool removeItem(std::string itemName);
    Item *getItem(std::string itemName);
    void printHashTable();
    void printHistogram();
    
private:
    LinkedList *array;
    int sizeOfTable;
    int hash(std::string itemKey);
    
    
};


#endif /* HashTable_hpp */
