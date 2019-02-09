#pragma once
#include "../Common.h"
#include <random>

class RNmake{
public:
// function
	RNmake();
	~RNmake();

	bool create(unsigned int nodeNum, unsigned int averageLinkNum);

private:
// function
	// ネットワーク作成
	bool make_network();
	// リンク相手作成
	void select_node(unsigned int& nodeA, unsigned int& nodeB);
	
	/*set-get*/
	unsigned int	get_nodeNum();
	unsigned int	get_averageLinkNum();
	NodeList		get_nodeList();
	LinkList		get_linkList();

// variable
	unsigned int	_nodeNum;
	unsigned int	_averageLinkNum;
	unsigned int	_allLinkNum;
	NodeList		_nodeList;
	LinkList		_linkList;
};

/*set-get*/
inline unsigned int RNmake::get_nodeNum()
{
	return _nodeNum;
}

inline unsigned int RNmake::get_averageLinkNum()
{
	return _averageLinkNum;
}

inline NodeList RNmake::get_nodeList()
{
	return _nodeList;
}

inline LinkList RNmake::get_linkList()
{
	return _linkList;
}
