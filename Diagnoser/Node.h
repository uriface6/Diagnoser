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
	Node(string data, Node* positive_child = nullptr, Node* negative_child = nullptr);
	~Node();

	Node* positive_child;
	Node* negative_child;
	string data;

private:

};