/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndTextFile.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "FrameWndTextFile.h"

CFrameWndTextFileUI::CFrameWndTextFileUI()
{
	CDialogBuilder builder;
	CContainerUI* pFrameWndTextFileUI = static_cast<CContainerUI*>(builder.Create(_T("frame\\FrameWndTextFile.xml"), (UINT)0));

	if (pFrameWndTextFileUI)
	{
		this->Add(pFrameWndTextFileUI);
	}
	else
	{
		this->RemoveAll();
		return;
	}

}