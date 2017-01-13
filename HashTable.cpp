//
//  HashTable.cpp
//  Practice_HashTable
//
//  Created by Christopher Watson on 10/25/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include "HashTable.hpp"
#include <iostream>
HashTable::HashTable(int size){
    
    array = new LinkedList[size];
    sizeOfTable = size;
    
}

HashTable::~HashTable(){
    
    delete [] array;
    sizeOfTable = 0;
    
}

void HashTable::insertItem(Item *newItem){
    
    int index = hash(newItem->key);
    array[index].insertItem(newItem);
}

bool HashTable::removeItem(std::string itemName){
    
    int index = hash(itemName);
    
    return array[index].removeItem(itemName);
    
}

int HashTable::hash(std::string itemKey){
   
    int value(0);
    for (int i(0); i < itemKey.length(); ++i){
        value += itemKey[i];
    }
    value = (value * itemKey.length()) % sizeOfTable;
    if (value > 6 && value < 11){
        ++value;
    }
    
    return value;
}

void HashTable::printHashTable(){
    
    for (int i(0); i < sizeOfTable; ++i){
        std::cout << "Index " << i << ": ";
        array[i].printItemChain();
        
    }
    std::cout << "\n ====================================";
    
}

void HashTable::printHistogram(){
    
    for (int i(0); i < sizeOfTable; ++i){
        std::cout << "\n\tIndex " << i << ": ";
        
        for (int j(0); j < array[i].getSize(); ++j){
            std:: cout << " X";
            
        }
    }
    std::cout << "\n\n";
}
