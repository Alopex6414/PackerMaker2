/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndMoreInfo.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndMoreInfo.h"

CFrameWndMoreInfoUI::CFrameWndMoreInfoUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndMoreInfoUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndMoreInfo.xml"), (UINT)0));

	if (pFrameWndMoreInfoUI)
	{
		this->Add(pFrameWndMoreInfoUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}