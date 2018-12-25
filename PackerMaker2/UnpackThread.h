/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		UnpackThread.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __UNPACKTHREAD_H_
#define __UNPACKTHREAD_H_

#include "PlumThread.h"

// Class Definition
class CUnpackThread : public CPlumThreadBase
{
public:
	CUnpackThread();
	~CUnpackThread();
	virtual void WINAPI PlumThreadRun();
};

extern char* g_pUnPackSrcArr;
extern char* g_pUnPackDestArr;
extern int g_nUnPackSize;
extern int g_nUnPackCount;

#endif // !__UNPACKTHREAD_H_

