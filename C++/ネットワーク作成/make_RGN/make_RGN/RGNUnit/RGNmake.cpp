#include "RGNmake.h"
#define _USE_MATH_DEFINES
#include <math.h>

RGNmake::RGNmake()
{
	_nodeNum			= INT_ZERO;
	_averageLinkNum		= INT_ZERO;
	_scale				= INT_ZERO;
	_communicationRange	= INT_ZERO;
}

RGNmake::~RGNmake()
{
}

void RGNmake::create(unsigned int nodeNum, unsigned int averageLinkNum, double scale)
{
	bool retVal			= true;
	_nodeNum			= nodeNum;
	_averageLinkNum		= averageLinkNum;
	_scale				= scale;
	_communicationRange	= averageLinkNum * (scale * scale) / (M_PI * nodeNum);
	random_device		rnd;
	mt19937				mt( rnd() );
	uniform_int_distribution<>	nodePosition( SCALE_MIN, scale );
	// ノードリスト作成
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
		// ノード座標決定
		oneNode.posX		= nodePosition( mt );
		oneNode.posY		= nodePosition( mt );
	}
	// ネットワーク作成
	make_network();
}

void RGNmake::make_network()
{
	bool retVal = true;
	// 全ノードリンクチェック開始
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		// 自分自身を除く次ノードから検索開始
		for( unsigned int destNodeNo = nodeNo + INT_ONE; destNodeNo <= _nodeNum; ++destNodeNo ){
			if( check_linkRange(_nodeList[nodeNo], _nodeList[destNodeNo]) == true ){
				;
			}
		}
	}
}

bool RGNmake::check_linkRange(NODE_DATA& baseNode, NODE_DATA& destNode)
{

}