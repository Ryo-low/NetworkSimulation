#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

// 1ノード分の情報
struct NODE_DATA {
	unsigned int	nodeNo;		// ノード番号
	string			nodeName;	// ノード名
	string			posX;		// x座標
	string			posY;		// y座標
};

typedef vector<NODE_DATA> NodeList;
typedef map<unsigned int, vector<unsigned int>> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1
#define		ARY_ADJUST		1		// 配列調整用

#define  PAJEK_MATCH_SCALE	1.0		// pajekでの標準スケール