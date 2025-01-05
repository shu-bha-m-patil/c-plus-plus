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

int DFSDis(std::vector<int>* adjList, int v)
{
    std::vector<bool> visited(v + 1);
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    int count = 0;
    for (size_t i = 0; i < v; i++)
    {
        bool vis = visited[i];
        if(vis == false)
        {
            count++;
            std::cout << i << " ";
            visited[i] = true;
            DFS(adjList, visited, i);
        }
    }
    return count;
}

//  0    2 --- 3    
//  -       -        5
//  1       4 

int main()
{
    const int v = 6;
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 2,3);
    AddEdge(adjList, 2,4);
    AddEdge(adjList, 3,4);
    AddEdge(adjList, 5,5);
    PrintGraph(adjList, v);

    int noOfDisGraph = DFSDis(adjList, v);
    std::cout << std::endl;
    std::cout << "The no of disconnected graph is " << noOfDisGraph << std::endl;
    return 0;
}