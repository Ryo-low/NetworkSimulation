#pragma once
#include "../Common.h"
#include <random>
#define  FIRST_NODE_NUM		4		// �����m�[�h��
#define  SCALE_MIN			0.0		// �X�P�[���ŏ��l


class RGNmake {
public:
	// function
	RGNmake();
	~RGNmake();
	// ��񐶐��֐�
	void create(unsigned int nodeNum, unsigned int averageLinkNum, double scale = PAJEK_MATCH_SCALE);

	/*set-get*/
	// �m�[�h���擾
	unsigned int	get_nodeNum();
	// ���σ����N���擾
	unsigned int	get_averageLinkNum();
	// �m�[�h��񃊃X�g�擾
	NodeList		get_nodeList();
	// �����N��񃊃X�g�擾
	LinkList		get_linkList();

private:
	// function
	// �l�b�g���[�N�쐬
	void make_network();
	// �����N�\�����`�F�b�N
	bool check_linkRange(const NODE_DATA& baseNode, const NODE_DATA& destNode);
	// �w��m�[�h�Ƃ̃����N�𐶐�
	void add_link(unsigned int baseNode, unsigned int destNode);

	// variable
	unsigned int			_nodeNum;				// �m�[�h��
	unsigned int			_averageLinkNum;		// ���σ����N��
	double					_scale;					// �l�b�g���[�N�̃X�P�[��
	double					_communicationRange;	// �ʐM�\����
	NodeList				_nodeList;				// �m�[�h��񃊃X�g
	LinkList				_linkList;				// �����N��񃊃X�g
};

/*set-get*/
inline unsigned int RGNmake::get_nodeNum()
{
	return _nodeNum;
}

inline unsigned int RGNmake::get_averageLinkNum()
{
	return _averageLinkNum;
}

inline NodeList RGNmake::get_nodeList()
{
	return _nodeList;
}

inline LinkList RGNmake::get_linkList()
{
	return _linkList;
}
