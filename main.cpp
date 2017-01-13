//
//  main.cpp
//  Practice_HashTable
//
//  Created by Christopher Watson on 10/25/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include <iostream>
#include "HashTable.hpp"

int main(int argc, const char * argv[]) {

    Item** itemArray =  new Item*[12];
    std::string stringArray[12] = {"Mark", "John", "Jacob", "Alvarez", "Roger", "Yoyo", "Larry", "Paul", "Richard", "Leo", "Carl", "Indigo"};
    for (int i(0); i < 12; ++i){
        itemArray[i] = new Item {stringArray[i], NULL};
    }
    
    HashTable firstTable;
    
    for (int i(0); i < 12; ++i){
        Item *addItem = itemArray[i];
        firstTable.insertItem(addItem);
    }
    
    firstTable.printHashTable();
    
    firstTable.printHistogram();
    
    
    
    
    firstTable.removeItem("Yoyo");
    
    firstTable.removeItem("Captain");
    
    firstTable.printHashTable();
    firstTable.printHistogram();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*====WORKING LINKED LIST TEST SECTION========
    LinkedList firstList;
    
    for (int i(0); i < 12; ++i){
        Item *addItem = itemArray[i];
        firstList.insertItem(addItem);
    }
    
    firstList.printItemChain();
    Item *C = firstList.getItem("Ron");
    std::cout << C->key << std::endl;
    
    firstList.removeItem("Joe");
    firstList.printItemChain();
    ==============END TEST SECTION==============*/
    return 0;
}
