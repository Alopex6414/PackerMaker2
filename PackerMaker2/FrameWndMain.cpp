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

// CFrameWndMain 获取窗口类名
LPCTSTR CFrameWndMain::GetWindowClassName() const
{
	return _T("FrameWndMain");
}

// CFrameWndMain 窗口消息响应
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

}

// CFrameWndMain 处理窗口消息
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

// CFrameWndMain 窗口标题栏移动 
void CFrameWndMain::MoveCaption(LPARAM lParam, BOOL & bHandled)
{
	if (m_pCloseBtn == NULL || m_pMaxBtn == NULL || m_pMinBtn == NULL)
	{
		bHandled = FALSE;
	}

	POINT sPoint;
	sPoint.x = GET_X_LPARAM(lParam);
	sPoint.y = GET_Y_LPARAM(lParam);

	CControlUI* pNewHover = m_PaintManager.FindControl(sPoint); //判断是否位于关闭按钮

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

// CFrameWndMain 窗口创建响应函数 
LRESULT CFrameWndMain::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	m_PaintManager.Init(m_hWnd);

	CDialogBuilder builder;
	CControlUI* pRoot = builder.Create(_T("frame\\FrameWndMain.xml"), (UINT)0, NULL, &m_PaintManager);
	ASSERT(pRoot && "Failed to parse XML");

	m_PaintManager.AttachDialog(pRoot);
	m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理

	InitControlsCaption();

	m_pMaxBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("MaxBtn")));
	m_pMinBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("MinBtn")));

	SetWindowInfo(960, 720);

	return 0;
}

// CFrameWndMain 窗口鼠标左键单击响应函数
LRESULT CFrameWndMain::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	MoveCaption(lParam, bHandled);
	return 0;
}

// CFrameWndMain 窗口关闭响应函数
LRESULT CFrameWndMain::OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	bHandled = FALSE;
	return 0;
}

// CFrameWndMain 窗口鼠标左键单击最小化窗口
void CFrameWndMain::OnLButtonClickedMinBtn()
{
	::ShowWindow(this->GetHWND(), SW_SHOWMINIMIZED);
}

// CFrameWndMain 窗口鼠标左键单击最大化窗口
void CFrameWndMain::OnLButtonClickedMaxBtn()
{
}

// CFrameWndMain 窗口鼠标左键单击关闭窗口
void CFrameWndMain::OnLButtonClickedCloseBtn()
{
	::PostMessageA(this->GetHWND(), WM_CLOSE, (WPARAM)0, (LPARAM)0);
}
