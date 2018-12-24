/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		PacketThread.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __PACKETTHREAD_H_
#define __PACKETTHREAD_H_

#include "PlumThread.h"

// Class Definition
class CPacketThread : public CPlumThreadBase
{
public:
	CPacketThread();
	~CPacketThread();
	virtual void WINAPI PlumThreadRun();
};

extern char** g_ppSrcArr;
extern char* g_pDestArr;
extern int g_nSrcSize;
extern DWORD g_dwLuckyArr[4];

extern int g_nPackerCount;
extern int g_nPackerCheck;

#endif // !__PACKETTHREAD_H_

