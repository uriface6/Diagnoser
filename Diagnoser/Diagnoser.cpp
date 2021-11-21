#include "Diagnoser.h"

Diagnoser::Diagnoser(Node* root)
{
	_root = root;
}

Diagnoser::~Diagnoser()
{
	//To-Do
}

string Diagnoser::diagnose(vector<string> symptoms)
{
	/*Node* currNode = _root;
	while (currNode->negative_child && currNode->positive_child)
	{
		if (find(symptoms.begin(), symptoms.end(), currNode->data) != symptoms.end())
		{
			//symptom in symptoms
			currNode = currNode->positive_child;
		}
		else
		{
			currNode = currNode->negative_child;
		}
	}
	return currNode->data;*/

	return diagnoseRecursive(_root, symptoms);
}

string Diagnoser::diagnoseRecursive(Node* currNode, vector<string> symptoms)
{
	if (currNode->negative_child && currNode->positive_child)
	{
		if (find(symptoms.begin(), symptoms.end(), currNode->data) != symptoms.end())
		{
			//symptom in symptoms
			return diagnoseRecursive(currNode->positive_child, symptoms);
		}
		else
		{
			return diagnoseRecursive(currNode->negative_child, symptoms);
		}
	}
	else
	{
		return currNode->data;
	}
}

float Diagnoser::calculate_success_rate(vector<Record*> records)
{
	string illness;
	int sucssesDiagnose = 0;
	for (Record* currRecord: records)
	{
		illness = diagnose(currRecord->symptoms);
		if (illness == currRecord->illness)
		{
			sucssesDiagnose++;
		}
	}
	return sucssesDiagnose / records.size();
}

vector<string> Diagnoser::allIllnesses()
{
	map<string, int> illnessesMap;
	vector<string> Sortillnesses;

	return Sortillnesses;

}

void Diagnoser::allIllnessesRecursive(Node* currNode, map<string, int>* illnessesMap)
{
	if (currNode->negative_child && currNode->positive_child)
	{
		allIllnessesRecursive(currNode->positive_child, illnessesMap);
		allIllnessesRecursive(currNode->negative_child, illnessesMap);
	}
	else
	{
		(*illnessesMap)[currNode->data] = (*illnessesMap)[currNode->data] + 1;
		//mybe can replace with:
		//(*illnessesMap)[currNode->data]++
	}
}


void Diagnoser::paths_to_illness(string illness)
{

}

/*
// Comparator function to sort pairs
// according to second value
bool Diagnoser::cmp(pair<string, int>& a,
	pair<string, int>& b)
{
	return a.second < b.second;
}

// Function to sort the map according
// to value in a (key-value) pairs
void Diagnoser::sort(map<string, int>& M)
{

	// Declare vector of pairs
	vector<pair<string, int>> A;

	// Copy key-value pair from Map
	// to vector of pairs
	for (auto& it : M) {
		A.push_back(it);
	}

	// Sort using comparator function
	sort(A.begin(), A.end(), cmp);

	// Print the sorted value
	for (auto& it : A) {

		cout << it.first << ' '
			<< it.second << endl;
	}
}

void print_map(string_view comment, const std::map<std::string, int>& m)
{
	std::cout << comment;
	for (const auto& [key, value] : m) {
		std::cout << key << " = " << value << "; ";
	}
	std::cout << "\n";
}*/