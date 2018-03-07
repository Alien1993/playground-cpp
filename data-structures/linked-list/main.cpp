#include <assert.h>
#include <stdio.h>

#include "linked-list.h"

int main(int argc, char* argv[])
{
    LinkedList list{};

    assert(list.size() == 0);

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    assert(list.size() == 4);

    assert(list.pop() == 3);
    assert(list.pop() == 2);
    assert(list.pop() == 1);
    assert(list.pop() == 0);

    assert(list.size() == 0);

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    assert(list.removeAt(0));
    assert(list.removeAt(0));
    assert(list.removeAt(0));
    assert(list.removeAt(0));
    
    assert(list.size() == 0);

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    assert(!list.insert(10000, 0));
    assert(list.insert(2, 666));

    assert(list.pop() == 3);
    assert(list.pop() == 2);
    assert(list.pop() == 666);
    assert(list.pop() == 1);
    assert(list.pop() == 0);

    assert(list.size() == 0);

    assert(list.insert(0, 999));

    assert(list.pop() == 999);

    assert(list.size() == 0);

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    
    list.clean();
    
    assert(list.size() == 0);

    printf("Done\n");
    return 0;
}