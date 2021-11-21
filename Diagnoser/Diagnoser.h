#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

class Diagnoser
{
	/*
	Node department, save the data of the node and pointer to the next
	children, if its leaf the child is empty
	*/
public:
	Diagnoser(Node* root);
	~Diagnoser();

	string diagnose(vector<string> symptoms);
	void calculate_success_rate(vector<string> records);
	void all_illnesses();
	void paths_to_illness(string illness);

private:
	Node* _root;

};