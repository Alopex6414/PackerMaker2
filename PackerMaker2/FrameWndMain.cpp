/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndMain.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "Common.h"
#include "FrameWndMain.h"

// CFrameWndMain ��ȡ��������
LPCTSTR CFrameWndMain::GetWindowClassName() const
{
	return _T("FrameWndMain");
}

// CFrameWndMain ������Ϣ��Ӧ
void CFrameWndMain::Notify(TNotifyUI & msg)
{
	if (msg.sType == _T("click"))
	{
		if (msg.pSender == m_pCloseBtn)
		{
			OnLButtonClickedCloseBtn();
		}
		else if (msg.pSender == m_pMaxBtn)
		{
			OnLButtonClickedMaxBtn();
		}
		else if (msg.pSender == m_pMinBtn)
		{
			OnLButtonClickedMinBtn();
		}
		
	}
	else if (msg.sType == _T("selectchanged"))
	{
		CTabLayoutUI* pControl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("FrameMainMenu")));
		if (msg.pSender == m_pSingleFileBtn)
		{
			pControl->SelectItem(0);
		}
		else if (msg.pSender == m_pMultiFileBtn)
		{
			pControl->SelectItem(1);
		}
		else if (msg.pSender == m_pTextFileBtn)
		{
			pControl->SelectItem(2);
		}
		else if (msg.pSender == m_pAppFileBtn)
		{
			pControl->SelectItem(3);
		}
		else if (msg.pSender == m_pCipherBtn)
		{
			pControl->SelectItem(4);
		}
		else if (msg.pSender == m_pCipherInfoBtn)
		{
			pControl->SelectItem(5);
		}
		else if (msg.pSender == m_pMoreInfoBtn)
		{
			pControl->SelectItem(6);
		}
		else if (msg.pSender == m_pAboutInfoBtn)
		{
			pControl->SelectItem(7);
		}

	}

}

// CFrameWndMain ��������Ϣ
LRESULT CFrameWndMain::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
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
	case WM_CLOSE:
		lRes = OnClose(uMsg, wParam, lParam, bHandled);
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

// CFrameWndMain ���ڱ������ƶ� 
void CFrameWndMain::MoveCaption(LPARAM lParam, BOOL & bHandled)
{
	if (m_pCloseBtn == NULL || m_pMaxBtn == NULL || m_pMinBtn == NULL)
	{
		bHandled = FALSE;
	}

	POINT sPoint;
	sPoint.x = GET_X_LPARAM(lParam);
	sPoint.y = GET_Y_LPARAM(lParam);

	CControlUI* pNewHover = m_PaintManager.FindControl(sPoint); //�ж��Ƿ�λ�ڹرհ�ť

	if (sPoint.x >= 0 && sPoint.x <= m_nWidth
		&& sPoint.y >= 0 && sPoint.y <= m_nCaptionSpace
		&& pNewHover != m_pCloseBtn
		&& pNewHover != m_pMaxBtn
		&& pNewHover != m_pMinBtn)
	{
		::PostMessageA(this->GetHWND(), WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(sPoint.x, sPoint.y));
	}
	else
	{
		bHandled = FALSE;
	}
}

// CFrameWndMain ���ڴ�����Ӧ���� 
LRESULT CFrameWndMain::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	m_PaintManager.Init(m_hWnd);

	CDialogBuilder builder;
	CDialogBuilderCallbackEx cb;
	CControlUI* pRoot = builder.Create(_T("frame\\FrameWndMain.xml"), (UINT)0, &cb, &m_PaintManager);
	ASSERT(pRoot && "Failed to parse XML");

	m_PaintManager.AttachDialog(pRoot);
	m_PaintManager.AddNotifier(this);   // ��ӿؼ�����Ϣ��Ӧ��������Ϣ�ͻᴫ�ﵽduilib����Ϣѭ�������ǿ�����Notify����������Ϣ����

	InitControlsCaption();

	m_pMaxBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("MaxBtn")));
	m_pMinBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("MinBtn")));

	m_pSingleFileBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("SigleFileBtn")));
	m_pMultiFileBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("MutiFileBtn")));
	m_pTextFileBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("TextFileBtn")));
	m_pAppFileBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("AppFileBtn")));

	m_pCipherBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("CipherBtn")));
	m_pCipherInfoBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("CipherInfoBtn")));
	m_pMoreInfoBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("MoreSetBtn")));

	m_pAboutInfoBtn = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("AboutInfoBtn")));

	SetWindowInfo(960, 720);

	return 0;
}

// CFrameWndMain ����������������Ӧ����
LRESULT CFrameWndMain::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	MoveCaption(lParam, bHandled);
	return 0;
}

// CFrameWndMain ���ڹر���Ӧ����
LRESULT CFrameWndMain::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	bHandled = FALSE;
	return 0;
}

// CFrameWndMain ����������������С������
void CFrameWndMain::OnLButtonClickedMinBtn()
{
	::ShowWindow(this->GetHWND(), SW_SHOWMINIMIZED);
}

// CFrameWndMain ����������������󻯴���
void CFrameWndMain::OnLButtonClickedMaxBtn()
{
}

// CFrameWndMain ���������������رմ���
void CFrameWndMain::OnLButtonClickedCloseBtn()
{
	::PostMessageA(this->GetHWND(), WM_CLOSE, (WPARAM)0, (LPARAM)0);
}
