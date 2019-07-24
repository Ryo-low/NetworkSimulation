#pragma once
#include <vector>
#include <map>
#include <string>
using namespace std;

// 1�m�[�h���̏��
struct NODE_DATA {
	unsigned int	nodeNo;		// �m�[�h�ԍ�
	string			nodeName;	// �m�[�h��
	string			posX;		// x���W
	string			posY;		// y���W
};

typedef vector<NODE_DATA> NodeList;
typedef map<unsigned int, vector<unsigned int>> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1
#define		ARY_ADJUST		1		// �z�񒲐��p

#define  PAJEK_MATCH_SCALE	1.0		// pajek�ł̕W���X�P�[��