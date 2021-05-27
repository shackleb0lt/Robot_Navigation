#ifndef MYNODE_H
#define MYNODE_H

#ifndef NULL
#define NULL nullptr
#endif
using namespace std;
/**
 * Class Node to store each of the cells in the grid
*/
class Node
{
    public:
    int x;                                      // Stores the the row number starting from 0 
    int y;                                      // Stores the the column number starting from 0
    unsigned int cost;                          // Stores the cost to reach a goal
    unsigned int dist;                          // Stores the distance travelled till now
    char col;                                   // Colour coding of the cell indicating 'R' for agent 'W' walls 'G' for Goals 'O' otherwise
    bool visit;                                 // Marks whether the cell has been visited or not
    Node *prev;                                 // Pointer to store the predecessor of the current node.
    Node(int a = -1,int b =-1,char c='O');      // COnstructor
};
#endif