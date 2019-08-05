#pragma once
#include "../Common.h"
#define  FIRST_NODE_NUM		4		// �����m�[�h��

class BAmake {
public:
	// function
	BAmake();
	~BAmake();
	// BA����
	void create(unsigned int nodeNum, unsigned int averageLinkNum);

	/*set-get*/
	// �m�[�h���擾
	unsigned int	get_nodeNum();
	// ���σ����N���擾
	unsigned int	get_averageLinkNum();
	// �m�[�h���擾
	NodeList		get_nodeList();
	// �����N���擾
	LinkList		get_linkList();
private:
	// function
		// �l�b�g���[�N�쐬
	void make_network();
	// �����N����쐬
	void select_node(UIntVec& destNodeList);
	// �����N���쐬
	void make_link(unsigned int newNode, unsigned int destNode);

	unsigned int	_nodeNum;				// �m�[�h��
	unsigned int	_averageLinkNum;		// ���σ����N��
	unsigned int	_oneNodeLinkCount;		// �����N��I����
	NodeList		_nodeList;				// �o�͗p�m�[�h���X�g
	LinkList		_linkList;				// �o�͗p�����N���X�g
	UIntVec			_selectNodeList;		// �����N��I��p�����N���X�g
};

/*set-get*/
inline unsigned int BAmake::get_nodeNum()
{
	return _nodeNum;
}

inline unsigned int BAmake::get_averageLinkNum()
{
	return _averageLinkNum;
}

inline NodeList BAmake::get_nodeList()
{
	return _nodeList;
}

inline LinkList BAmake::get_linkList()
{
	return _linkList;
}
