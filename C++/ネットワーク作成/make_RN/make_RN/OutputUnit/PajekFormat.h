#pragma once
/*
�o�̓l�b�g���[�N�F�����_���l�b�g���[�N
�t�@�C�����FRN�m�[�h��N���σ����N��k.txt

*/
#include "../Common.h"

#define		NETWORK_NAME			"RN"
#define		REPRES_PAJEK_FIRST		"*Vertices"
#define		REPRES_PAJEK_SECOND		"*Edges"

class PajekFormat
{
public:
	PajekFormat();
	~PajekFormat();

	bool output_network(NodeList nodeList, LinkList linkList);
private:

};