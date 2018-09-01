/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndBase.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __FRAMEWNDBASE_H__
#define __FRAMEWNDBASE_H__

// Include Frame Window Common Header File
#include "CommonWnd.h"

// Class Definition
class CFrameWndBase : public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const;

protected:
	void MoveCaption(LPARAM lParam, BOOL& bHandled);

protected:
	CPaintManagerUI m_PaintManager;

protected:
	int m_nWidth;
	int m_nHeight;

public:
	static const int m_nCaptionSpace = 28;

public:
	SIZE GetWindowSize();
	void SetWindowSize(int nWidth, int nHeight);
	void SetWindowInfo(int nWidth, int nHeight);

public:
	CButtonUI* m_pCloseBtn;

public:
	void InitControlsCaption();

};

#endif // !__FRAMEWNDBASE_H__

