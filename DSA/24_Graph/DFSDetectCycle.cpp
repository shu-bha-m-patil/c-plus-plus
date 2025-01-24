#include <iostream>
#include <vector>
#include <queue>

void AddEdge(std::vector<int>* adjList, int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void PrintGraph(std::vector<int>* adjList, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << i << " - ";
        for (size_t j = 0; j < adjList[i].size(); j++)
        {
            std::cout << adjList[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void DFS(std::vector<int>* adjList, std::vector<bool>& visited, int s)
{
    for(auto u : adjList[s])
    {
        bool vis = visited[u];
        if(vis == false)
        {
            std::cout << u << " ";
            visited[u] = true;
            DFS(adjList, visited, u);
        }
    }
}

void DFSDis(std::vector<int>* adjList, int v)
{
    std::vector<bool> visited(v + 1);
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    for (size_t i = 0; i < v; i++)
    {
        bool vis = visited[i];
        if(vis == false)
        {
            std::cout << i << " ";
            visited[i] = true;
            DFS(adjList, visited, i);
        }
    }
    
}

//  0 ----- 1 --    
//  -       -     4
//  2------ 3 --

int main()
{
    const int v = 5;
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 0,2);
    AddEdge(adjList, 1,3);
    AddEdge(adjList, 2,3);
    AddEdge(adjList, 1,4);
    AddEdge(adjList, 3,4);
    PrintGraph(adjList, v);

    DFSDis(adjList, v);
    return 0;
}