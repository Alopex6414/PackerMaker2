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

// CFrameWndMain 获取窗口类型
UINT CFrameWndMain::GetClassStyle() const
{
	return CS_DBLCLKS;
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
	case WM_NCACTIVATE:
		lRes = OnNcActivate(uMsg, wParam, lParam, bHandled);
		break;
	case WM_NCCALCSIZE:
		lRes = OnNcCalcSize(uMsg, wParam, lParam, bHandled);
		break;
	case WM_NCPAINT:
		lRes = OnNcPaint(uMsg, wParam, lParam, bHandled);
		break;
	case WM_NCHITTEST:
		lRes = OnNcHitTest(uMsg, wParam, lParam, bHandled);
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

	RECT Rect;
	GetWindowRect(this->GetHWND(), &Rect);

	CControlUI* pNewHover = m_PaintManager.FindControl(sPoint); //判断是否位于关闭按钮

	if (sPoint.x >= 0 && sPoint.x <= (Rect.right - Rect.left)
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
	CDialogBuilderCallbackEx cb;
	CControlUI* pRoot = builder.Create(_T("frame\\FrameWndMain.xml"), (UINT)0, &cb, &m_PaintManager);
	ASSERT(pRoot && "Failed to parse XML");

	m_PaintManager.AttachDialog(pRoot);
	m_PaintManager.AddNotifier(this);   // 添加控件等消息响应，这样消息就会传达到duilib的消息循环，我们可以在Notify函数里做消息处理

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

// CFrameWndMain 窗口活动响应
LRESULT CFrameWndMain::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	if (::IsIconic(*this)) 
	{
		bHandled = FALSE;
	}
	return (wParam == 0) ? TRUE : FALSE;
}

// CFrameWndMain 窗口计算大小响应
LRESULT CFrameWndMain::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	return 0;
}

// CFrameWndMain 窗口绘制响应
LRESULT CFrameWndMain::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	return 0;
}

// CFrameWndMain 窗口点击响应
LRESULT CFrameWndMain::OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	POINT pt; 
	pt.x = GET_X_LPARAM(lParam); 
	pt.y = GET_Y_LPARAM(lParam);
	::ScreenToClient(*this, &pt);

	RECT rcClient;
	::GetClientRect(*this, &rcClient);

	RECT rcCaption = m_PaintManager.GetCaptionRect();
	if (pt.x >= rcClient.left + rcCaption.left && pt.x < rcClient.right - rcCaption.right && pt.y >= rcCaption.top && pt.y < rcCaption.bottom) 
	{
		CControlUI* pControl = static_cast<CControlUI*>(m_PaintManager.FindControl(pt));
		if (pControl && _tcscmp(pControl->GetClass(), DUI_CTR_BUTTON) != 0 && _tcscmp(pControl->GetClass(), DUI_CTR_OPTION) != 0 && _tcscmp(pControl->GetClass(), DUI_CTR_TEXT) != 0)
		{
			return HTCAPTION;
		}
			
	}

	return HTCLIENT;
}

// CFrameWndMain 窗口鼠标左键单击最小化窗口
void CFrameWndMain::OnLButtonClickedMinBtn()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}

// CFrameWndMain 窗口鼠标左键单击最大化窗口
void CFrameWndMain::OnLButtonClickedMaxBtn()
{
	//SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
}

// CFrameWndMain 窗口鼠标左键单击关闭窗口
void CFrameWndMain::OnLButtonClickedCloseBtn()
{
	::PostMessageA(this->GetHWND(), WM_CLOSE, (WPARAM)0, (LPARAM)0);
}
