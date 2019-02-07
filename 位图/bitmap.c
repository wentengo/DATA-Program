//1.����100�ڸ�����������㷨�ҵ�ֻ����һ�ε�����
//2.�������ļ����ֱ���100�ڸ�����������ֻ��1G�ڴ棬����ҵ������ļ�����
//3.1���ļ���100�ڸ�int��1G�ڴ棬����㷨�ҵ����ִ���������2�ε���������
//�⣺1.�Ƚ�100�ڸ������и100���ļ��У�ÿ���ļ����ù�ϣ��洢���ҳ�ÿ���ļ���ֻ����һ�ε��������ٺϲ�����ҳ�ֻ����һ�ε�������
//2.������һ�����Ƚ������ļ���������ͬ��ɢ�к������и�Ϊ100�ݣ����ҽ������ļ����и��ļ���һ���Ĺ��ɱ�ţ��ٽ���ͬ��ŵ��ļ����кϲ��ҳ�����������ҳ��Ľ������кϲ����ҵ����еĽ�����
//3.������bit��ʾ״̬��00,��ʾδ���ֹ���01��ʾ���ֹ�һ�Σ�11��ʾ���ֶ�Σ�����λͼ���д洢��
#include "bitmap.h"

void BitMapInit(pBitMap bm, size_t range)
{
	assert(bm);
	bm->_bits = (size_t*)malloc(sizeof(size_t)*range);
	memset(bm->_bits, 0, sizeof(size_t)*range);
	bm->_range = range;
}

void BitMapSet(pBitMap bm, size_t x)
{
	assert(bm);
	size_t index = x >> 3;
	size_t cur = x % 8;
	bm->_bits[index] |= 1 << cur;
}

void BitMapReset(pBitMap bm, size_t x)
{
	assert(bm);
	size_t index = x >> 3;
	size_t cur = x % 8;
	bm->_bits[index] &= ~(1 << cur);
}

int BitMapTest(pBitMap bm, size_t x)
{
	assert(bm);
	size_t index = x >> 3;
	size_t cur = x % 8;
	return ((bm->_bits[index]) & (1 << cur)) == 0 ? 0 : 1;
}