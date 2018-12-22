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
	virtual UINT GetClassStyle() const;
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

	// Sigle File
	CEditUI* m_pOriginFileType;
	CEditUI* m_pEnCryptFileType;
	CEditUI* m_pOriginFilePath;
	CEditUI* m_pEnCryptFilePath;
	CButtonUI* m_pEnCryptImportBtn;
	CButtonUI* m_pEnCryptExportBtn;
	CButtonUI* m_pEnCryptStartBtn;
	CTextUI* m_pEnCryptStatus;

	CEditUI* m_pDeCryptFilePath;
	CEditUI* m_pDestFilePath;
	CButtonUI* m_pDeCryptImportBtn;
	CButtonUI* m_pDeCryptExportBtn;
	CButtonUI* m_pDeCryptStartBtn;
	CTextUI* m_pDeCryptStatus;

	// Multiple File
	CButtonUI* m_pPacketAddBtn;
	CButtonUI* m_pPacketDelBtn;
	CButtonUI* m_pPacketMoreBtn;
	CListUI* m_pPacketList;
	CButtonUI* m_pPacketStartBtn;

	CEditUI* m_pUnpackPakPath;
	CEditUI* m_pDestPakPath;
	CButtonUI* m_pUnpackImportBtn;
	CButtonUI* m_pUnpackExportBtn;
	CButtonUI* m_pUnpackStartBtn;

public:
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnNcHitTest(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	void OnLButtonClickedMinBtn();
	void OnLButtonClickedMaxBtn();
	void OnLButtonClickedCloseBtn();

	void OnLButtonClickedEnCryptImportBtn();
	void OnLButtonClickedEnCryptExportBtn();
	void OnLButtonClickedEnCryptStartBtn();
	void OnLButtonClickedDeCryptImportBtn();
	void OnLButtonClickedDeCryptExportBtn();
	void OnLButtonClickedDeCryptStartBtn();

};

#endif // !__FRAMEWNDMAIN_H__
