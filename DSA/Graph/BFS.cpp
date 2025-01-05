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

void BFS(std::vector<int>* adjList, int v, int s)
{
    bool visited[v + 1];
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
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


//    -- 1 -- 3 --
//  0--------------5
//    -- 2 -- 4 --

int main()
{
    const int v = 6;
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 0,2);
    AddEdge(adjList, 0,5);
    AddEdge(adjList, 1,3);
    AddEdge(adjList, 2,4);
    AddEdge(adjList, 3,5);
    AddEdge(adjList, 4,5);
    PrintGraph(adjList, v);

    BFS(adjList, v, 0);
    return 0;
}