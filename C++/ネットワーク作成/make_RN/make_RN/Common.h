#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

struct NODE_DATA{
	int		nodeNo;
	string	nodeName;
	string	posX;
	string	posY;
};

typedef vector<NODE_DATA> NodeList;
typedef map<int, vector<int>> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1