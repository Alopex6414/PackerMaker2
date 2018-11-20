/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndMultipleFile.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndMultipleFile.h"

CFrameWndMultipleFileUI::CFrameWndMultipleFileUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndMultipleFileUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndMultipleFile.xml"), (UINT)0));

	if (pFrameWndMultipleFileUI)
	{
		this->Add(pFrameWndMultipleFileUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}