/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndAppsFile.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndAppsFile.h"

CFrameWndAppsFileUI::CFrameWndAppsFileUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndAppsFileUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndAppsFile.xml"), (UINT)0));

	if (pFrameWndAppsFileUI)
	{
		this->Add(pFrameWndAppsFileUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}