#include <iostream>
#include "Graph.h"
#include "Traversal.h"

int main() 
{
    Graph graph;

    graph.AddVertex(); // Vertex 0
    graph.AddVertex(); // Vertex 1
    graph.AddVertex(); // Vertex 2
    graph.AddVertex(); // Vertex 3
    graph.AddVertex(); // Vertex 4

    try {
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 2);
        graph.AddEdge(1, 2);
        graph.AddEdge(2, 3);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 4);

        DSF(graph, 1); 
        std::cout << std::endl;
        BSF(graph, 1);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
