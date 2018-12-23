/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		FrameWndPacketMore.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __FRAMEWNDPACKETMORE_H_
#define __FRAMEWNDPACKETMORE_H_

// Include Frame Window Common Header File
#include "CommonWnd.h"
#include "FrameWndBase.h"

// Class Definition
class CFrameWndPacketMore : public CFrameWndBase
{
public:
	virtual LPCTSTR GetWindowClassName() const;
	virtual UINT GetClassStyle() const;
	virtual void Notify(TNotifyUI& msg);
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	CDuiString m_csPacketFileType;
	CDuiString m_csPacketFileName;
	CDuiString m_csPacketFilePath;

public:
	void ConstructionExtra();
	void InitControls();

	void SetPacketFileType(CDuiString csFileType) { m_csPacketFileType = csFileType; }
	void SetPacketFileName(CDuiString csFileName) { m_csPacketFileName = csFileName; }
	void SetPacketFilePath(CDuiString csFilePath) { m_csPacketFilePath = csFilePath; }
	CDuiString GetPacketFileType() { return m_csPacketFileType; }
	CDuiString GetPacketFileName() { return m_csPacketFileName; }
	CDuiString GetPacketFilePath() { return m_csPacketFilePath; }

public:
	CEditUI* m_pPacketFileType;
	CEditUI* m_pPacketFileName;
	CEditUI* m_pPacketFilePath;
	CButtonUI* m_pPacketExportBtn;
	CButtonUI* m_pPacketOkBtn;
	CButtonUI* m_pPacketCancelBtn;

public:
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

public:
	void OnLButtonClickedCloseBtn();
	void OnLButtonClickedExportBtn();
	void OnLButtonClickedOkBtn();
	void OnLButtonClickedCancel();

};

#endif // !__FRAMEWNDPACKETMORE_H_

