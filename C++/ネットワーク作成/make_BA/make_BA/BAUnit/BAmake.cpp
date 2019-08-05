#include "BAmake.h"
#include <random>

BAmake::BAmake()
{
	_nodeNum			= INT_ZERO;
	_averageLinkNum		= INT_ZERO;
	_oneNodeLinkCount	= INT_ZERO;
}

BAmake::~BAmake()
{
}

void BAmake::create(unsigned int nodeNum, unsigned int averageLinkNum)
{
	bool retVal			= true;
	_nodeNum			= nodeNum;
	_averageLinkNum		= averageLinkNum;
	_oneNodeLinkCount	= (int)(averageLinkNum * 0.5);		// 1ノードごとのリンク数設定
	// ノードリスト作成
	_nodeList.reserve( nodeNum );
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
	}
	// ネットワーク作成
	make_network();
}

void BAmake::make_network()
{
	bool retVal = true;
	// 4node完全グラフ作成
	for( unsigned int nodeNo = INT_ONE; nodeNo < FIRST_NODE_NUM; ++nodeNo ){
		for( unsigned int destNode = FIRST_NODE_NUM; destNode >= INT_ONE; --destNode){
			if( nodeNo == destNode ){
				break;
			}
			make_link( destNode, nodeNo );
		}
	}
	// ノード5からリンク情報生成
	for( unsigned int nodeNo = FIRST_NODE_NUM + INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		UIntVec destNodeList;
		// リンク先ノード決定
		select_node( destNodeList );
		// リンク情報生成
		for( UIntVec::iterator it = destNodeList.begin(); it != destNodeList.end(); ++it ){
			make_link( nodeNo, *it );
		}
	}
}

void BAmake::select_node(UIntVec& destNodeList)
{
	destNodeList.clear();
	random_device				rnd;
	mt19937						mt( rnd() );
	uniform_int_distribution<>	randFormOneToNomeNum( INT_ZERO, ((int)_selectNodeList.size() - ARY_ADJUST) );
	// リンクしているノードのリストからランダムで
	// 平均リンク数/2 だけリンク先を選ぶ
	while( destNodeList.size() < _oneNodeLinkCount ){
		unsigned int destNode = _selectNodeList[randFormOneToNomeNum(mt)];
		if( find(destNodeList.begin(), destNodeList.end(), destNode) == destNodeList.end() ){
			destNodeList.push_back( destNode );
		}
	}
}


void BAmake::make_link(unsigned int newNode, unsigned int destNode)
{
	// 出力用リンク情報
	UIntVec& destNodeList = _linkList[destNode - ARY_ADJUST];
	destNodeList.push_back( newNode );
	// リンク先選択用リンク情報
	_selectNodeList.push_back( newNode );
	_selectNodeList.push_back( destNode );
}