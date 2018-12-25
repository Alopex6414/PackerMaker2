/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		UnpackThread.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "Common.h"

char* g_pUnPackSrcArr = NULL;
char* g_pUnPackDestArr = NULL;
int g_nUnPackSize = 0;
int g_nUnPackCount = 0;

// CUnpackThread 构造函数
CUnpackThread::CUnpackThread()
{
}

// CUnpackThread 析构函数
CUnpackThread::~CUnpackThread()
{
}

// CUnpackThread 线程运行
void CUnpackThread::PlumThreadRun()
{
	CPlumPack* pUnPacker = new CPlumPack;

	g_nUnPackSize = 0;
	g_nUnPackCount = 0;

	pUnPacker->PlumUnPackFilePackerA((const char*)g_pUnPackSrcArr, (const char*)g_pUnPackDestArr, &g_nUnPackSize, &g_nUnPackCount);

	free(g_pUnPackSrcArr);
	g_pUnPackSrcArr = NULL;
	free(g_pUnPackDestArr);
	g_pUnPackDestArr = NULL;

	delete pUnPacker;
}
