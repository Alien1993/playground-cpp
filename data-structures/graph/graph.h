#pragma once

#include <string>
#include <map>
#include <forward_list>


struct Edge 
{
    Edge(const std::string& to) : to{to} {};
    std::string to;
};

class DirectedGraph
{
public:
    DirectedGraph();
    ~DirectedGraph();

    void clear();

    void removeVertex(const std::string& name);
    void createVertex(const std::string& name);
    void createEdge(const std::string& from, const std::string& to);
    void removeEdge(const std::string& from, const std::string& to);
    
    bool areConnected(const std::string& from, const std::string& to) const;
    
private:
    std::map<std::string, std::forward_list<Edge*>*> m_adjacencyList;
};