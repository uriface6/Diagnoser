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
	return (float)(sucssesDiagnose / records.size());
}

vector<string> Diagnoser::allIllnesses()
{
	map<string, int> illnessesMap;
	allIllnessesRecursive(_root, &illnessesMap);
	printMap(illnessesMap);
	vector<string> Sortillnesses = sortMapToVector(illnessesMap);
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


vector<vector<bool>> Diagnoser::pathsToIllness(string illness)
{
	vector<vector<bool>> b;
	return b;
}

void Diagnoser::pathsToIllnessRecursive(Node* currNode, string illness, vector<bool>* routeList)
{
	if (currNode->negative_child && currNode->positive_child)
	{
		/*if (find(symptoms.begin(), symptoms.end(), currNode->data) != symptoms.end())
		{
			//symptom in symptoms
			return diagnoseRecursive(currNode->positive_child, symptoms);
		}
		else
		{
			return diagnoseRecursive(currNode->negative_child, symptoms);
		}*/
	}
	else
	{
		if (currNode->data != illness)
		{
			routeList->clear();
		}
	}
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

*/

void Diagnoser::printMap(map<string, int> m)
{
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
	std::cout << "\n";
}

/*
bool Diagnoser::cmp(pair<string, int>& a, pair<string, int>& b)
{
	return a.second < b.second;
}*/

vector<string> Diagnoser::sortMapToVector(map<string, int> m)
{
	//To-Do 
	vector<string> v;
	/*map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++)
	{
		v.push_back(it->first);
	}

	// Declare vector of pairs
	vector<pair<string, int>> A;

	// Copy key-value pair from Map
	// to vector of pairs
	//vector<pair<string, int>>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		A.push_back(*it);
	}
	
	// Sort using comparator function
	sort(A.begin(), A.end(), comp);

	// Print the sorted value
	for (auto& it : A) {

		cout << it.first << ' '
			<< it.second << endl;

		cout << "aaaaa" << endl;
		for (unsigned int i = 0; i < v.size(); ++i)
			cout << v[i] << endl;
		cout << "aaaaa" << endl;
		return v;
	}*/
	return v;
}
