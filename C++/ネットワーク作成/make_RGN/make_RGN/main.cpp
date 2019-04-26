#include "main.h"

int main(int argc, char* args[])
{
	unsigned int	nodeNum			= INT_ZERO;
	unsigned int	averageLinkNum	= INT_ZERO;
	double			scale			= PAJEK_MATCH_SCALE;
	if( argc >= NEED_ARGS_NUM ){
		nodeNum = atoi(args[ARGS_NODE_NUM]);
		averageLinkNum = atoi(args[ARGS_AVERAGE_LINK_NUM]);
	}
	else if(argc == SCALE_SPCIFY_ARGS){
		scale = atof( args[ARGS_SCALE] );
	}
	else{
		cout << "�����s���ɂ��Θb���[�h" << endl;
		cout << "�m�[�h���w��" << endl;
		cin >> nodeNum;

		cout << "���σ����N���w��" << endl;
		cin >> averageLinkNum;
	}
	chrono::system_clock::time_point  start, end;
	start = chrono::system_clock::now();
	// �쐬
	RGNmake rgnMake = RGNmake();
	rgnMake.create( nodeNum, averageLinkNum, scale );
	// �o��
	PajekFormat pajekFormat = PajekFormat( nodeNum, averageLinkNum );
	pajekFormat.output_network( rgnMake.get_nodeList(), rgnMake.get_linkList() );

	end = chrono::system_clock::now();
	double elapsed = (double)chrono::duration_cast<chrono::milliseconds>(end - start).count();
	cout << elapsed << "millisec" << endl;
	cout << "�������͂��ďI��" << endl;
	string tmp;
	cin >> tmp;
	return 0;
}