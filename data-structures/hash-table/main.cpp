#include <iostream>
#include <assert.h>

#include "hash-table.h"

int main(int argc, char* argv[]) 
{
    HashTable table;

    table.insert("first value", 10);
    table.insert("second value", 34895);
    table.insert("first value", 11);

    assert(table.size() == 2);

    assert(table.value("first value") == 11);
    assert(table.value("non existing value") == 0);
    assert(table.value("another non existing value", 1245) == 1245);

    assert(table.size() == 2);

    table.remove("first value");
    table.remove("second value");
    table.remove("some value never inserted");

    assert(table.size() == 0);

    table.insert("foo", 100);
    table.insert("bar", 15);
    table.insert("lol", 11);
    table.insert("asd", 234);
    table.insert("wasd", 59);
    table.insert("space", 0);
    table.insert("lotr", 45);

    assert(table.contains("foo"));
    assert(table.contains("bar"));
    assert(table.contains("lol"));
    assert(table.contains("asd"));
    assert(table.contains("wasd"));
    assert(table.contains("space"));
    assert(table.contains("lotr"));
    assert(!table.contains("some key never added"));

    assert(table.size() == 7);

    table.clear();

    assert(table.size() == 0);
    
    std::cout << "Done!\n";
    return 0;
}