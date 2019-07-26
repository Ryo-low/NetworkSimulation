#include "PajekFormat.h"


PajekFormat::PajekFormat( unsigned int nodeNum, unsigned int averageLinkNum )
{
	_nodeNum		= nodeNum;
	_averageLinkNum	= averageLinkNum;
}

PajekFormat::~PajekFormat()
{
}

void PajekFormat::output_network( NodeList nodeList, LinkList linkList )
{
	_fileName	= NETWORK_NAME + to_string(_nodeNum) + FILENAME_NODE
		+ to_string(_averageLinkNum) + FILENAME_LINK + ".txt";
	ofstream outputFile( _fileName );

	// ノードリスト出力
	outputFile << REPRES_PAJEK_FIRST << " " << _nodeNum << endl;
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		outputFile << nodeList[nodeNo - ARY_ADJUST].nodeNo << " ";
		outputFile << nodeList[nodeNo - ARY_ADJUST].nodeName << " ";
		outputFile << nodeList[nodeNo - ARY_ADJUST].posX << " ";
		outputFile << nodeList[nodeNo - ARY_ADJUST].posY << endl;
	}
	
	// リンクリスト出力
	outputFile << REPRES_PAJEK_SECOND << endl;
	for( unsigned int nodeNo = INT_ONE; nodeNo <= _nodeNum; ++nodeNo ){
		UintList& distNodeList = linkList[nodeNo - ARY_ADJUST];
		for( UintList::iterator it = distNodeList.begin(); it != distNodeList.end(); ++it ){
			outputFile << nodeNo << " " << *it << " " << 1 << endl;
		}
	}
}