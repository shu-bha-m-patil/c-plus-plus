#include <iostream>
#include <vector>
#include <queue>

const int v = 6;

void AddEdge(std::vector<int>* adjList, int v, int u)
{
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

void DetectCycleInBFS(std::vector<int>* adjList, std::vector<bool>& visited, int s)
{
    int localVis[v];
    for (size_t i = 0; i < v; i++)
        localVis[i] = false;
        
    visited[s] = true;
    localVis[s] = true;

    std::queue<int>q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int u : adjList[v])
        {
            if(localVis[u] == false)
            {
                visited[u] = true;
                localVis[u] = true;
                q.push(u);
            }
            else
            {
                std::cout << "Loop is present" << std::endl;
            }
        }
    }
}


void DetectCycleBFS(std::vector<int>* adjList)
{
    std::vector<bool> visited(v);
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    for (size_t i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            DetectCycleInBFS(adjList, visited, i);
        }
    }
}


void DetectCycleInDFS(std::vector<int>* adjList, std::vector<bool>& visited, int s)
{
    int localVis[v];
    for (size_t i = 0; i < v; i++)
        localVis[i] = false;
        
    visited[s] = true;
    localVis[s] = true;

    std::queue<int>q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        for (int u : adjList[v])
        {
            if(localVis[u] == false)
            {
                visited[u] = true;
                localVis[u] = true;
                q.push(u);
            }
            else
                std::cout << "Loop is present" << std::endl;
        }
    }
}


void DetectCycleInDFS(std::vector<int>* adjList, std::vector<bool>& visited, std::vector<bool>& localVis,
    int s)
{
    for (int u : adjList[s])
    {
        if(localVis[u] == false)
        {
            visited[u] = true;
            localVis[u] = true;
            DetectCycleInDFS(adjList, visited, localVis, u);
        }
        else
            std::cout << "Loop is present" << std::endl;
    }
}

void DetectCycleDFS(std::vector<int>* adjList)
{
    std::vector<bool> visited(v);
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    for (size_t i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            std::vector<bool> localVis(v);
            for (size_t i = 0; i < v; i++)
                visited[i] = false;

            visited[i] = true;
            localVis[i] = true;
            DetectCycleInDFS(adjList, visited, localVis, i);
        }
    }
}

//  0---.1.---2---.3-----.4
//                 .-    -
//                   - .- 
//                    5
int main()
{
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 2,1);
    AddEdge(adjList, 2,3);
    AddEdge(adjList, 3,4);
    AddEdge(adjList, 4,5);
    AddEdge(adjList, 5,3);
    PrintGraph(adjList, v);
    DetectCycleBFS(adjList);
    DetectCycleDFS(adjList);
    return 0;
}