#include "PajekFormat.h"
#include <fstream>

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
	// �o�̓t�@�C�����쐬
	_fileName	= NETWORK_NAME + to_string(_nodeNum) + FILENAME_NODE
		+ to_string(_averageLinkNum) + FILENAME_LINK + ".txt";
	ofstream outputFile(_fileName);

	// �m�[�h���X�g�o��
	outputFile << REPRES_PAJEK_FIRST << " " << _nodeNum << endl;
	for( unsigned int nodeNo = INT_ZERO; nodeNo < _nodeNum; ++nodeNo ){
		outputFile << nodeList[nodeNo].nodeNo << " ";
		outputFile << nodeList[nodeNo].nodeName << " ";
		outputFile << nodeList[nodeNo].posX << " ";
		outputFile << nodeList[nodeNo].posY << endl;
	}
	// �����N���X�g�o��
	outputFile << REPRES_PAJEK_SECOND << endl;
	for( unsigned int nodeNo = INT_ZERO; nodeNo < _nodeNum; ++nodeNo ){
		UIntVec distNodeList;
		distNodeList = linkList[nodeNo];
		for( UIntVec::iterator it = distNodeList.begin(); it != distNodeList.end(); ++it ){
			outputFile << nodeNo << " " << *it << " " << 1 << endl;
		}
	}
}