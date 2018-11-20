/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DialogBuilderCallbackEx.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-11-20
*/
#pragma once

#ifndef __DIALOGBUILDERCALLBACKEX_H_
#define __DIALOGBUILDERCALLBACKEX_H_

// Include Common Header File
#include "Common.h"

// Class Definition
class CDialogBuilderCallbackEx : public IDialogBuilderCallback
{
private:

public:
	CControlUI * CreateControl(LPCTSTR pstrClass);

};

#endif // !__DIALOGBUILDERCALLBACKEX_H_
