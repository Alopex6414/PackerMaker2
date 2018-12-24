/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		PacketThread.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "Common.h"

char** g_ppSrcArr = NULL;
char* g_pDestArr = NULL;
int g_nSrcSize = 0;

int g_nPackerCount = 0;
int g_nPackerCheck = 0;

DWORD g_dwLuckyArr[4] = 
{ 
	0x00000000,
	0x00000000,
	0x00000000,
	0x00000000
};

// CPacketThread 构造函数
CPacketThread::CPacketThread()
{
}

// CPacketThread 析构函数
CPacketThread::~CPacketThread()
{
}

// CPacketThread 线程运行
void CPacketThread::PlumThreadRun()
{
	CPlumPack* pPacker = new CPlumPack;

	g_nPackerCount = 0;

	if (g_nPackerCheck == 0)
	{
		pPacker->PlumPackFilePackerA((const char**)g_ppSrcArr, g_nSrcSize, (const char*)g_pDestArr, g_dwLuckyArr, &g_nPackerCount);
	}
	else if (g_nPackerCheck == 1)
	{
		pPacker->PlumPackFilePackerA((const char**)g_ppSrcArr, g_nSrcSize, (const char*)g_pDestArr, &g_nPackerCount);
	}

	free(g_pDestArr);
	g_pDestArr = NULL;

	for (int i = 0; i < g_nSrcSize; ++i)
	{
		free(*(g_ppSrcArr + i));
		*(g_ppSrcArr + i) = NULL;
	}

	free(g_ppSrcArr);
	g_ppSrcArr = NULL;

	g_nSrcSize = 0;

	delete pPacker;
}
