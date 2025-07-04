/*
 * Graph Visualization Helper
 * 
 * This file provides a text-based visualization of the graph structure
 * to help students understand the problem better.
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Simple ASCII visualization of the graph
void visualizeGraph() {
    cout << "\n==============================================" << endl;
    cout << "GRAPH VISUALIZATION (Cities and Travel Times)" << endl;
    cout << "==============================================" << endl;
    cout << "\n";
    cout << "    2h        1h" << endl;
    cout << "  +----->1------+" << endl;
    cout << "  |      |      |" << endl;
    cout << "  |      |7h    v" << endl;
    cout << "  |      |    +---+" << endl;
    cout << "0 |      |    | 3 |" << endl;
    cout << "  |      |    +---+" << endl;
    cout << "  |      |      |" << endl;
    cout << "  |      |      |1h" << endl;
    cout << "  |      |      v" << endl;
    cout << "  |      |    +---+" << endl;
    cout << "  |      |    | 5 | (Destination)" << endl;
    cout << "  |      |    +---+" << endl;
    cout << "  |      |      ^" << endl;
    cout << "  |4h    |      |" << endl;
    cout << "  v      |      |5h" << endl;
    cout << "+---+    |    +---+" << endl;
    cout << "| 2 |----+--->| 4 |" << endl;
    cout << "+---+    3h   +---+" << endl;
    cout << "               |" << endl;
    cout << "               |2h" << endl;
    cout << "               |" << endl;
    cout << "               v" << endl;
    cout << "              (3)" << endl;
    cout << "\n";
    
    // Display the adjacency list representation
    cout << "Adjacency List Representation:" << endl;
    cout << "-----------------------------" << endl;
    cout << "City 0: (1,2), (2,4)" << endl;
    cout << "City 1: (2,1), (3,7)" << endl;
    cout << "City 2: (4,3)" << endl;
    cout << "City 3: (5,1)" << endl;
    cout << "City 4: (3,2), (5,5)" << endl;
    cout << "City 5: [Destination]" << endl;
    cout << "\n";
    
    cout << "Edge List (From, To, Weight):" << endl;
    cout << "----------------------------" << endl;
    cout << "(0,1,2), (0,2,4), (1,2,1), (1,3,7), (2,4,3), (3,5,1), (4,3,2), (4,5,5)" << endl;
    cout << "\n==============================================" << endl;
}

int main() {
    visualizeGraph();
    
    cout << "\nInstructions for students:" << endl;
    cout << "1. Understand the graph structure above" << endl;
    cout << "2. Implement Dijkstra's algorithm in the main exercise file" << endl;
    cout << "3. Trace through the algorithm by hand to verify your solution" << endl;
    cout << "4. Run your code and check if you get the correct shortest path" << endl;
    
    return 0;
}
