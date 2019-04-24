#include "RNmake.h"

RNmake::RNmake()
{
	_nodeNum		= INT_ZERO;
	_averageLinkNum	= INT_ZERO;
}

RNmake::~RNmake()
{
}
// RNを作成する
bool RNmake::create( unsigned int nodeNum, unsigned int averageLinkNum )
{
	bool retVal		= true;
	_nodeNum		= nodeNum;
	_averageLinkNum	= averageLinkNum;
	_allLinkNum		= (unsigned int)(_nodeNum * _averageLinkNum * 0.5);
	// ノード情報の作成
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
	}
	// ネットワーク情報の作成
	retVal			= make_network();
	return retVal;
}

bool RNmake::make_network()
{
	bool			retVal	= true;
	unsigned int	nodeA	= INT_ZERO;
	unsigned int	nodeB	= INT_ZERO;
	for( unsigned int linkNo = INT_ZERO; linkNo < _allLinkNum; ++linkNo ){
		// 異なる2つのノードを選択
		select_node( nodeA, nodeB );
		vector<unsigned int>&	destNodeList = _linkList[nodeA];
		// リンク先ノード配列を検索し、
		// リンク候補ノードが存在しない場合は追加
		if( find(destNodeList.begin(), destNodeList.end(), nodeB) == destNodeList.end() ){
			destNodeList.emplace_back( nodeB );
		}
		else{
			--linkNo;		// リンク済みの場合、多重リンクとせずリンク数としてカウントしない
		}
	}
	return retVal;
}

void RNmake::select_node( unsigned int& nodeA, unsigned int& nodeB )
{
	random_device				rnd;
	mt19937						mt( rnd() );
	uniform_int_distribution<>	randFormOneToNomeNum( INT_ONE, _nodeNum );
	nodeA	= INT_ZERO;
	nodeB	= INT_ZERO;
	// 異なる2つのノードを選択し、A <= B 必ずの状態にする
	while( nodeA == nodeB ){
		nodeA	= randFormOneToNomeNum( mt );
		nodeB	= randFormOneToNomeNum( mt );
	}
	if( nodeA > nodeB ){
		unsigned int tmp = INT_ZERO;
		tmp		= nodeA;
		nodeA	= nodeB;
		nodeB	= tmp;
	}
}