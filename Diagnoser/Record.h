#pragma once
#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Record
{
	/*
	Node department, save the data of the node and pointer to the next
	children, if its leaf the child is empty
	*/
public:
	Record(string illness, string symptoms);
	~Record();

private:
	string _illness;
	string _symptoms;
	
};