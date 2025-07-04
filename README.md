# Shortest Path Algorithms: Dijkstra and A*

This repository contains educational materials for learning and comparing two important shortest path algorithms: Dijkstra's algorithm and A* (A-star).

## Repository Contents

- `Dijkstra.cpp` - Exercise implementing Dijkstra's algorithm on a road trip problem
- `Dijkstra_solution.cpp` - Complete solution for the Dijkstra exercise
- `AStar.cpp` - Exercise implementing A* algorithm on the same road trip problem
- `AStar_solution.cpp` - Complete solution for the A* exercise
- `Algorithm_Comparison.cpp` - Direct comparison of both algorithms showing efficiency differences
- `GraphVisualization.cpp` - Visual representation of the graph structure used in exercises

## Problem Context

Both exercises use the same context: planning a road trip across cities with different travel times between them. The goal is to find the shortest (minimum time) path from a starting city to a destination city.

## Dijkstra's Algorithm

### Overview
Dijkstra's algorithm finds the shortest path from a source vertex to all other vertices in a weighted graph with non-negative edge weights.

### How It Works
1. Maintain a priority queue of vertices, sorted by their distance from the source
2. Initialize distances: source = 0, all others = infinity
3. While the queue is not empty:
   - Extract the vertex with minimum distance
   - For each neighbor, update its distance if a shorter path is found
   - Insert updated neighbors into the queue

### Key Properties
- Guarantees shortest path if all edge weights are non-negative
- Time complexity: O((V + E) log V) with a binary heap
- Space complexity: O(V)
- Explores nodes in all directions (uniformly)

### Pseudocode
```
function Dijkstra(Graph, source, destination):
    create vertex priority queue Q
    for each vertex v in Graph:
        distance[v] ← INFINITY
        parent[v] ← UNDEFINED
        add v to Q
    distance[source] ← 0

    while Q is not empty:
        u ← vertex in Q with minimum distance
        remove u from Q
        
        if u = destination:
            break
            
        for each neighbor v of u:
            alt ← distance[u] + length(u, v)
            if alt < distance[v]:
                distance[v] ← alt
                parent[v] ← u
                update v in Q

    return distance[], parent[]
```

## A* Algorithm

### Overview
A* is an informed search algorithm that uses a heuristic function to guide the search toward the goal, making it more efficient than Dijkstra's algorithm when a good heuristic is available.

### How It Works
1. Similar to Dijkstra, but uses a priority queue sorted by f(n) = g(n) + h(n)
   - g(n) = cost from start to current node (same as Dijkstra)
   - h(n) = heuristic estimate of cost from current node to goal
2. Initialize: source f-score = h(source), all others = infinity
3. While the queue is not empty:
   - Extract the vertex with minimum f-score
   - For each neighbor, update its g-score and f-score if a better path is found
   - Insert updated neighbors into the queue

### Key Properties
- Complete and optimal if the heuristic is admissible (never overestimates)
- More efficient than Dijkstra when a good heuristic is available
- Time complexity: O((V + E) log V) with a binary heap
- Space complexity: O(V)
- Explores nodes in the direction of the goal

### Pseudocode
```
function A_Star(Graph, source, destination, heuristic):
    create vertex priority queue Q (sorted by f-score)
    for each vertex v in Graph:
        g_score[v] ← INFINITY
        f_score[v] ← INFINITY
        parent[v] ← UNDEFINED
    g_score[source] ← 0
    f_score[source] ← heuristic[source]
    add source to Q

    while Q is not empty:
        u ← vertex in Q with minimum f_score
        remove u from Q
        
        if u = destination:
            break
            
        for each neighbor v of u:
            tentative_g ← g_score[u] + length(u, v)
            if tentative_g < g_score[v]:
                parent[v] ← u
                g_score[v] ← tentative_g
                f_score[v] ← g_score[v] + heuristic[v]
                if v not in Q:
                    add v to Q

    return g_score[], parent[]
```

## Comparing Dijkstra and A*

### Similarities
1. Both find the shortest path in a weighted graph
2. Both use a priority queue for node selection
3. Both have the same time complexity
4. Both guarantee the optimal solution with appropriate conditions

### Differences
1. Dijkstra explores uniformly in all directions
2. A* uses a heuristic to guide the search toward the goal
3. A* is generally more efficient when searching for a specific destination
4. Dijkstra computes shortest paths to all vertices
5. A* is focused on finding the shortest path to a specific destination

### When to Use Dijkstra
- When you need shortest paths to all vertices from a source
- When no good heuristic is available
- When the graph is relatively small

### When to Use A*
- When you need the shortest path to a specific destination
- When a good heuristic is available
- When the graph is large and efficiency is crucial

## Heuristics for A*

### Admissible Heuristics
A heuristic h(n) is admissible if h(n) ≤ h*(n) for all nodes n, where h*(n) is the true cost.
In other words, the heuristic never overestimates the cost to reach the goal.

### Examples of Admissible Heuristics
1. Euclidean distance (straight-line distance) for spatial problems
2. Manhattan distance for grid-based problems
3. Number of misplaced tiles for the 8-puzzle problem

### Consistent (Monotonic) Heuristics
A heuristic is consistent if h(n) ≤ d(n, n') + h(n') for all edges (n, n'),
where d(n, n') is the cost of the edge.

Note: All consistent heuristics are admissible, but not all admissible heuristics are consistent.

## Implementation Tips

1. Use a priority queue (min-heap) for efficient node selection
2. Keep track of visited nodes to avoid processing them multiple times
3. For A*, make sure your heuristic is admissible for optimal results
4. Consider using a hash table for faster lookup of node information
5. Implement path reconstruction to trace the optimal path

## Exercise Instructions

For both Dijkstra.cpp and AStar.cpp:

1. Implement the missing method (shortestPath for Dijkstra, aStarSearch for A*)
2. Your implementation should:
   - Calculate the minimum travel time from src to dest
   - Print the sequence of cities in the shortest path
   - Handle edge cases (e.g., no path exists)
3. Compare your solution with the provided solution files
4. Run the Algorithm_Comparison.cpp to understand efficiency differences

## Expected Output Format
```
Shortest travel time: X hours
Path: 0 -> 1 -> ... -> 5
```

## Compilation and Running

To compile and run any of the C++ files:

```bash
g++ -std=c++11 Dijkstra.cpp -o dijkstra
./dijkstra

g++ -std=c++11 AStar.cpp -o astar
./astar

g++ -std=c++11 Algorithm_Comparison.cpp -o compare
./compare
```

## Extensions and Further Learning

After completing the basic exercises, consider these extensions:
1. Modify the implementation to handle different start and destination cities as user input
2. Experiment with different heuristic values and observe how they affect A* performance
3. Visualize the graph and the exploration process with a graphical interface
4. Apply these algorithms to solve other path-finding problems like maze navigation
