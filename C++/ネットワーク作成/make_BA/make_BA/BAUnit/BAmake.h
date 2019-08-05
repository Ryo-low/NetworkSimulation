#pragma once
#include "../Common.h"
#define  FIRST_NODE_NUM		4		// 初期ノード数

class BAmake {
public:
	// function
	BAmake();
	~BAmake();
	// BA生成
	void create(unsigned int nodeNum, unsigned int averageLinkNum);

	/*set-get*/
	// ノード数取得
	unsigned int	get_nodeNum();
	// 平均リンク数取得
	unsigned int	get_averageLinkNum();
	// ノード情報取得
	NodeList		get_nodeList();
	// リンク情報取得
	LinkList		get_linkList();
private:
	// function
		// ネットワーク作成
	void make_network();
	// リンク相手作成
	void select_node(UIntVec& destNodeList);
	// リンク情報作成
	void make_link(unsigned int newNode, unsigned int destNode);

	unsigned int	_nodeNum;				// ノード数
	unsigned int	_averageLinkNum;		// 平均リンク数
	unsigned int	_oneNodeLinkCount;		// リンク先選択個数
	NodeList		_nodeList;				// 出力用ノードリスト
	LinkList		_linkList;				// 出力用リンクリスト
	UIntVec			_selectNodeList;		// リンク先選択用リンクリスト
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
