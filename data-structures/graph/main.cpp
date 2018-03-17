#include <iostream>
#include <assert.h>

#include "graph.h"


int main(int argc, char* argv[])
{
    DirectedGraph graph;

    graph.createVertex("A");
    graph.createVertex("B");
    graph.createVertex("C");
    graph.createVertex("D");
    graph.createVertex("E");

    graph.createEdge("A", "B");
    graph.createEdge("A", "C");
    graph.createEdge("B", "C");
    graph.createEdge("B", "F");
    graph.createEdge("B", "D");
    graph.createEdge("B", "E");
    graph.createEdge("D", "C");
    graph.createEdge("F", "E");
    graph.createEdge("E", "D");

    assert(!graph.areConnected("C", "A"));
    assert(graph.areConnected("A", "C"));
    assert(graph.areConnected("A", "E"));
    assert(!graph.areConnected("C", "E"));
    
    std::cout << "Done!\n";
    return 0;
}