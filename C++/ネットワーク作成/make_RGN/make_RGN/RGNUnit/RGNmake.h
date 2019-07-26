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
	// 情報生成関数
	void create(unsigned int nodeNum, unsigned int averageLinkNum, double scale = PAJEK_MATCH_SCALE);

	/*set-get*/
	// ノード数取得
	unsigned int	get_nodeNum();
	// 平均リンク数取得
	unsigned int	get_averageLinkNum();
	// ノード情報リスト取得
	NodeList		get_nodeList();
	// リンク情報リスト取得
	LinkList		get_linkList();

private:
	// function
	// ネットワーク作成
	void make_network();
	// リンク可能距離チェック
	bool check_linkRange(const NODE_DATA& baseNode, const NODE_DATA& destNode);
	// 指定ノードとのリンクを生成
	void add_link(unsigned int baseNode, unsigned int destNode);

	// variable
	unsigned int			_nodeNum;				// ノード数
	unsigned int			_averageLinkNum;		// 平均リンク数
	double					_scale;					// ネットワークのスケール
	double					_communicationRange;	// 通信可能距離
	NodeList				_nodeList;				// ノード情報リスト
	LinkList				_linkList;				// リンク情報リスト
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
