#pragma once
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// 1�m�[�h���̏��
struct NODE_DATA {
	unsigned int	nodeNo;		// �m�[�h�ԍ�
	string			nodeName;	// �m�[�h��
	double	posX;		// x���W
	double	posY;		// y���W
};

typedef vector<NODE_DATA> NodeList;
typedef list<unsigned int> UintList;
typedef unordered_map<unsigned int, UintList> LinkList;

#define		INT_ZERO		0
#define		INT_ONE			1
#define		ARY_ADJUST		1		// �z�񒲐��p
#define		HALF_DIVISION	0.5		// 2�Ŋ���Ƃ��̋t���Z�o����

#define		PAJEK_MATCH_SCALE	1.0		// pajek�ł̕W���X�P�[��