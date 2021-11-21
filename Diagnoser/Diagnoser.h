#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include "Node.h"
#include "Record.h"

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
	string diagnoseRecursive(Node* currNode, vector<string> symptoms);
	float calculate_success_rate(vector<Record*> records);
	vector<string> allIllnesses();
	void allIllnessesRecursive(Node* currNode, map<string, int>* illnessesMap);
	void paths_to_illness(string illness);


private:
	Node* _root;

	/*bool cmp(pair<string, int>& a,
		pair<string, int>& b);
	
	void sort(map<string, int>& M);

	void print_map(string_view comment, const std::map<std::string, int>& m);
	*/
};