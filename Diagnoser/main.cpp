#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Diagnoser.h"
#include "Node.h"
#include "Record.h"



vector<Record> parseData(string filepath);
void build_tree(vector<string> records, string symptoms);
void optimal_tree(vector<string> records, string symptoms, int depth);
void SplitString(string s, vector<string>& v);
void PrintVector(vector<string> v);

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

	Node flu_leaf("influenza", nullptr, nullptr);
	Node cold_leaf("cold", nullptr, nullptr);
	Node inner_vertex("fever", &flu_leaf, &cold_leaf);
	Node healthy_leaf("healthy", nullptr, nullptr);
	Node root("cough", &inner_vertex, &healthy_leaf);

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

void build_tree(vector<string> records, string symptoms)
{

}

void optimal_tree(vector<string> records, string symptoms, int depth)
{

}

void SplitString(string s, vector<string>& v) {

	//To-Do add check in start and end;
	string temp = "";
	for (int i = 0; i < s.length(); ++i) {

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

void PrintVector(vector<string> v) {
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
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