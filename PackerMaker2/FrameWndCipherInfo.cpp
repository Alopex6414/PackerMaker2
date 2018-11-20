/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndCipherInfo.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndCipherInfo.h"

CFrameWndCipherInfoUI::CFrameWndCipherInfoUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndCipherInfoUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndCipherInfo.xml"), (UINT)0));

	if (pFrameWndCipherInfoUI)
	{
		this->Add(pFrameWndCipherInfoUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}