/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndCipherConfig.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndCipherConfig.h"

CFrameWndCipherConfigUI::CFrameWndCipherConfigUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndCipherConfigUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndCipherConfig.xml"), (UINT)0));

	if (pFrameWndCipherConfigUI)
	{
		this->Add(pFrameWndCipherConfigUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}