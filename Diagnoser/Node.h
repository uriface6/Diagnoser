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

private:
	Node* _positive_child;
	Node* _negative_child;
	string _data;
};