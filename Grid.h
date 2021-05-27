#ifndef MYGRID_H
#define MYGRID_H

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "Node.h"
using namespace std;
/**
 * Class to store and manipulate the grid
 * Also contains function implementing all kinds of algorithm
*/
class Grid
{
    public:
    int N;                    // Stores the number of rows
    int M;                    // Stores the number of columns
    Node Start;               // Stores the Start State of Agent
    vector<Node> Goals;       // Stores the all the Goals nodes 
    Node** G;                 // Stores the all the nodes on grid as a 2D node array

    /**
     * Constructor
     * @param a No. of rows
     * @param b No.of Columns
    */
    Grid(int a,int b);
    
    /**
     * Prints out the board onto the terminal
    */
    void p();

    /**
     * Helper function to check whether a cell exist 
     * or is not a wall
     * or has not been visited before
     * @param x x-coordinate / row number
     * @param y y-coordinate / column number
     * @return true if cell is valid false otherwise
    */
    bool is_Valid(int x,int y);

    /**
     * Helper function to check whether a cell exist 
     * or is not a wall
     * or can be relaxed for djikstra's algorithm
     * @param x x-coordinate / row number
     * @param y y-coordinate / column number
     * @return true if cell is valid false otherwise
    */
    bool is_Valid_1(int x,int y,Node* curr);

    /**
     * Estimates the cost to travel to destination from source
     * @param src  Source node 
     * @param dest Destination node
    */
    int cost(Node* src, Node * dest);
    
    /**
     * Prints out a path from source to destination
     * @param tail Node pointer to dest which can be traversed reversely to reach source
     * @param path String to store the path
    */
    void print_path(Node * tail,stringstream &S);

    /**
     * Resets the visit values of all nodes to false
    */
    void reset_visit();

    /**
     * Depth First Search Algorithm
     * Expands a single child before expanding it's neighbour
     * Prints out the path to all destinations from source
     * @param curr stores the source or current node being expanded
     * Disadvantages: Output paths are least efficient sometimes compared to other algorithms
     * Advantages: Less memory usage
    */
    void DFS(Node *curr);

    /**
     * Breadth First Search Algorithm
     * Expands all it's neighbours then moves onto their neghbours
     * Prints out the path to all destinations from source
     * @param curr stores the source or start node
     * Disadvantages: Requires a lot of memory
     * Advantages: More efficient than DFS in some cases
    */
    void BFS(Node *curr);

    /**
     * Greedy Best First Search Algorithm
     * Uses Priority queue to find the node with smallest cost value/shortest distance to destination and traverses it
     * Prints out the path to destination
     * @param src source node
     * @param dest destination node
     * Disadvantages: Smallest cost value may not be efficient everytime.
     * Advantage: Better efficiency than BFS and DFS same memory usage as BFS
    */
    void GBFS(Node* src, Node * dest);

    /**
     * A* search Algortihm
     * Uses Priority queue to find the node with shortest distance to destination and shortest distance from source to current node
     * Prints out the path to destination
     * @param src source node
     * @param dest destination node
     * Advantages: Highly efficient paths 
    */
    void AS(Node* src, Node * dest);

    /**
     * Djikstra's algorithm to find shortest path to every node from source
     * Uses priority queue to find the node with shortest distance from source
     * @param src Source node
     * Advantages: Can tell the shortest path to any Node.
    */
    void CUS1(Node * src);

    void CUS2(Node * src);
};
#endif