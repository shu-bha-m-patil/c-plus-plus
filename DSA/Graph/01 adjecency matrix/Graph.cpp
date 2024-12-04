#include "Graph.h"
#include <stdexcept>
#include <string>

Graph::Graph(int numVertices) : 
    m_adjMatrix(numVertices, std::vector<int>(numVertices, 0)), 
    m_numVertices(numVertices)
{
}

void Graph::AddVertex()
{
    // Increase numver of vertices by 1
    m_numVertices++;

    // Addsa column in existing rows for new vertex
    for (auto& row : m_adjMatrix)
    {
        row.push_back(0);
    }
    
    // Add a new row at the end of m_adjMatrix
    // This is a row for ew vertex
    m_adjMatrix.push_back(std::vector<int>(m_numVertices, 0));
}

void Graph::RemoveVertex(int vertex)
{
    if (!IsValidNode(vertex))
        throw std::out_of_range("Invalid vertex(" + std::to_string(vertex) + ")");

    // Delete the vertex row
    m_adjMatrix.erase(m_adjMatrix.begin() + vertex);

    for (auto& row : m_adjMatrix)
        row.erase(row.begin() + vertex);

    m_numVertices--;
}

void Graph::AddEdge(int src, int dest)
{
    if (!IsValidNode(src) || !IsValidNode(dest))
        throw std::out_of_range("Invalid node numbers for edge(" + std::to_string(src) + "," + std::to_string(dest) + ")");

    m_adjMatrix[src][dest] = 1;
    m_adjMatrix[dest][src] = 1;
}

void Graph::RemoveEdge(int src, int dest)
{
    if (!IsValidNode(src) || !IsValidNode(dest))
        throw std::out_of_range("Invalid node numbers for edge(" + std::to_string(src) + "," + std::to_string(dest) + ")");

    m_adjMatrix[src][dest] = 0;
    m_adjMatrix[dest][src] = 0;
}

// Helper function to validate node numbers
bool Graph::IsValidNode(int node) const
{
    return node >= 0 && node < m_numVertices;
}
