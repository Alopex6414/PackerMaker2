/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		CommonType.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __COMMONTYPE_H_
#define __COMMONTYPE_H_

#include "Common.h"

// ∑‚∞¸¿‡–Õ
typedef struct
{
	int nSerial;
	char chFileName[MAX_PATH];
	char chFilePath[MAX_PATH];
}S_PACKETTYPE, *LPS_PACKETTYPE;

#endif // !__COMMONTYPE_H_

