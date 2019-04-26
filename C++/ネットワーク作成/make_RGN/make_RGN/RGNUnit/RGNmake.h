#pragma once
#include "../Common.h"
#include <random>
#define  FIRST_NODE_NUM		4		// 初期ノード数
#define  SCALE_MIN			0.0		// スケール最小値


class RGNmake {
public:
	// function
	RGNmake();
	~RGNmake();

	void create(unsigned int nodeNum, unsigned int averageLinkNum, double scale = PAJEK_MATCH_SCALE);

	/*set-get*/
	unsigned int	get_nodeNum();
	unsigned int	get_averageLinkNum();
	NodeList		get_nodeList();
	LinkList		get_linkList();
private:
	// function
		// ネットワーク作成
	void make_network();
	// リンク可能距離チェック
	bool check_linkRange(NODE_DATA& baseNode, NODE_DATA& destNode);

	// variable
	unsigned int			_nodeNum;
	unsigned int			_averageLinkNum;
	double					_scale;
	double					_communicationRange;
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
