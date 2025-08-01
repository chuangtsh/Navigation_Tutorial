/*
 * Dijkstra's Algorithm Practice Question
 * 
 * Problem Statement:
 * You are planning a road trip across a country with several cities. Each direct road between 
 * cities has a specific travel time (in hours). You want to find the shortest (minimum time) 
 * path from your starting city to your destination city.
 * 
 * Given:
 * - A graph representing cities and roads between them
 * - Each road has a positive travel time (weight)
 * - There are no negative weights (no time travel!)
 * - The graph is directed (you can only travel in one direction on some roads)
 * - The graph has no cycles that would create infinite loops
 * 
 * Task:
 * Implement Dijkstra's algorithm to find the shortest path (minimum total travel time)
 * from the starting city (0) to the destination city (5).
 * 
 * Also print the actual path taken (sequence of cities) from start to destination.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <utility> // for pair
#include <stack>   // for reconstructing the path

using namespace std;

struct CompareDistance {
    bool operator()(pair<int,int> lhs, pair<int,int> rhs) {
        return lhs.second > rhs.second; 
    }
};

// Graph representation using adjacency list
class Graph {
private:
    int V; // Number of vertices (cities)
    vector<vector<pair<int, int>>> adj; // adjacency list: pair<destination, weight>

public:
    // Constructor
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Add an edge (road) from city u to city v with travel time w
    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
    }

    // TODO: Implement Dijkstra's algorithm
    void shortestPath(int src, int dest) {
        // Your implementation goes here
        
        // 1. Create a priority queue for vertices being processed
        // 2. Create arrays for distances and for tracking the path
        // 3. Initialize all distances as INFINITE and src distance as 0
        // 4. Process vertices in order of their distance from src
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareDistance> pq;
        vector<bool> visited(V, 0);
        vector<int> cost(V, INT32_MAX);
        vector<int> path(V, -1);
        stack<int> result_path;
        pq.push(make_pair(src, 0));
        cost[src] = 0;

        while ( visited[dest] == 0 && pq.size() > 0 ) {
            auto cur = pq.top();
            pq.pop();
            visited[cur.first] = true;
            // cout << "cur:" << cur.first << endl;

            for ( auto ni : adj[cur.first] ) {
                if ( visited[ni.first] ) continue;

                if ( cost[ni.first] > cost[cur.first] + ni.second ) {
                    cost[ni.first] = cost[cur.first] + ni.second;
                    path[ni.first] = cur.first;
                    pq.push(make_pair(ni.first, cost[ni.first]));
                    // current method would cause duplicate nodes in pqueue,
                    // to improve is to use set<pair<int,int>>, since st.begin() is the smallest
                    // cout << "add neighbor: " << ni.first << "<>" << cost[ni.first] << endl;
                }
            }
        }

        if ( visited[dest] == 0 ) {
            cout << "no path exists\n";
            return;
        }


        for ( int it = dest; it != src; it = path[it] ) {
            result_path.push(it); 
        }
        result_path.push(src);


        cout << "Shortest travel time: " << cost[dest] << " hours\n";

        cout << "Path: ";

        cout << result_path.top();
        result_path.pop();
        while ( !result_path.empty() ) {
            int cur = result_path.top();
            result_path.pop();
            cout << " -> " << cur;
        }
        cout << endl;


    }
};

int main() {
    // Create graph with 6 cities (labeled 0 to 5)
    Graph g(6);
    
    // Add roads with travel times (directed edges with weights)
    g.addEdge(0, 1, 2);  // From city 0 to city 1, travel time: 2 hours
    g.addEdge(0, 2, 4);  // From city 0 to city 2, travel time: 4 hours
    g.addEdge(1, 2, 1);  // From city 1 to city 2, travel time: 1 hour
    g.addEdge(1, 3, 7);  // From city 1 to city 3, travel time: 7 hours
    g.addEdge(2, 4, 3);  // From city 2 to city 4, travel time: 3 hours
    g.addEdge(3, 5, 1);  // From city 3 to city 5, travel time: 1 hour
    g.addEdge(4, 3, 2);  // From city 4 to city 3, travel time: 2 hours
    g.addEdge(4, 5, 5);  // From city 4 to city 5, travel time: 5 hours
    
    // Find the shortest path from city 0 (start) to city 5 (destination)
    cout << "Shortest path from city 0 to city 5:" << endl;
    g.shortestPath(0, 5);
    
    return 0;
}

/*
 * Student Task:
 * 
 * 1. Implement the shortestPath method using Dijkstra's algorithm
 * 2. Your implementation should:
 *    - Calculate the minimum travel time from src to dest
 *    - Print the sequence of cities in the shortest path
 *    - Handle edge cases (e.g., no path exists)
 * 
 * Expected output format:
 * - Shortest travel time: X hours
 * - Path: 0 -> 1 -> ... -> 5
 * 
 * Optional challenge:
 * - Modify the implementation to handle different start and destination cities as user input
 * - Visualize the graph and the shortest path
 */
