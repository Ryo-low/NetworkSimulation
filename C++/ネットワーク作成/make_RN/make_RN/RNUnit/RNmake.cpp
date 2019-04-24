#include "RNmake.h"

RNmake::RNmake()
{
	_nodeNum		= INT_ZERO;
	_averageLinkNum	= INT_ZERO;
}

RNmake::~RNmake()
{
}
// RN���쐬����
bool RNmake::create( unsigned int nodeNum, unsigned int averageLinkNum )
{
	bool retVal		= true;
	_nodeNum		= nodeNum;
	_averageLinkNum	= averageLinkNum;
	_allLinkNum		= (unsigned int)(_nodeNum * _averageLinkNum * 0.5);
	// �m�[�h���̍쐬
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
	}
	// �l�b�g���[�N���̍쐬
	retVal			= make_network();
	return retVal;
}

bool RNmake::make_network()
{
	bool			retVal	= true;
	unsigned int	nodeA	= INT_ZERO;
	unsigned int	nodeB	= INT_ZERO;
	for( unsigned int linkNo = INT_ZERO; linkNo < _allLinkNum; ++linkNo ){
		// �قȂ�2�̃m�[�h��I��
		select_node( nodeA, nodeB );
		vector<unsigned int>&	destNodeList = _linkList[nodeA];
		// �����N��m�[�h�z����������A
		// �����N���m�[�h�����݂��Ȃ��ꍇ�͒ǉ�
		if( find(destNodeList.begin(), destNodeList.end(), nodeB) == destNodeList.end() ){
			destNodeList.emplace_back( nodeB );
		}
		else{
			--linkNo;		// �����N�ς݂̏ꍇ�A���d�����N�Ƃ��������N���Ƃ��ăJ�E���g���Ȃ�
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
	// �قȂ�2�̃m�[�h��I�����AA <= B �K���̏�Ԃɂ���
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