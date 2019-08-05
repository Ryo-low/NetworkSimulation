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
	_oneNodeLinkCount	= (int)(averageLinkNum * 0.5);		// 1�m�[�h���Ƃ̃����N���ݒ�
	// �m�[�h���X�g�쐬
	_nodeList.reserve( nodeNum );
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
	}
	// �l�b�g���[�N�쐬
	make_network();
}

void BAmake::make_network()
{
	bool retVal = true;
	// 4node���S�O���t�쐬
	for( unsigned int nodeNo = INT_ONE; nodeNo < FIRST_NODE_NUM; ++nodeNo ){
		for( unsigned int destNode = FIRST_NODE_NUM; destNode >= INT_ONE; --destNode){
			if( nodeNo == destNode ){
				break;
			}
			make_link( destNode, nodeNo );
		}
	}
	// �m�[�h5���烊���N��񐶐�
	for( unsigned int nodeNo = FIRST_NODE_NUM + INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		UIntVec destNodeList;
		// �����N��m�[�h����
		select_node( destNodeList );
		// �����N��񐶐�
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
	// �����N���Ă���m�[�h�̃��X�g���烉���_����
	// ���σ����N��/2 ���������N���I��
	while( destNodeList.size() < _oneNodeLinkCount ){
		unsigned int destNode = _selectNodeList[randFormOneToNomeNum(mt)];
		if( find(destNodeList.begin(), destNodeList.end(), destNode) == destNodeList.end() ){
			destNodeList.push_back( destNode );
		}
	}
}


void BAmake::make_link(unsigned int newNode, unsigned int destNode)
{
	// �o�͗p�����N���
	UIntVec& destNodeList = _linkList[destNode - ARY_ADJUST];
	destNodeList.push_back( newNode );
	// �����N��I��p�����N���
	_selectNodeList.push_back( newNode );
	_selectNodeList.push_back( destNode );
}