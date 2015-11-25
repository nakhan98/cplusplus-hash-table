#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

hash::hash() {
    for (int i=0; i < tableSize; i++) {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
    }
}

void hash::AddItem(string name, string drink) {
    int index = Hash(name);
    
    if (HashTable[index]->name == "empty") {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else {
        item * Ptr = HashTable[index]; //first item in bunket!
        // Create new item
        item * n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;

        while(Ptr->next != NULL) {
            Ptr = Ptr->next;
        }
        Ptr->next = n;
    }
}

int hash::NumberOfItemsinIndex(int index) {
    int count = 0;

    if (HashTable[index]->name == "empty")
        return count;
    else {
        count++;
        item * Ptr = HashTable[index];
        while (Ptr->next != NULL) {
            count++;
            Ptr = Ptr->next;
        }
    }
    return count;
}

void hash::PrintTable() {
    int number;
    for (int i=0; i<tableSize; i++) {
        number = NumberOfItemsinIndex(i);
        cout << "---------------------\n";
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "Number of items = " << number << endl;
        cout << "---------------------\n";
    }
}

void hash::PrintItemsInIndex(int index) {
    item * Ptr = HashTable[index];
    if (Ptr->name == "empty")
        cout << "index = " << index << " is empty\n";
    else {
        cout << "index = " << index << " contains the following items\n";
        while (Ptr != NULL) {
            cout << "-----------------\n";
            cout << Ptr->name << endl;
            cout << Ptr->drink << endl;
            cout << "-----------------\n";
            Ptr = Ptr->next;
        }
    }
}

int hash::Hash(string key) {
    int hash = 0;
    int index;

    for (int i=0; i < key.length(); i++) {
        //hash += (int)key[i];
        hash = (hash + (int)key[i]) * 7;
        //cout << "hash = " << hash << endl;
    }

    index = hash % tableSize;

    return index;
}

void hash::FindDrink(string name) {
    int index = Hash(name);
    bool foundName = false;
    string drink;
    item * Ptr = HashTable[index];
    while (Ptr != NULL) {
        if (Ptr->name == name) {
            foundName = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    if (foundName)
        cout << "Favourite drink = " << drink << endl;
    else 
        cout << "No info found for " << name << " in the Hash Table" << endl;
}

void hash::RemoveItem(string name) {
    int index = Hash(name);        
    item * delPtr;
    item * P1;
    item * P2;

    /* 
     * Case 0 - bucket/index is empty
     * Case 1 - Only 1 item in the bucket/index, has matching name
     * Case 2 - Match is location in the first item in the bucket, but there
     * are more items in the bucket.
     * Case 3 - bucket contains items but first item is not a match.
     *      Case 3.1  - no match
     *      Case 3.2  - match is found
     */
    
    // Case 0
    if (HashTable[index]->name == "empty" && HashTable[index]->drink ==
            "empty") {    
        cout << name << "was not found in the Hash Table" << endl;
    }
    // Case 1
    else if (HashTable[index]->name == name && HashTable[index]->next ==
            NULL) {
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";

        cout << name << " was removed from the Hash Table" << endl;
    }
    // Case 2
    else if (HashTable[index]->name == name) {
        delPtr = HashTable[index];
        //HashTable[index] = HashTable[index]->next;
        HashTable[index] = delPtr->next;
        delete delPtr;
        cout << name << " was removed from the Hash Table" << endl;
    }
    // Case 3
    else {
        P1 = HashTable[index]->next;
        P2 = HashTable[index];

        while (P1 != NULL && P1->name != name) {
            P2 = P1;
            P1 = P1->next;
        }
        // Case 3.1
        if (P1 == NULL)
            cout << name << "was not found in the Hash Table" << endl;
        // Case 3.2
        else {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;

            delete delPtr;
            cout << name << " was removed from the Hash Table" << endl;
        }
    }
}
