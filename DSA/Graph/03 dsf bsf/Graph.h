#pragma once

#include <vector>
#include <unordered_map>

class Graph 
{
public:
    Graph();
public:
    const std::unordered_map<int, std::vector<int>>& GetAdjList() const;
public:
    void AddVertex();
    void RemoveVertex(int vertex);
    void AddEdge(int src, int dest);
    void RemoveEdge(int src, int dest);
private:
    std::unordered_map<int, std::vector<int>> m_adjList;
    int m_nextVertex;
};