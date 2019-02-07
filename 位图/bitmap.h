#ifndef _BITMAP__H_
#define _BITMAP__H_

#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "string.h"

typedef struct BitMap
{
	size_t* _bits;
	size_t _range;
}BitMap, *pBitMap;

void BitMapInit(BitMap* bm, size_t range);
void BitMapSet(BitMap* bm, size_t x);
void BitMapReset(BitMap* bm, size_t x);
int BitMapTest(BitMap* bm, size_t x);

#endif