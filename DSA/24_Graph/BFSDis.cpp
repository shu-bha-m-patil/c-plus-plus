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

void BSF(std::vector<int>* adjList, std::vector<bool>& visited, int s)
{
    std::queue<int>q;
    visited[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        std::cout << u << " ";
        for(int v : adjList[u])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void BSFDis(std::vector<int>* adjList, int v)
{
    //bool visited[v + 1];
    std::vector<bool> visited(v + 1);
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    for (size_t i = 0; i < v; i++)
    {
        if(visited[i] == false)
            BSF(adjList, visited, i);
    }
}

//    -- 0 --      -  4  -
//  1        2   5 ------- 6
//    -- 3 -- 

int main()
{
    const int v = 7;
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 0,2);
    AddEdge(adjList, 1,3);
    AddEdge(adjList, 2,3);
    AddEdge(adjList, 4,5);
    AddEdge(adjList, 4,6);
    AddEdge(adjList, 5,6);
    PrintGraph(adjList, v);

    BSFDis(adjList, v);
    return 0;
}