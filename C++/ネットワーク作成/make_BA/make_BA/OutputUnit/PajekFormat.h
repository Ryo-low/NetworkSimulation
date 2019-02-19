#pragma once
/*
出力ネットワーク：ランダムネットワーク
ファイル名：RNノード数N平均リンク数k.txt

*/
#include "../Common.h"
#include<fstream>

#define		NETWORK_NAME			"BA-"
#define		FILENAME_NODE			"N"
#define		FILENAME_LINK			"K"
#define		REPRES_PAJEK_FIRST		"*Vertices"
#define		REPRES_PAJEK_SECOND		"*Edges"

class PajekFormat
{
public:
	PajekFormat(unsigned int nodeNum, unsigned int averageLinkNum);
	~PajekFormat();

	void output_network(NodeList nodeList, LinkList linkList);
private:
	unsigned int	_nodeNum;
	unsigned int	_averageLinkNum;
	string			_fileName;
};