//
//  LinkedList.cpp
//  Practice_HashTable
//
//  Created by Christopher Watson on 10/25/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList(){
    
    head = new Item;
    head->next = 0;
    size = 0;
}

LinkedList::~LinkedList(){
    Item *root = head;
    Item *temp;
    while (root != 0){
        temp = root->next;
        root = 0;
        root = temp;
    }
    head = 0;
    size = 0;
}

void LinkedList::insertItem(Item *item){
    Item *root = head;
    
    if (head->next ==  NULL){
        head->next = item;
    }
    else if (root->next){
        while (root->next){
            Item *temp = root->next;
            root = temp;
        }
        root->next = item;
    }
    ++size;
}

bool LinkedList::removeItem(std::string itemName){
    Item *root = head;
    if (root->next->key != itemName){
        while ((root->next != NULL) && (root->next->key != itemName)){
            Item *temp = root->next;
            root = temp;
        }
    }
    
    if ((root->next != NULL) && (root->next->key == itemName)){
        Item *temp = root->next;
        if (!temp->next){
            delete root->next;
            --size;
            return true;
        }
        else if (temp->next){
            delete root->next;
            root->next = temp->next;
            --size;
            return true;
        }
        
    }
    std::cout << "NOTICE: Item with name \"" + itemName + "\" does not exist." << std::endl;
    return false;
}

Item* LinkedList::getItem(std::string itemName){
    Item *returnMe;
    Item *root = head;
    if (root->next->key != itemName){
        while ((root->next != NULL) && (root->next->key != itemName)){
            Item *temp = root->next;
            root = temp;
        }
        
    }
    
    if ((root->next != NULL) && (root->next->key == itemName)){
        returnMe = root->next;
        return returnMe;
    }
    else {
        std::string nfString = "NOTICE: No record found for \"" + itemName + "\"";
        Item *notFound = new Item {nfString, NULL};
        return notFound;
    }
    
}

void LinkedList::printItemChain(){
    Item *root = head;
    std::cout << "{ ";
    while (root->next){
        std::cout << root->next->key;
        Item *temp = root->next;
        root = temp;
        if (root->next){
            std::cout << ", ";}
    }
    std::cout << " }" << std::endl;
}

int LinkedList::getSize(){
    return size;
}