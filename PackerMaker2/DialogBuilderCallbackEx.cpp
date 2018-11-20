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
	if (_tcscmp(pstrClass, _T("FrameWndRealTimeStatus")) == 0)
	{
		return new CFrameWndRealTimeStatusUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndAlarmRecord")) == 0)
	{
		return new CFrameWndAlarmRecordUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndDeviceManagement")) == 0)
	{
		return new CFrameWndDeviceManagementUI();
	}

	if (_tcscmp(pstrClass, _T("FrameWndUserManagement")) == 0)
	{
		return new CFrameWndUserManagementUI();
	}

	return NULL;
}
