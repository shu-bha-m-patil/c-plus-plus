#include <iostream>
#include "Graph.h"

int main() {
    Graph graph(4);

    graph.AddVertex();

    try {
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 2);
        graph.AddEdge(1, 2);
        graph.AddEdge(2, 3);
        graph.AddEdge(1, 3);
        graph.AddEdge(1, 4);

        graph.RemoveEdge(0, 1);

        graph.RemoveVertex(4);
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
