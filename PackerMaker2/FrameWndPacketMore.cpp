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

// CFrameWndPacketMore 获取窗口类名
LPCTSTR CFrameWndPacketMore::GetWindowClassName() const
{
	return _T("FrameWndPacketMore");
}

// CFrameWndPacketMore 获取窗口类型
UINT CFrameWndPacketMore::GetClassStyle() const
{
	return CS_DBLCLKS;
}

// CFrameWndPacketMore 窗口消息响应
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

// CFrameWndPacketMore 处理窗口消息
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

// CFrameWndPacketMore 构造函数
void CFrameWndPacketMore::ConstructionExtra()
{
	
}

// CFrameWndPacketMore 初始化控件
void CFrameWndPacketMore::InitControls()
{
	m_pPacketFileType->SetText(m_csPacketFileType);
	m_pPacketFileName->SetText(m_csPacketFileName);
	m_pPacketFilePath->SetText(m_csPacketFilePath);
}

// CFrameWndPacketMore 窗口创建响应函数
LRESULT CFrameWndPacketMore::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	m_PaintManager.Init(m_hWnd);

	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create(_T("frame\\FrameWndPacketMore.xml"), (UINT)0, NULL, &m_PaintManager);
	ASSERT(pRoot && "Failed to parse XML");

	m_PaintManager.AttachDialog(pRoot);
	m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理

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

// CFrameWndPacketMore 窗口鼠标左键单击响应函数
LRESULT CFrameWndPacketMore::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	MoveCaption(lParam, bHandled);
	return 0;
}

// CFrameWndPacketMore 窗口鼠标左键单击关闭窗口
void CFrameWndPacketMore::OnLButtonClickedCloseBtn()
{
	::PostMessageA(this->GetHWND(), WM_CLOSE, (WPARAM)0, (LPARAM)0);
}

// CFrameWndPacketMore 窗口鼠标左键单击导出窗口
void CFrameWndPacketMore::OnLButtonClickedExportBtn()
{
	CDuiString strType = _T("");
	CDuiString strName = _T("");

	USES_CONVERSION;

	strType = m_pPacketFileType->GetText();
	if (!strcmp(T2A(strType.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "请输入封包文件类型!", "提示", MB_OK | MB_ICONASTERISK);
		return;
	}
	else if(strType.Find('.') != -1)
	{
		MessageBoxA(this->GetHWND(), "封包文件类型中不能包含'.'字符!", "提示", MB_OK | MB_ICONASTERISK);
		return;
	}

	strName = m_pPacketFileName->GetText();
	if (!strcmp(T2A(strName.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "请选择封包文件名称!", "提示", MB_OK | MB_ICONASTERISK);
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
	sprintf_s(chFilter, "%s文件*.%s", chType, chType);

	nSize = strlen(chFilter) + 3;
	pStr = new char[nSize];
	memset(pStr, 0, nSize);
	sprintf_s(pStr, nSize, "%s文件", chType);

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

// CFrameWndPacketMore 窗口鼠标左键单击确定窗口
void CFrameWndPacketMore::OnLButtonClickedOkBtn()
{
	m_csPacketFileType = m_pPacketFileType->GetText();
	m_csPacketFileName = m_pPacketFileName->GetText();
	m_csPacketFilePath = m_pPacketFilePath->GetText();
	Close(1);
}

// CFrameWndPacketMore 窗口鼠标左键单击取消窗口
void CFrameWndPacketMore::OnLButtonClickedCancel()
{
	Close(0);
}
