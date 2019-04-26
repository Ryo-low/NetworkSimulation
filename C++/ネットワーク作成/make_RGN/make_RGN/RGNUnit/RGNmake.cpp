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
	// �m�[�h���X�g�쐬
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		_nodeList.emplace_back();
		NODE_DATA& oneNode	= _nodeList.back();
		oneNode.nodeNo		= nodeNo;
		oneNode.nodeName	= to_string( nodeNo );
		// �m�[�h���W����
		oneNode.posX		= nodePosition( mt );
		oneNode.posY		= nodePosition( mt );
	}
	// �l�b�g���[�N�쐬
	make_network();
}

void RGNmake::make_network()
{
	bool retVal = true;
	// �S�m�[�h�����N�`�F�b�N�J�n
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		// �������g���������m�[�h���猟���J�n
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