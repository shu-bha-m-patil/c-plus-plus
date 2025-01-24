#include <iostream>
#include <vector>

const int noOfVer = 4;

void AddEdge(std::vector<std::vector<int>>&adjMaxt, int v, int u, int wt)
{
    adjMaxt[v][u] = wt;
    adjMaxt[u][v] = wt;
}

void Print(std::vector<std::vector<int>>&adjMaxt)
{
    for(int i = 0; i < noOfVer; i++)
    {
        for(int u : adjMaxt[i])
        {
            std::cout << u << " ";
        }
        std::cout << std::endl;
    }
}

void BuildMat(std::vector<std::vector<int>>&adjMaxt)
{
    for(int i = 0; i < noOfVer; i++)
    {
        std::vector<int> vect = {0,0,0,0};
        adjMaxt.push_back(vect);
    }
}

int PrimMST(std::vector<std::vector<int>>&mat)
{
    int res = 0;
    int key[noOfVer] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
    bool vis[noOfVer] = {false, false, false, false};
    key[0] = 0;
    vis[0] = true;

    for (size_t i = 0; i < noOfVer; i++)
    {
        int u = -1;
        if(!vis[i] && (u == -1 || key[i] < key[u]))
            u = i;

        vis[u] = true;
        res = res + key[u];
        for (size_t j = 0; j < noOfVer; j++)
        {
            if(mat[u][j] != 0 && !vis[j])
                key[j] = std::min(key[j], mat[u][j]);
        }
    }
    return res;
}

int main()
{
    std::vector<std::vector<int>>mat;
    BuildMat(mat);
    AddEdge(mat, 0,1,5);
    AddEdge(mat, 0,2,8);
    AddEdge(mat, 1,2,10);
    AddEdge(mat, 1,3,15);
    AddEdge(mat, 2,3,20);
    Print(mat);
    PrimMST(mat);
    return 0;
}