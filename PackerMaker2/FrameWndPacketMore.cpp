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
