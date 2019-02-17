#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

struct NODE_DATA {
	unsigned int	nodeNo;
	string			nodeName;
	string			posX;
	string			posY;
};

typedef vector<NODE_DATA> NodeList;
typedef map<unsigned int, vector<unsigned int>> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1