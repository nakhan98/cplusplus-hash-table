/* C++ Hash Table
 * https://www.youtube.com/watch?v=m6n_rozU8dA
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

int main(int argc, char ** argv) {
    hash Hashy;
    string name = "";

    Hashy.AddItem("Jerry", "Coca Cola");
    Hashy.AddItem("Sheldon", "Green Tea");
    Hashy.AddItem("Steve", "Pepsi Cola");
    Hashy.AddItem("Abdullah", "Orange juice");
    Hashy.AddItem("Marco", "Water");
    Hashy.AddItem("Don", "Coffee");
    Hashy.AddItem("Qiang", "Tea");
    Hashy.AddItem("Yan", "Seven-up");
    Hashy.AddItem("Nina", "Mineral Water");
    Hashy.AddItem("Peter", "Hot Chocolate");
    Hashy.AddItem("Anna", "Diet Coke");
    Hashy.AddItem("Albert", "Green Tea");
    Hashy.AddItem("James", "Fanta");
    Hashy.AddItem("Nasef", "Sprite");

    //Hashy.PrintTable();
    //Hashy.PrintItemsInIndex(2);
    //Hashy.PrintItemsInIndex(7);
    //Hashy.PrintItemsInIndex(3);
    
    //Hashy.PrintTable();
    Hashy.PrintItemsInIndex(0);
    
    while (name != "exit") {
        cout << "Remove ";
        cin >> name;
        if (name != "exit")
            Hashy.RemoveItem(name);
    }

    //Hashy.PrintTable();
    Hashy.PrintItemsInIndex(0);

    return 0;
}
