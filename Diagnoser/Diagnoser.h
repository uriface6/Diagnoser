#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <algorithm>    // std::sort
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
	float calculate_success_rate(vector<Record*> records);
	vector<string> allIllnesses();
	vector<vector<bool>> pathsToIllness(string illness);

	static void printMap(map<string, int> m);

private:
	Node* _root;
	
	string diagnoseRecursive(Node* currNode, vector<string> symptoms);
	void allIllnessesRecursive(Node* currNode, map<string, int>* illnessesMap);
	void pathsToIllnessRecursive(Node* currNode, string illness, vector<bool> routeList, vector<vector<bool>>* listOfRouteLists);
	vector<string> sortMapToVector(map<string, int> m);
	


	/*struct comp {
		template <typename T>

		// Comparator function
		bool operator()(const T& l,
			const T& r) const
		{
			if (l.second != r.second) {
				return l.second < r.second;
			}
			return l.first < r.first;
		}
	};*/

	/*bool cmp(pair<string, int>& a,
		pair<string, int>& b);
	
	void sort(map<string, int>& M);

	void print_map(string_view comment, const std::map<std::string, int>& m);
	*/
};