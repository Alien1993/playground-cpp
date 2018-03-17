#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <limits>

#include "graph.h"

DirectedGraph::DirectedGraph()
{

}

DirectedGraph::~DirectedGraph()
{
    clear();
}

void DirectedGraph::clear()
{
    auto it = m_adjacencyList.cbegin();
    while (it != m_adjacencyList.cend()) {
        it->second->clear();
        delete it->second;
        it++;
    }
    m_adjacencyList.clear();
}

void DirectedGraph::createVertex(const std::string& name)
{
    auto it = m_adjacencyList.find(name);

    // Vertex exists
    if (it != m_adjacencyList.cend()) {
        return;
    }
    
    m_adjacencyList.insert(std::make_pair(name, new std::forward_list<Edge*>));
}

void DirectedGraph::removeVertex(const std::string& name)
{
    auto it = m_adjacencyList.find(name);

    // Vertex exists
    if (it == m_adjacencyList.cend()) {
        it->second->clear();
        delete it->second;
        m_adjacencyList.erase(name);
    }
}

void DirectedGraph::createEdge(const std::string& from, const std::string& to)
{
    auto mapIt = m_adjacencyList.find(to);
    // To vertex doesn't exists
    if (mapIt == m_adjacencyList.cend()) {
        return;
    }

    mapIt = m_adjacencyList.find(from);
    // From vertex doesn't exists
    if (mapIt == m_adjacencyList.cend()) {
        return;
    }

    auto fromEdges = mapIt->second;

    auto listIt = std::find_if(fromEdges->cbegin(), fromEdges->cend(),
        [=] (Edge* edge) { return edge->to == to; });
    // Edge already exists
    if (listIt != fromEdges->cend()) {
        return;
    }

    fromEdges->push_front(new Edge(to));
}

void DirectedGraph::removeEdge(const std::string& from, const std::string& to)
{
    auto mapIt = m_adjacencyList.find(to);
    // To vertex doesn't exists
    if (mapIt == m_adjacencyList.cend()) {
        return;
    }

    mapIt = m_adjacencyList.find(from);
    // From vertex doesn't exists
    if (mapIt == m_adjacencyList.cend()) {
        return;
    }

    // Removes it if Edge is found
    mapIt->second->remove_if([to] (Edge* edge) { return edge->to == to; });
}

bool DirectedGraph::areConnected(const std::string& from, const std::string& to) const
{
    std::set<std::string> visited;
    std::queue<std::string> queue;

    visited.insert(from);
    queue.push(from);

    while(!queue.empty()) {
        auto connectedEdges = m_adjacencyList.at(queue.front());
        queue.pop();

        for (auto edge : *connectedEdges) {
            if (edge->to == to) {
                return true;
            }
            if (visited.count(edge->to) == 0) {
                visited.insert(edge->to);
                queue.push(edge->to);
            }
        }
    }
    return false;
}
