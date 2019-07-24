#pragma once
/*
出力ネットワーク：ランダムネットワーク
ファイル名：RGNノード数N平均リンク数k.txt

*/
#include "../Common.h"
#include <fstream>
// 出力ファイル名関連定義
#define		NETWORK_NAME			"RGN-"
#define		FILENAME_NODE			"N"
#define		FILENAME_LINK			"K"

// pajek形式出力時関連定義
#define		REPRES_PAJEK_FIRST		"*Vertices"
#define		REPRES_PAJEK_SECOND		"*Edges"

class PajekFormat
{
public:
	PajekFormat(unsigned int nodeNum, unsigned int averageLinkNum);
	~PajekFormat();

	// ネットワーク情報をpajek形式で出力
	void output_network(NodeList nodeList, LinkList linkList);
private:
	unsigned int	_nodeNum;			// ノード数
	unsigned int	_averageLinkNum;	// 平均リンク数
	string			_fileName;			// 出力ファイル名
};