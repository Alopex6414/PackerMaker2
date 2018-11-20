/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		DialogBuilderCallbackEx.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-11-20
*/
#include "DialogBuilderCallbackEx.h"

CControlUI * CDialogBuilderCallbackEx::CreateControl(LPCTSTR pstrClass)
{
	if (_tcscmp(pstrClass, _T("FrameWndSigleFile")) == 0)
	{
		return new CFrameWndSingleFileUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndMultiFile")) == 0)
	{
		return new CFrameWndMultipleFileUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndTextFile")) == 0)
	{
		return new CFrameWndTextFileUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndAppsFile")) == 0)
	{
		return new CFrameWndAppsFileUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndCipherConfig")) == 0)
	{
		return new CFrameWndCipherConfigUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndCipherInfo")) == 0)
	{
		return new CFrameWndCipherInfoUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndMoreInfo")) == 0)
	{
		return new CFrameWndMoreInfoUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndAboutInfo")) == 0)
	{
		return new CFrameWndAboutInfoUI();
	}

	return NULL;
}
