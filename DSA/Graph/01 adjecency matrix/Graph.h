#pragma once

#include <vector>
class Graph 
{
public:
    Graph(int numVertices);
public:
    void AddVertex();
    void RemoveVertex(int vertex);
    void AddEdge(int src, int dest);
    void RemoveEdge(int src, int dest);
private:
    bool IsValidNode(int node)const;
private:
    std::vector<std::vector<int>> m_adjMatrix;
    int m_numVertices;
};