#include "Node.h"
/**
 * Constructor initializes cost  and distance to INT_MAX marks visit as false and prev points to NULL 
*/
Node::Node(int a,int b,char c):x(a),y(b),col(c),cost(-1),dist(-1),visit(false),prev(NULL){};
