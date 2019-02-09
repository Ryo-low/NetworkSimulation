#pragma once
/*
出力ネットワーク：ランダムネットワーク
ファイル名：RNノード数N平均リンク数k.txt

*/
#include "../Common.h"

#define		NETWORK_NAME			"RN"
#define		REPRES_PAJEK_FIRST		"*Vertices"
#define		REPRES_PAJEK_SECOND		"*Edges"

class PajekFormat
{
public:
	PajekFormat();
	~PajekFormat();

	bool output_network(NodeList nodeList, LinkList linkList);
private:

};