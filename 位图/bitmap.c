//1.给定100亿个整数，设计算法找到只出现一次的整数
//2.给两个文件，分别有100亿个整数，我们只有1G内存，如何找到两个文件交集
//3.1个文件有100亿个int，1G内存，设计算法找到出现次数不超过2次的所有整数
//解：1.先将100亿个整数切割到100个文件中，每个文件利用哈希表存储，找出每个文件中只出现一次的整数，再合并最后找出只出现一次的整数。
//2.和上题一样，先将两个文件都利用相同的散列函数各切割为100份，并且将两个文件的切割文件按一样的规律编号，再将相同编号的文件进行合并找出交集，最后将找出的交集进行合并就找到所有的交集。
//3.用俩个bit表示状态，00,表示未出现过，01表示出现过一次，11表示出现多次，利用位图进行存储。
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