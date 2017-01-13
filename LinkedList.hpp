//
//  LinkedList.hpp
//  Practice_HashTable
//
//  Created by Christopher Watson on 10/25/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <string>

struct Item {
    
    std::string key;
    Item *next;
    
};

class LinkedList{
    
public:
    LinkedList();
    ~LinkedList();
    
    void insertItem(Item *item);
    bool removeItem(std::string itemName);
    Item* getItem(std::string itemName);
    void printItemChain();
    int getSize();
    
private:
    
    Item *head;
    int size;
    
};

#endif /* LinkedList_hpp */
