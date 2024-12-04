#pragma once

#include "Graph.h"
#include "Traversal.h"
#include <stack>
#include <unordered_set>
#include <iostream>
#include <queue>

void BSF(const Graph& graph, int startNode)
{
    std::queue<int> toVisit;
    std::unordered_set<int> visited;

    toVisit.push(startNode);
    visited.insert(startNode);

    while (!toVisit.empty())
    {
        int node = toVisit.front();
        toVisit.pop();

        std::cout << node << "";
        std::unordered_map<int, std::vector<int>> adjList = graph.GetAdjList();

        for (int neighbor : adjList.at(node))
        {
            if (visited.find(neighbor) == visited.end())
            {
                toVisit.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

void DSF(const Graph& graph, int startNode)
{
    std::stack<int> toVisit;
    std::unordered_set<int> visited;

    toVisit.push(startNode);
    visited.insert(startNode);

    while (!toVisit.empty())
    {
        int node = toVisit.top();
        toVisit.pop();

        std::cout << node << "";
        std::unordered_map<int, std::vector<int>> adjList = graph.GetAdjList();

        for (int neighbor : adjList.at(node))
        {
            if (visited.find(neighbor) == visited.end())
            {
                toVisit.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}