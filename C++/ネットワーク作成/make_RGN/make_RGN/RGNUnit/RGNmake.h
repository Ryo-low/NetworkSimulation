#pragma once
#include "../Common.h"
#include <random>
#define  FIRST_NODE_NUM		4		// �����m�[�h��

class RGNmake {
public:
	// function
	RGNmake();
	~RGNmake();

	void create(unsigned int nodeNum, unsigned int averageLinkNum);

	/*set-get*/
	unsigned int	get_nodeNum();
	unsigned int	get_averageLinkNum();
	NodeList		get_nodeList();
	LinkList		get_linkList();
private:
	// function
		// �l�b�g���[�N�쐬
	void make_network();
	// �����N����쐬
	void select_node(vector<unsigned int>& destNodeList);
	// �����N���쐬
	void make_link(unsigned int newNode, unsigned int destNode);

	// variable
	unsigned int			_nodeNum;
	unsigned int			_averageLinkNum;
	unsigned int			_oneNodeLinkCount;
	NodeList				_nodeList;
	LinkList				_linkList;
	vector<unsigned int>	_selectNodeList;
};

/*set-get*/
inline unsigned int RGNmake::get_nodeNum()
{
	return _nodeNum;
}

inline unsigned int RGNmake::get_averageLinkNum()
{
	return _averageLinkNum;
}

inline NodeList RGNmake::get_nodeList()
{
	return _nodeList;
}

inline LinkList RGNmake::get_linkList()
{
	return _linkList;
}
