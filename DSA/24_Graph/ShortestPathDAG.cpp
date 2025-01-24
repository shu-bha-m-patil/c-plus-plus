#include <iostream>
#include <vector>
#include <queue>

const int v = 6;

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


void BFS(std::vector<int>* adjList, int s)
{
    bool visited[v];
    for (size_t i = 0; i < v; i++)
        visited[i] = false;

    std::queue<int> q;
    visited[s] = true;
    q.push(s);
    std::cout << s << " ";

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for(int u : adjList[v])
        {
            if(visited[u] == false)
            {
                visited[u] = true;
                q.push(u);
                std::cout << u << " ";
            }
        }
    }
}

void PrintShortDist(int* distArr, int size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << i << "-" << distArr[i] << " ";
}

void PrintShortestDist(std::vector<int>* adjList, int s)
{
    int noOfvert = v;
    int distArr[v];
    for (size_t i = 0; i < v; i++)
        distArr[i] = 0;

    bool visited[v];
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    std::queue<int>q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for(int u : adjList[v])
        {
            if(visited[u] == false)
            {
                visited[u] = true;
                distArr[u] = distArr[v] + 1;
                q.push(u);
            }
        }
    }

    PrintShortDist(distArr, noOfvert);
}


//    -- 1 -- 3 --
//  0--------------5
//    -- 2 -- 4 --

int main()
{
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 0,2);
    AddEdge(adjList, 0,5);
    AddEdge(adjList, 1,3);
    AddEdge(adjList, 2,4);
    AddEdge(adjList, 3,5);
    AddEdge(adjList, 4,5);
    PrintGraph(adjList, v);

    BFS(adjList, 0);
    std::cout << std::endl;
    PrintShortestDist(adjList, 0);


    return 0;
}
