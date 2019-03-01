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

void RGNmake::create(unsigned int nodeNum, unsigned int averageLinkNum, unsigned int scale)
{
	bool retVal			= true;
	_nodeNum			= nodeNum;
	_averageLinkNum		= averageLinkNum;
	_scale				= scale;
	_communicationRange	= averageLinkNum * (scale * scale) / (M_PI * nodeNum);
	random_device				rnd;
	mt19937						mt(rnd());
	uniform_int_distribution<>	randFormOneToNomeNum(INT_ZERO, scale);
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

	make_network();
}

void RGNmake::make_network()
{
	bool retVal = true;
	// 4node完全グラフ
	for (unsigned int nodeNo = INT_ONE; nodeNo < FIRST_NODE_NUM; ++nodeNo) {
		for (unsigned int destNode = FIRST_NODE_NUM; destNode >= INT_ONE; --destNode) {
			if (nodeNo == destNode) {
				break;
			}
			make_link(destNode, nodeNo);
		}
	}

	for (unsigned int nodeNo = FIRST_NODE_NUM + INT_ONE; nodeNo <= _nodeNum; ++nodeNo) {
		vector<unsigned int> destNodeList;
		select_node(destNodeList);
		for (vector<unsigned int>::iterator it = destNodeList.begin(); it != destNodeList.end(); ++it) {
			make_link(nodeNo, *it);
		}
	}
}

void RGNmake::select_node(vector<unsigned int>& destNodeList)
{
	destNodeList.clear();
	random_device				rnd;
	mt19937						mt(rnd());
	uniform_int_distribution<>	randFormOneToNomeNum(INT_ZERO, ((int)_selectNodeList.size() - ARY_ADJUST));

	while (destNodeList.size() < _oneNodeLinkCount) {
		unsigned int destNode = _selectNodeList[randFormOneToNomeNum(mt)];
		if (find(destNodeList.begin(), destNodeList.end(), destNode) == destNodeList.end()) {
			destNodeList.push_back(destNode);
		}
	}
}


void RGNmake::make_link(unsigned int newNode, unsigned int destNode)
{
	vector<unsigned int> destNodeList = _linkList[destNode];
	destNodeList.push_back(newNode);
	_linkList[destNode] = destNodeList;

	_selectNodeList.push_back(newNode);
	_selectNodeList.push_back(destNode);
}