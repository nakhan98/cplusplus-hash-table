#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class hash {
    public:
        hash(); //Constructor prototype
        int Hash(string key); 
        void AddItem(string name, string drink);
        int NumberOfItemsinIndex(int index);
        void PrintTable();
        void PrintItemsInIndex(int index);
        void FindDrink(string name);
        void RemoveItem(string name);

    private:
        // static allows you to define it in class?
        static const int tableSize = 40;

        struct item {
            string name;
            string drink;
            item * next;
        };

        item * HashTable[tableSize];
};

#endif /* HASH_H */
