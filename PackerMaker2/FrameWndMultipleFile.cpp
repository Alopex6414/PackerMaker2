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

CFrameWndMultipleFileListUI g_cCFrameWndMultipleFileListUI;

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

LPCTSTR CFrameWndMultipleFileListUI::GetItemText(CControlUI * pControl, int iIndex, int iSubItem)
{
	TCHAR szBuf[MAX_PATH] = { 0 };

	switch (iSubItem)
	{
		case 0:
		{
			_stprintf_s(szBuf, _T("%d"), g_pCFrameWndMain->m_vecPacket[iIndex].nSerial);
		}
		break;
		case 1:
		{
			int iLen = sizeof(g_pCFrameWndMain->m_vecPacket[iIndex].chFileName);
			LPWSTR lpText = new WCHAR[iLen + 1];
			::ZeroMemory(lpText, (iLen + 1) * sizeof(WCHAR));
			::MultiByteToWideChar(CP_ACP, 0, g_pCFrameWndMain->m_vecPacket[iIndex].chFileName, -1, (LPWSTR)lpText, iLen);
			_stprintf_s(szBuf, lpText);
			delete[] lpText;
		}
		break;
		case 2:
		{
			// IPµØÖ·
			int iLen = sizeof(g_pCFrameWndMain->m_vecPacket[iIndex].chFilePath);
			LPWSTR lpText = new WCHAR[iLen + 1];
			::ZeroMemory(lpText, (iLen + 1) * sizeof(WCHAR));
			::MultiByteToWideChar(CP_ACP, 0, g_pCFrameWndMain->m_vecPacket[iIndex].chFilePath, -1, (LPWSTR)lpText, iLen);
			_stprintf_s(szBuf, lpText);
			delete[] lpText;
		}
		break;
	}

	pControl->SetUserData(szBuf);
	return pControl->GetUserData();
}
