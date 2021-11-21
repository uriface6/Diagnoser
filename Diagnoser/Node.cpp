#include "Node.h"

Node::Node(string data, Node* positive_child, Node* negative_child)
{
	_positive_child = positive_child;
	_negative_child = negative_child;
	_data = data;
}

//TO-DO
Node::~Node()
{

}