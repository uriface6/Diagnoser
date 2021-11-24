#include "Node.h"

Node::Node(string data, Node* positiveChild, Node* negativeChild)
	: positiveChild (positiveChild), negativeChild (negativeChild), data (data)
{
}

//TO-DO
Node::~Node()
{

}