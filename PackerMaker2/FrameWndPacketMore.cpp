/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndPacketMore.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "Common.h"
#include "FrameWndPacketMore.h"

// CFrameWndPacketMore ��ȡ��������
LPCTSTR CFrameWndPacketMore::GetWindowClassName() const
{
	return _T("FrameWndPacketMore");
}

// CFrameWndPacketMore ��ȡ��������
UINT CFrameWndPacketMore::GetClassStyle() const
{
	return CS_DBLCLKS;
}

// CFrameWndPacketMore ������Ϣ��Ӧ
void CFrameWndPacketMore::Notify(TNotifyUI & msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender == m_pCloseBtn)
		{
			OnLButtonClickedCloseBtn();
		}
		else if (msg.pSender == m_pPacketExportBtn)
		{
			OnLButtonClickedExportBtn();
		}
		else if (msg.pSender == m_pPacketOkBtn)
		{
			OnLButtonClickedOkBtn();
		}
		else if (msg.pSender == m_pPacketCancelBtn)
		{
			OnLButtonClickedCancel();
		}

	}

}

// CFrameWndPacketMore ��������Ϣ
LRESULT CFrameWndPacketMore::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT lRes = 0;
	BOOL bHandled = TRUE;

	switch (uMsg)
	{
	case WM_CREATE:
		lRes = OnCreate(uMsg, wParam, lParam, bHandled);
		break;
	case WM_LBUTTONDOWN:
		lRes = OnLButtonDown(uMsg, wParam, lParam, bHandled);
		break;
	default:
		bHandled = FALSE;
		break;
	}

	if (bHandled)
	{
		return lRes;
	}

	if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
	{
		return lRes;
	}

	return CWindowWnd::HandleMessage(uMsg, wParam, lParam);
}

// CFrameWndPacketMore ���캯��
void CFrameWndPacketMore::ConstructionExtra()
{
	
}

// CFrameWndPacketMore ��ʼ���ؼ�
void CFrameWndPacketMore::InitControls()
{
	m_pPacketFileType->SetText(m_csPacketFileType);
	m_pPacketFileName->SetText(m_csPacketFileName);
	m_pPacketFilePath->SetText(m_csPacketFilePath);
}

// CFrameWndPacketMore ���ڴ�����Ӧ����
LRESULT CFrameWndPacketMore::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	m_PaintManager.Init(m_hWnd);

	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create(_T("frame\\FrameWndPacketMore.xml"), (UINT)0, NULL, &m_PaintManager);
	ASSERT(pRoot && "Failed to parse XML");

	m_PaintManager.AttachDialog(pRoot);
	m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����

	InitControlsCaption();
	ConstructionExtra();

	m_pPacketFileType = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("PacketFileType")));
	m_pPacketFileName = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("PacketFileName")));
	m_pPacketFilePath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("PacketFilePath")));
	m_pPacketExportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketExportBtn")));
	m_pPacketOkBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketOkBtn")));
	m_pPacketCancelBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketCancelBtn")));

	InitControls();
	SetWindowInfo(480, 360);

	return 0;
}

// CFrameWndPacketMore ����������������Ӧ����
LRESULT CFrameWndPacketMore::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	MoveCaption(lParam, bHandled);
	return 0;
}

// CFrameWndPacketMore ���������������رմ���
void CFrameWndPacketMore::OnLButtonClickedCloseBtn()
{
	::PostMessageA(this->GetHWND(), WM_CLOSE, (WPARAM)0, (LPARAM)0);
}

// CFrameWndPacketMore ����������������������
void CFrameWndPacketMore::OnLButtonClickedExportBtn()
{
	CDuiString strType = _T("");
	CDuiString strName = _T("");

	USES_CONVERSION;

	strType = m_pPacketFileType->GetText();
	if (!strcmp(T2A(strType.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "���������ļ�����!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}
	else if(strType.Find('.') != -1)
	{
		MessageBoxA(this->GetHWND(), "����ļ������в��ܰ���'.'�ַ�!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	strName = m_pPacketFileName->GetText();
	if (!strcmp(T2A(strName.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ�����ļ�����!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	OPENFILENAME file;
	WCHAR strfile[MAX_PATH] = { 0 };
	char chType[MAX_PATH] = { 0 };
	char chFilter[MAX_PATH] = { 0 };
	char* pTemp = NULL;
	char* pStr = nullptr;
	int nSize = 0;

	strcpy_s(chType, T2A(strType.GetData()));
	sprintf_s(chFilter, "%s�ļ�*.%s", chType, chType);

	nSize = strlen(chFilter) + 3;
	pStr = new char[nSize];
	memset(pStr, 0, nSize);
	sprintf_s(pStr, nSize, "%s�ļ�", chType);

	for (pTemp = pStr; *pTemp != '\0'; ++pTemp);
	sprintf_s(++pTemp, nSize, "*.%s", chType);

	char chFileName[MAX_PATH] = { 0 };

	strcpy_s(chFileName, T2A(strName.GetData()));
	strcat_s(chFileName, ".");
	strcat_s(chFileName, T2A(strType.GetData()));
	wcscpy_s(strfile, A2T(chFileName));

	ZeroMemory(&file, sizeof(OPENFILENAME));

	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = A2T(pStr);
	file.nFilterIndex = 1;
	file.lpstrFile = strfile;
	file.nMaxFile = sizeof(strfile);
	file.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

	if (GetSaveFileName(&file))
	{
		m_pPacketFilePath->SetText(strfile);
	}

	delete[] pStr;
	pStr = nullptr;
}

// CFrameWndPacketMore ��������������ȷ������
void CFrameWndPacketMore::OnLButtonClickedOkBtn()
{
	m_csPacketFileType = m_pPacketFileType->GetText();
	m_csPacketFileName = m_pPacketFileName->GetText();
	m_csPacketFilePath = m_pPacketFilePath->GetText();
	Close(1);
}

// CFrameWndPacketMore ��������������ȡ������
void CFrameWndPacketMore::OnLButtonClickedCancel()
{
	Close(0);
}
