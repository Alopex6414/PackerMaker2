/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndMain.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __FRAMEWNDMAIN_H__
#define __FRAMEWNDMAIN_H__

// Include Frame Window Common Header File
#include "CommonWnd.h"
#include "FrameWndBase.h"

// Class Definition
class CFrameWndMain : public CFrameWndBase
{
public:
	virtual LPCTSTR GetWindowClassName() const;
	virtual void Notify(TNotifyUI& msg);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

protected:
	virtual void MoveCaption(LPARAM lParam, BOOL& bHandled);

private:


public:
	CButtonUI* m_pMaxBtn;
	CButtonUI* m_pMinBtn;

	COptionUI* m_pSingleFileBtn;
	COptionUI* m_pMultiFileBtn;
	COptionUI* m_pTextFileBtn;
	COptionUI* m_pAppFileBtn;

	COptionUI* m_pCipherBtn;
	COptionUI* m_pCipherInfoBtn;
	COptionUI* m_pMoreInfoBtn;

	COptionUI* m_pAboutInfoBtn;

public:
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	void OnLButtonClickedMinBtn();
	void OnLButtonClickedMaxBtn();
	void OnLButtonClickedCloseBtn();

};

#endif // !__FRAMEWNDMAIN_H__
