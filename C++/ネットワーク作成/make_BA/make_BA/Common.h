#pragma once
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

struct NODE_DATA {
	unsigned int	nodeNo;
	string			nodeName;
	string			posX;
	string			posY;
};

typedef vector<NODE_DATA> NodeList;
typedef vector<unsigned int> UIntVec;
typedef unordered_map<unsigned int, UIntVec> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1
#define		ARY_ADJUST		1