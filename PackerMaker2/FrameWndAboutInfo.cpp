/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndAboutInfo.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndAboutInfo.h"

CFrameWndAboutInfoUI::CFrameWndAboutInfoUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndAboutInfoUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndAboutInfo.xml"), (UINT)0));

	if (pFrameWndAboutInfoUI)
	{
		this->Add(pFrameWndAboutInfoUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}