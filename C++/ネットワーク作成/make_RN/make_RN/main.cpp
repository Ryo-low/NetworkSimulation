#include "main.h"

int main(int argc, char* args[])
{
	unsigned int nodeNum			= INT_ZERO;
	unsigned int averageLinkNum		= INT_ZERO;
	if( argc == NEED_ARGS_NUM ){
		nodeNum			= (unsigned int)args[ARGS_NODE_NUM];
		averageLinkNum	= (unsigned int)args[ARGS_AVERAGE_LINK_NUM];
	}
	else{
		cout << "�����s���ɂ��Θb���[�h" << endl;
		cout << "�m�[�h���w��" << endl;
		cin >> nodeNum;

		cout << "���σ����N���w��" << endl;
		cin >> averageLinkNum;
	}

	RNmake* rnMake = new RNmake();

}