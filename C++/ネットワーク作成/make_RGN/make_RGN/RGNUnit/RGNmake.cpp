#include "RGNmake.h"
#define _USE_MATH_DEFINES

#include <math.h>
#include <cmath>

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
	_nodeNum			= nodeNum;
	_averageLinkNum		= averageLinkNum;
	_scale				= scale;
	_communicationRange	= averageLinkNum * (scale * scale) / (M_PI * nodeNum);		// 通信可能距離算出
	// ノードの分布をランダムで決めるため、以下を使用する
	random_device				rnd;
	default_random_engine		engine( rnd() );
	uniform_real_distribution<>	nodePosition( SCALE_MIN, scale );
	// ノードリスト作成
	_nodeList.reserve( _nodeNum );
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
		// ノード座標決定
		oneNode.posX		= nodePosition( engine );
		oneNode.posY		= nodePosition( engine );
	}
	// ネットワーク作成
	make_network();
}

void RGNmake::make_network()
{
	// 全ノードリンクチェック開始
	for( unsigned int baseNodeNo = INT_ONE; baseNodeNo <= _nodeNum; ++baseNodeNo ){
		// 自分自身を除く次ノードから行う
		// 多重リンクを防ぐため、次のノードからチェック開始
		for( unsigned int destNodeNo = baseNodeNo + INT_ONE; destNodeNo <= _nodeNum; ++destNodeNo ){
			if( check_linkRange(_nodeList[baseNodeNo - ARY_ADJUST], _nodeList[destNodeNo - ARY_ADJUST]) == true ){
				add_link( _nodeList[baseNodeNo - ARY_ADJUST].nodeNo, _nodeList[destNodeNo - ARY_ADJUST].nodeNo );
			}
		}
	}
}

bool RGNmake::check_linkRange(const NODE_DATA& baseNode, const NODE_DATA& destNode)
{
	bool	retVal		= false;
	// ノード間距離算出
	double	distanceX	= fabs( baseNode.posX - destNode.posX );
	double	distanceY	= fabs( baseNode.posY - destNode.posY );
	// スケールの半分を超えている場合、
	// 反対側の距離でリンクする可能性がある
	double	halfScale	= _scale * HALF_DIVISION;
	if( distanceX >= halfScale ){
		distanceX = fabs( distanceX - _scale );
	}
	if( distanceY >= halfScale ){
		distanceY = fabs( distanceY - _scale );
	}
	// 通信可否判定
	if( (distanceX * distanceX + distanceY * distanceY) <= _communicationRange ){
		retVal = true;
	}
	return retVal;
}

void RGNmake::add_link(unsigned int baseNode, unsigned int destNode)
{
	_linkList[baseNode - ARY_ADJUST].push_back( destNode );
}