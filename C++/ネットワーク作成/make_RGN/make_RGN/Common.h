#pragma once
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// 1ノード分の情報
struct NODE_DATA {
	unsigned int	nodeNo;		// ノード番号
	string			nodeName;	// ノード名
	double	posX;		// x座標
	double	posY;		// y座標
};

typedef vector<NODE_DATA> NodeList;
typedef list<unsigned int> UintList;
typedef unordered_map<unsigned int, UintList> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1
#define		ARY_ADJUST		1		// 配列調整用
#define		HALF_DIVISION	0.5		// 2で割るときの逆数算出結果

#define		PAJEK_MATCH_SCALE	1.0		// pajekでの標準スケール