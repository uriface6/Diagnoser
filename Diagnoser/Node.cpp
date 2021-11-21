#include "Node.h"

Node::Node(string data, Node* positive_child, Node* negative_child)
	: positive_child (positive_child), negative_child (negative_child), data (data)
{
}

//TO-DO
Node::~Node()
{

}