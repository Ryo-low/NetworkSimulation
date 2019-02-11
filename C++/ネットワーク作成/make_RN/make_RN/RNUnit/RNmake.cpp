#include "RNmake.h"

RNmake::RNmake()
{
	_nodeNum		= INT_ZERO;
	_averageLinkNum	= INT_ZERO;
}

RNmake::~RNmake()
{
}

bool RNmake::create( unsigned int nodeNum, unsigned int averageLinkNum )
{
	bool retVal		= true;
	_nodeNum		= nodeNum;
	_averageLinkNum	= averageLinkNum;
	_allLinkNum		= (unsigned int)(_nodeNum * _averageLinkNum * 0.5);
	retVal			= make_network();

	return retVal;
}

bool RNmake::make_network()
{
	bool retVal = true;
	for( unsigned int linkNo = INT_ZERO; linkNo <= _allLinkNum; ++linkNo ){
		bool saveFlag = false;
		while( saveFlag == false ){
			unsigned int	nodeA	= INT_ZERO;
			unsigned int	nodeB	= INT_ZERO;
			select_node( nodeA, nodeB );

		}
	}

}

void RNmake::select_node( unsigned int& nodeA, unsigned int& nodeB )
{
	random_device				rnd;
	mt19937						mt( rnd() );
	uniform_int_distribution<>	randFormOneToNomeNum( INT_ONE, _nodeNum );
	nodeA	= INT_ZERO;
	nodeB	= INT_ZERO;
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