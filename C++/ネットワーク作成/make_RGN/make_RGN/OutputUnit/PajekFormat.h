#pragma once
/*
�o�̓l�b�g���[�N�F�����_���l�b�g���[�N
�t�@�C�����FRGN�m�[�h��N���σ����N��k.txt

*/
#include "../Common.h"
#include <fstream>
// �o�̓t�@�C�����֘A��`
#define		NETWORK_NAME			"RGN-"
#define		FILENAME_NODE			"N"
#define		FILENAME_LINK			"K"

// pajek�`���o�͎��֘A��`
#define		REPRES_PAJEK_FIRST		"*Vertices"
#define		REPRES_PAJEK_SECOND		"*Edges"

class PajekFormat
{
public:
	PajekFormat(unsigned int nodeNum, unsigned int averageLinkNum);
	~PajekFormat();

	// �l�b�g���[�N����pajek�`���ŏo��
	void output_network(NodeList nodeList, LinkList linkList);
private:
	unsigned int	_nodeNum;			// �m�[�h��
	unsigned int	_averageLinkNum;	// ���σ����N��
	string			_fileName;			// �o�̓t�@�C����
};