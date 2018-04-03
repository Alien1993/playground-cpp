#include <assert.h>
#include <iostream>

#include "lru_cache.h"

int main(int argc, char* argv[])
{
    LRUCache cache(4);

    assert(cache.get(100) == "");

    cache.set(1, "Qui Gon Jinn");
    cache.set(5, "Anakin Skywalker");
    cache.set(28, "Leia Organa");
    cache.set(10, "Han Solo");

    assert(cache.get(1) == "Qui Gon Jinn");
    assert(cache.get(5) == "Anakin Skywalker");
    assert(cache.get(10) == "Han Solo");
    assert(cache.get(28) == "Leia Organa");

    cache.set(5, "Darth Vader");

    assert(cache.get(1) == "Qui Gon Jinn");
    assert(cache.get(5) == "Darth Vader");
    assert(cache.get(10) == "Han Solo");
    assert(cache.get(28) == "Leia Organa");

    cache.set(100, "Darth Maul");

    assert(cache.get(1) == "");
    assert(cache.get(5) == "Darth Vader");
    assert(cache.get(10) == "Han Solo");
    assert(cache.get(28) == "Leia Organa");
    assert(cache.get(100) == "Darth Maul");

    cache.get(5);
    cache.get(100);
    cache.get(28);

    cache.set(47, "Ben Solo");

    assert(cache.get(1) == "");
    assert(cache.get(5) == "Darth Vader");
    assert(cache.get(10) == "");
    assert(cache.get(28) == "Leia Organa");
    assert(cache.get(100) == "Darth Maul");
    assert(cache.get(47) == "Ben Solo");

    std::cout << "Done!\n";
    return 0;
}
