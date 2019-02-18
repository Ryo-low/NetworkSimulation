#include "BAmake.h"

BAmake::BAmake()
{
	_nodeNum			= INT_ZERO;
	_averageLinkNum		= INT_ZERO;
	_oneNodeLinkNum		= INT_ZERO;
}

BAmake::~BAmake()
{
}

bool BAmake::create(unsigned int nodeNum, unsigned int averageLinkNum)
{
	bool retVal = true;
	_nodeNum		= nodeNum;
	_averageLinkNum = averageLinkNum;
	_oneNodeLinkNum = (int)(averageLinkNum * 0.5);
	for (unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo) {
		// ノードリスト作成
		NODE_DATA oneNode;
		oneNode.nodeNo = nodeNo;
		oneNode.nodeName = to_string(nodeNo);
		_nodeList.push_back(oneNode);
		// 空でリンクリストを作成
		vector<unsigned int>	empty;
		_linkList[nodeNo] = empty;
	}

	retVal = make_network();
	return retVal;
}

bool BAmake::make_network()
{
	bool retVal = true;
	// 4node完全グラフ
	for( unsigned int nodeNum = INT_ONE; nodeNum <= FIRST_NODE_NUM; ++nodeNum ){
		for( unsigned int destNode = FIRST_NODE_NUM; destNode >= INT_ONE; --destNode){
			if( nodeNum == destNode ){
				break;
			}
			make_link( destNode, nodeNum );
		}
	}

	return retVal;
}


void BAmake::make_link(unsigned int newNode, unsigned int destNode)
{
	vector<unsigned int> destNodeList = _linkList[destNode];
	destNodeList.push_back( newNode );
	_linkList[destNode] = destNodeList;

	_selectNodeList.push_back( newNode );
	_selectNodeList.push_back( destNode );
}