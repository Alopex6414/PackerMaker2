/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndSingleFile.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndSingleFile.h"

CFrameWndSingleFileUI::CFrameWndSingleFileUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndSingleFileUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndSingleFile.xml"), (UINT)0));

	if (pFrameWndSingleFileUI)
	{
		this->Add(pFrameWndSingleFileUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}