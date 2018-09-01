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

// CFrameWndBase ��ȡ��������
LPCTSTR CFrameWndBase::GetWindowClassName() const
{
	return _T("FrameWndBase");
}

// CFrameWndBase �������ƶ�
void CFrameWndBase::MoveCaption(LPARAM lParam, BOOL & bHandled)
{
	if (m_pCloseBtn == NULL)
	{
		bHandled = FALSE;
	}

	POINT sPoint;
	sPoint.x = GET_X_LPARAM(lParam);
	sPoint.y = GET_Y_LPARAM(lParam);

	CControlUI* pNewHover = m_PaintManager.FindControl(sPoint); //�ж��Ƿ�λ�ڹرհ�ť

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

// CFrameWndBase ��ȡ���ڳߴ�
SIZE CFrameWndBase::GetWindowSize()
{
	return m_PaintManager.GetClientSize();
}

// CFrameWndBase ���ô��ڳߴ�
void CFrameWndBase::SetWindowSize(int nWidth, int nHeight)
{
	return m_PaintManager.SetInitSize(nWidth, nHeight);
}

// CFrameWndBase ���ô�����Ϣ
void CFrameWndBase::SetWindowInfo(int nWidth, int nHeight)
{
	m_nWidth = nWidth;
	m_nHeight = nHeight;
}

// CFrameWndBase ��ʼ���������ؼ�
void CFrameWndBase::InitControlsCaption()
{
	m_pCloseBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("CloseBtn")));
}
