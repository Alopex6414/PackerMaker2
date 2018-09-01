/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndBase.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "Common.h"

// CFrameWndBase 获取窗口类名
LPCTSTR CFrameWndBase::GetWindowClassName() const
{
	return _T("FrameWndBase");
}

// CFrameWndBase 标题栏移动
void CFrameWndBase::MoveCaption(LPARAM lParam, BOOL & bHandled)
{
	if (m_pCloseBtn == NULL)
	{
		bHandled = FALSE;
	}

	POINT sPoint;
	sPoint.x = GET_X_LPARAM(lParam);
	sPoint.y = GET_Y_LPARAM(lParam);

	CControlUI* pNewHover = m_PaintManager.FindControl(sPoint); //判断是否位于关闭按钮

	if (sPoint.x >= 0 && sPoint.x <= m_nWidth
		&& sPoint.y >= 0 && sPoint.y <= m_nCaptionSpace
		&& pNewHover != m_pCloseBtn)
	{
		::PostMessageA(this->GetHWND(), WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(sPoint.x, sPoint.y));
	}
	else
	{
		bHandled = FALSE;
	}
}

// CFrameWndBase 获取窗口尺寸
SIZE CFrameWndBase::GetWindowSize()
{
	return m_PaintManager.GetClientSize();
}

// CFrameWndBase 设置窗口尺寸
void CFrameWndBase::SetWindowSize(int nWidth, int nHeight)
{
	return m_PaintManager.SetInitSize(nWidth, nHeight);
}

// CFrameWndBase 设置窗口信息
void CFrameWndBase::SetWindowInfo(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}

// CFrameWndBase 初始化标题栏控件
void CFrameWndBase::InitControlsCaption()
{
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("CloseBtn")));
}
