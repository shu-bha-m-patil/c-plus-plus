#include <algorithm>
#include <iostream>
#include <string>

#include "Graph.h"

Graph::Graph() : m_nextVertex(0) {}

void Graph::AddEdge(int src, int dest) 
{
    if (m_adjList.find(src) == m_adjList.end() || m_adjList.find(dest) == m_adjList.end()) {
        throw std::invalid_argument("Invalid vertex specified for edge ("
            + std::to_string(src) + ", " + std::to_string(dest) + ")");
    }
    m_adjList[src].push_back(dest);
    m_adjList[dest].push_back(src); // Assuming undirected graph
}

void Graph::AddVertex()
{
    m_adjList[m_nextVertex] = std::vector<int>{};
    ++m_nextVertex;
}

void Graph::RemoveEdge(int src, int dest) 
{
    if (m_adjList.find(src) == m_adjList.end() || m_adjList.find(dest) == m_adjList.end()) {
        throw std::invalid_argument("Invalid vertex specified for edge removal ("
            + std::to_string(src) + ", " + std::to_string(dest) + ")");
    }
    auto& srcNeighbors = m_adjList[src];
    auto& destNeighbors = m_adjList[dest];

    srcNeighbors.erase(std::remove(srcNeighbors.begin(), srcNeighbors.end(), dest), srcNeighbors.end());
    destNeighbors.erase(std::remove(destNeighbors.begin(), destNeighbors.end(), src), destNeighbors.end());
}


void Graph::RemoveVertex(int vertex) 
{
    if (m_adjList.find(vertex) == m_adjList.end()) {
        throw std::invalid_argument("Invalid vertex specified for removal (" + std::to_string(vertex) + ")");
    }
    // Remove all edges connected to this vertex
    for (int neighbor : m_adjList[vertex]) {
        auto& neighbors = m_adjList[neighbor];
        neighbors.erase(std::remove(neighbors.begin(), neighbors.end(), vertex), neighbors.end());
    }
    // Remove the vertex itself
    m_adjList.erase(vertex);
}