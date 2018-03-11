#include <assert.h>
#include <iostream>

#include "binary-tree.h"

int main(int argc, char* argv[])
{
    BinaryTree tree;

    assert(tree.append(0));
    assert(!tree.append(0));

    assert(tree.size() == 1);

    tree.remove(0);

    assert(tree.size() == 0);

    assert(tree.append(54));
    assert(tree.append(20));
    assert(tree.append(37));
    assert(tree.append(50));
    assert(tree.append(84));
    assert(tree.append(13));

    assert(tree.size() == 6);

    tree.remove(50);

    assert(tree.size() == 5);

    assert(!tree.contains(1000));
    assert(tree.contains(13));

    assert(tree.size() == 5);
    tree.clean();
    assert(tree.size() == 0);

    std::cout << "Done!\n";
    return 0;
} 