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

void PrintShortDist(int* distArr, int size)
{
    for (size_t i = 0; i < size; i++)
        std::cout << i << "-" << distArr[i] << " ";
}

void DetectCycle(std::vector<int>* adjList, int s)
{
    bool visited[v];
    for (size_t i = 0; i < v; i++)
        visited[i] = false;
    
    std::queue<int>q;
    visited[s] = true;
    q.push(s);

    int prevVer = -1;
    while (!q.empty())
    {
        int ver = q.front(); q.pop();
        for(int u : adjList[ver])
        {
            if(visited[u] == false)
            {
                visited[u] = true;
                q.push(u);
            }
            else
            {
                if (prevVer != u)
                    std::cout << "Loop is present" << std::endl;
            }
        }
        prevVer = ver;
    }
}


//  0 --- 1 --- 2 --- 4 --- 5
//         -   -
//           3

int main()
{
    std::vector<int> adjList[v];
    AddEdge(adjList, 0,1);
    AddEdge(adjList, 1,2);
    AddEdge(adjList, 1,3);
    AddEdge(adjList, 2,3);
    AddEdge(adjList, 2,4);
    AddEdge(adjList, 4,5);
    PrintGraph(adjList, v);

    DetectCycle(adjList, 0);

    return 0;
}