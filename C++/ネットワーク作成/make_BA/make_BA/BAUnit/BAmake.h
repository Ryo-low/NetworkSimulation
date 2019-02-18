#pragma once
#include "../Common.h"
#include <random>
#define  FIRST_NODE_NUM		4		// 初期ノード数

class BAmake {
public:
	// function
	BAmake();
	~BAmake();

	bool create(unsigned int nodeNum, unsigned int averageLinkNum);

	/*set-get*/
	unsigned int	get_nodeNum();
	unsigned int	get_averageLinkNum();
	NodeList		get_nodeList();
	LinkList		get_linkList();
private:
	// function
		// ネットワーク作成
	bool make_network();
	// リンク相手作成
	void select_node(vector<unsigned int>& destNodeList);
	// リンク情報作成
	void make_link(unsigned int newNode, unsigned int destNode);

	// variable
	unsigned int			_nodeNum;
	unsigned int			_averageLinkNum;
	unsigned int			_oneNodeLinkNum;
	NodeList				_nodeList;
	LinkList				_linkList;
	vector<unsigned int>	_selectNodeList;
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
