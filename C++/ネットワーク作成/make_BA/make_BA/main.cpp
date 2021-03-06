﻿#include "main.h"

int main(int argc, char* args[])
{
	unsigned int nodeNum		= INT_ZERO;
	unsigned int averageLinkNum	= INT_ZERO;
	if( argc == NEED_ARGS_NUM ){
		nodeNum			= atoi( args[ARGS_NODE_NUM] );
		averageLinkNum	= atoi( args[ARGS_AVERAGE_LINK_NUM] );
	}
	else {
		cout << "引数不足による対話モード" << endl;
		cout << "ノード数指定" << endl;
		cin >> nodeNum;

		cout << "平均リンク数指定" << endl;
		cin >> averageLinkNum;
	}
	chrono::system_clock::time_point  start, end;
	start = chrono::system_clock::now();
	// 作成
	BAmake baMake = BAmake();
	baMake.create( nodeNum, averageLinkNum );
	// 出力
	PajekFormat pajekFormat = PajekFormat( nodeNum, averageLinkNum );
	pajekFormat.output_network( baMake.get_nodeList(), baMake.get_linkList() );
	
	end = chrono::system_clock::now();
	double elapsed = (double)chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << elapsed << "millisec" << endl;
	cout << "文字入力して終了" << endl;
	string tmp;
	cin >> tmp;
	return 0;
}