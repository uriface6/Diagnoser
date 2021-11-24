#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Diagnoser.h"
#include "Node.h"
#include "Record.h"



vector<Record> parseData(string filepath);
Node* buildTree(vector<Record> records, vector<string> symptoms);
void buildTreeRecursive(Node* currNode, vector<string> symptoms, int index, vector<bool> route, vector<Record> records);
string findIllnes(vector<string> symptoms, vector<bool> route, vector<Record> records);
void optimalTree(vector<string> records, string symptoms, int depth);
void SplitString(string s, vector<string>& v);

void printVector(vector<string> v);
void printVector(vector<bool> v);
void printVector(vector<vector<bool>> v);

// trim from start 
inline void ltrim(std::string& s);
// trim from end (in place)
inline void rtrim(std::string& s);
// trim from both ends (in place)
inline void trim(std::string& s);


int main()
{
    system("color B");

	/* Manually build a simple tree.
		            cough
		        Yes / \ No
		    fever           healthy
		Yes / \ No
		influenza   cold
	*/

	Node fluLeaf("influenza", nullptr, nullptr);
	Node coldLeaf("cold", nullptr, nullptr);
	Node innerVertex("fever", &fluLeaf, &coldLeaf);
	Node healthyLeaf("healthy", nullptr, nullptr);
	Node root("cough", &innerVertex, &healthyLeaf);

	Diagnoser diagnoser = Diagnoser(&root);

	// Simple test
	vector<string> myVector;
	myVector.push_back("cough");
	string diagnosis = diagnoser.diagnose(myVector);
	if (diagnosis == "cold")
	{
		cout << "Test passed" << endl;
	}
	else
	{
		cout << "Test failed. Should have printed cold, printed: " << diagnosis << endl;
	}
	//TO-DO Add more tests for sections 2 - 7 here.
	vector<string> s = diagnoser.allIllnesses();
	printVector(s);
	vector<vector<bool>> listOfRouteLists = diagnoser.pathsToIllness("cold");
	printVector(listOfRouteLists);

	vector<Record> a;
	
	myVector.push_back("abc");
	myVector.push_back("ddd");
	myVector.push_back("eee");
	//myVector.push_back("fff");
	printVector(myVector);
	a.push_back(Record("hahahahahah", myVector));
	cout << "________________________" << endl;
	
	buildTree(a, myVector);

	system("PAUSE");
}





vector<Record> parseData(string filepath)
{
	/*
	with open(filepath) as data_file:
		records = []
		for line in data_file:
			words = line.strip().split()
			records.append(Record(words[0], words[1:]))
		return records

	*/
	vector<Record> records;
	vector<string> words;
	string myText;
	string illness;
	ifstream MyReadFile(filepath);

	while (getline(MyReadFile, myText)) {
		
		trim(myText);
		SplitString(myText, words);
		
		string illness = words.front();
		words.erase(words.begin());
		records.push_back(Record(illness, words));
	}

	MyReadFile.close();
	
	return records;
}

Node* buildTree(vector<Record> records, vector<string> symptoms)
{
	Node* root;
	if (symptoms.size() == 0)
	{
		root = new Node("None");
	}
	else
	{
		root = new Node(symptoms[0]);
		vector<bool> route;
		buildTreeRecursive(root, symptoms, 1, route, records);
	}
	//TO-DO delete
	//check
	Diagnoser myDiagnoser = Diagnoser(root);
	myDiagnoser.allIllnesses();
	
	
	return root;
}

void buildTreeRecursive(Node* currNode, vector<string> symptoms, int index, vector<bool> route, vector<Record> records)
{
	vector<bool> negetiveRoute = route;
	negetiveRoute.push_back(false);
	vector<bool> positiveRoute = route;
	positiveRoute.push_back(true);

	if (index != symptoms.size())
	{
		cout << "curSymptom: " << symptoms[index] << endl;
		//currNode->data = *currSymptom;
		currNode->negativeChild = new Node(symptoms[index]);
		currNode->positiveChild = new Node(symptoms[index]);
		//vector<string>::iterator temp = currSymptom;
		index++;
		buildTreeRecursive(currNode->negativeChild, symptoms, index, negetiveRoute, records);
		buildTreeRecursive(currNode->positiveChild, symptoms, index, positiveRoute, records);
	}
	else
	{
		/*cout << "Your route is: " << endl;
		printVector(route);
		cout << "___________________________" << endl;*/
		
		//cout << "find illnes negetive : " << findIllnes(symptoms, negetiveRoute, records) << endl;
		currNode->negativeChild = new Node(findIllnes(symptoms, negetiveRoute, records));
		//cout << "find illnes positive: " << findIllnes(symptoms, positiveRoute, records) << endl;
		currNode->positiveChild = new Node(findIllnes(symptoms, positiveRoute, records));
	}
}

string findIllnes(vector<string> symptoms, vector<bool> route, vector<Record> records)
{
	vector<bool>::iterator currRoute;
	map<string, int> illnesses;
	bool flag = true;
	for (vector<Record>::iterator currRecord = records.begin(); currRecord != records.end(); currRecord++)
	{
		currRoute = route.begin();
		flag = true;
		for (vector<string>::iterator cuurSymptom = symptoms.begin(); cuurSymptom != symptoms.end(); cuurSymptom++)
		{
			vector<string>::iterator isFound;
			
			isFound = find(currRecord->symptoms.begin(), currRecord->symptoms.end(), *cuurSymptom);
			if (*currRoute && isFound == currRecord->symptoms.end() ||
				!(*currRoute) && isFound != currRecord->symptoms.end())
			{
				flag = false;
				break;
			}
			currRoute++;
		}
		if (flag)
		{
			illnesses[currRecord->illness] = illnesses[currRecord->illness] + 1;
		}
	}
	//Diagnoser::printMap(illness);
	string bestDiagnoseIllness;
	int bestDiagnoseCount = 0;
	if (illnesses.size() > 0)
	{
		for (map<string, int>::iterator currIllness = illnesses.begin(); currIllness != illnesses.end(); currIllness++)
		{
			if (currIllness->second > bestDiagnoseCount)
			{
				bestDiagnoseCount = currIllness->second;
				bestDiagnoseIllness = currIllness->first;
			}
		}
	}
	else
	{
		bestDiagnoseIllness = "None";
	}
	//cout << "bestDiagnoseIllness = " << bestDiagnoseIllness << endl;
	return bestDiagnoseIllness;
}

void optimalTree(vector<string> records, string symptoms, int depth)
{

}

void SplitString(string s, vector<string>& v) {

	//To-Do add check in start and end;
	string temp = "";
	for (unsigned int i = 0; i < s.length(); ++i) {

		if (s[i] == ' ') {
			v.push_back(temp);
			temp = "";
		}
		else {
			temp.push_back(s[i]);
		}

	}
	v.push_back(temp);

}

void printVector(vector<string> v) {
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	cout << "\n";
}

void printVector(vector<bool> v) {
	for (unsigned int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	cout << "\n";
}

void printVector(vector<vector<bool>> v) {
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		for (unsigned int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j])
			{
				cout << "True, ";
			}
			else
			{
				cout << "False, ";
			}
		}
		cout << endl;
	}
	cout << "\n";
}




// trim from start (in place)
inline void ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
		}));
}

// trim from end (in place)
inline void rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
		}).base(), s.end());
}

// trim from both ends (in place)
inline void trim(std::string& s) {
	ltrim(s);
	rtrim(s);
}