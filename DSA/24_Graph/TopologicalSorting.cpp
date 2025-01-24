#include <iostream>
#include <vector>
#include <stack>

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

void PrintStack(std::stack<int> stack)
{
    while (!stack.empty())
    {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

void DFS(std::vector<int>* adjList, std::vector<bool>& visited, std::stack<int>& stack, int s)
{
    visited[s] = true;
    for(auto u : adjList[s])
    {
        if(false == visited[u])
            DFS(adjList, visited, stack, u);
    }
    stack.push(s);
}

void TopologicalSort(std::vector<int>* adjList, std::stack<int>& stack, int v)
{
    std::vector<bool> visited(v, false);

    for (size_t i = 0; i < v; i++)
    {
        if(visited[i] == false)
            DFS(adjList, visited, stack, i);
    }
}

//  0 --- 1 --- 2 --- 4 --- 5
//         -   -
//           3

int main()
{
    const int v = 5;
    std::vector<int> adjList[v];
    AddEdge(adjList, 1,2);
    AddEdge(adjList, 3,4);
    PrintGraph(adjList, v);

    std::stack<int> stack;
    TopologicalSort(adjList, stack, v);

    PrintStack(stack);
    return 0;
}