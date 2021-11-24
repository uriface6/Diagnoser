#pragma once

#include <iostream>
#include <string>

using namespace std;

class Node
{
	/*
	Node department, save the data of the node and pointer to the next
	children, if its leaf the child is empty
	*/
public:
	Node(string data, Node* positiveChild = nullptr, Node* negativeChild = nullptr);
	~Node();

	Node* positiveChild;
	Node* negativeChild;
	string data;

private:

};