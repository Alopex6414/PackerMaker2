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

//Macro Definition
#define FRAMEMAIN_LIST_REFRESH_SLEEPTIME	1
#define FRAMEMAIN_PROGRESS_REFRESH_TIME		100

#define FRAMEMAIN_TIMER_PROGRESS_PACKET_REFRESH		0
#define FRAMEMAIN_TIMER_PROGRESS_UNPACK_REFRESH		1

#define WM_USER_MSG_ADDITEM_SEEKPACKET	(WM_USER + 1)
#define WM_USER_MSG_ADDITEM_PACKETLIST	(WM_USER + 2)

// Variable Definition
CFrameWndMain* g_pCFrameWndMain;

// CFrameWndMain ��ȡ��������
LPCTSTR CFrameWndMain::GetWindowClassName() const
{
	return _T("FrameWndMain");
}

// CFrameWndMain ��ȡ��������
UINT CFrameWndMain::GetClassStyle() const
{
	return CS_DBLCLKS;
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
		else if (msg.pSender == m_pEnCryptImportBtn)
		{
			OnLButtonClickedEnCryptImportBtn();
		}
		else if (msg.pSender == m_pEnCryptExportBtn)
		{
			OnLButtonClickedEnCryptExportBtn();
		}
		else if (msg.pSender == m_pEnCryptStartBtn)
		{
			OnLButtonClickedEnCryptStartBtn();
		}
		else if (msg.pSender == m_pDeCryptImportBtn)
		{
			OnLButtonClickedDeCryptImportBtn();
		}
		else if (msg.pSender == m_pDeCryptExportBtn)
		{
			OnLButtonClickedDeCryptExportBtn();
		}
		else if (msg.pSender == m_pDeCryptStartBtn)
		{
			OnLButtonClickedDeCryptStartBtn();
		}
		else if (msg.pSender == m_pPacketAddBtn)
		{
			OnLButtonClickedPacketAddBtn();
		}
		else if (msg.pSender == m_pPacketDelBtn)
		{
			OnLButtonClickedPacketDelBtn();
		}
		else if (msg.pSender == m_pPacketMoreBtn)
		{
			OnLButtonClickedPacketMoreBtn();
		}
		else if (msg.pSender == m_pPacketStartBtn)
		{
			OnLButtonClickedPacketStartBtn();
		}
		else if (msg.pSender == m_pUnpackImportBtn)
		{
			OnLButtonClickedUnpackImportBtn();
		}
		else if (msg.pSender == m_pUnpackExportBtn)
		{
			OnLButtonClickedUnpackExportBtn();
		}
		else if (msg.pSender == m_pUnpackStartBtn)
		{
			OnLButtonClickedUnpackStartBtn();
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
	case WM_TIMER:
		lRes = OnTimer(uMsg, wParam, lParam, bHandled);
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
	case WM_USER_MSG_ADDITEM_SEEKPACKET:
		lRes = OnAddPacketSeekList(uMsg, wParam, lParam, bHandled);
		break;
	case WM_USER_MSG_ADDITEM_PACKETLIST:
		lRes = OnAddPacketListItem(uMsg, wParam, lParam, bHandled);
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

	RECT Rect;
	GetWindowRect(this->GetHWND(), &Rect);

	CControlUI* pNewHover = m_PaintManager.FindControl(sPoint); //�ж��Ƿ�λ�ڹرհ�ť

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

// CFrameWndMain ���ڹ��캯��
void CFrameWndMain::ConstructionExtra()
{
	g_pCFrameWndMain = this;

	m_vecPacket.clear();

	m_pPlumPackerThread = NULL;

	m_csPacketFileType = _T("pak");
	m_csPacketFileName = _T("MyPacket");
	m_csPacketFilePath = _T("C:\\MyPacket.pak");
}

// CFrameWndMain ��ѯ����ļ���Ϣ
void CFrameWndMain::SeekPacketFileInfo()
{
	HANDLE hThread = NULL;
	DWORD dwThreadID = 0;

	m_pPacketList->RemoveAll();
	m_pPacketList->SetTextCallback(&g_cCFrameWndMultipleFileListUI);
	hThread = ::CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SeekPacketFileInfoShowListCallBack, NULL, 0, &dwThreadID);
	::CloseHandle(hThread);
}

// CFrameWndMain ��ѯ����ļ���Ϣ��ʾ���б��߳�
DWORD CFrameWndMain::SeekPacketFileInfoShowListCallBack(LPVOID lpParameter)
{
	CListUI* pList = g_pCFrameWndMain->m_pPacketList;

	for (int i = 0; i < g_pCFrameWndMain->m_vecPacket.size(); ++i)
	{
		CListTextElementUI* pListElement = new CListTextElementUI();

		pListElement->SetTag(i);
		if (pListElement != NULL)
		{
			::PostMessageA(g_pCFrameWndMain->GetHWND(), WM_USER_MSG_ADDITEM_PACKETLIST, 0L, (LPARAM)pListElement);
		}

		Sleep(FRAMEMAIN_LIST_REFRESH_SLEEPTIME);
	}

	return 0;
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

	ConstructionExtra();
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

	// Sigle File
	m_pOriginFileType = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("OriginFileType")));
	m_pEnCryptFileType = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("EnCryptFileType")));
	m_pOriginFilePath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("OriginFilePath")));
	m_pEnCryptFilePath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("EnCryptFilePath")));
	m_pEnCryptImportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("EnCryptImportBtn")));
	m_pEnCryptExportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("EnCryptExportBtn")));
	m_pEnCryptStartBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("EnCryptStartBtn")));
	m_pEnCryptStatus = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("EnCryptStatus")));

	m_pDeCryptFilePath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("DeCryptFilePath")));
	m_pDestFilePath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("DestFilePath")));
	m_pDeCryptImportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("DeCryptImportBtn")));
	m_pDeCryptExportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("DeCryptExportBtn")));
	m_pDeCryptStartBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("DeCryptStartBtn")));
	m_pDeCryptStatus = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("DeCryptStatus")));

	// Multiple File
	m_pPacketAddBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketAddBtn")));
	m_pPacketDelBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketDelBtn")));
	m_pPacketMoreBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketMoreBtn")));
	m_pPacketList = static_cast<CListUI*>(m_PaintManager.FindControl(_T("PacketList")));
	m_pPacketProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("PacketProgress")));
	m_pPacketStatus = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("PacketStatus")));
	m_pPacketStartBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("PacketStartBtn")));

	m_pUnpackPakPath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("UnpackPakPath")));
	m_pDestPakPath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("DestPakPath")));
	m_pUnpackImportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("UnpackImportBtn")));
	m_pUnpackExportBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("UnpackExportBtn")));
	m_pUnpackProgress = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("UnpackProgress")));
	m_pUnpackStatus = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("UnpackStatus")));
	m_pUnpackStartBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("UnpackStartBtn")));

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

	if (m_pPlumPackerThread)
	{
		m_pPlumPackerThread->PlumThreadExit();
		delete m_pPlumPackerThread;
		m_pPlumPackerThread = NULL;
	}

	return 0;
}

// CFrameWndMain ���ڶ�ʱ����Ӧ����
LRESULT CFrameWndMain::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	DWORD nID = wParam;

	switch (nID)
	{
	case FRAMEMAIN_TIMER_PROGRESS_PACKET_REFRESH:
		{
			CDuiString csConvCount = _T("");
			CDuiString csAllCount = _T("");

			csConvCount.Format(_T("%d"), g_nPackerCount);
			csAllCount.Format(_T("%d"), m_vecPacket.size());

			m_pPacketProgress->SetValue(g_nPackerCount);
			m_pPacketStatus->SetText(csConvCount + _T("/") + csAllCount);
			if (g_nPackerCount == m_vecPacket.size())
			{
				m_pPacketStatus->SetText(_T("Finish!"));
				::KillTimer(this->GetHWND(), FRAMEMAIN_TIMER_PROGRESS_PACKET_REFRESH);
			}
			break;
		}
	case FRAMEMAIN_TIMER_PROGRESS_UNPACK_REFRESH:
		{
			break;
		}
	default:
		break;
	}

	return 0;
}

// CFrameWndMain ���ڻ��Ӧ
LRESULT CFrameWndMain::OnNcActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	if (::IsIconic(*this)) 
	{
		bHandled = FALSE;
	}
	return (wParam == 0) ? TRUE : FALSE;
}

// CFrameWndMain ���ڼ����С��Ӧ
LRESULT CFrameWndMain::OnNcCalcSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	return 0;
}

// CFrameWndMain ���ڻ�����Ӧ
LRESULT CFrameWndMain::OnNcPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	return 0;
}

// CFrameWndMain ���ڵ����Ӧ
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

// CFrameWndMain ������ӷ���ļ���ѯ�б���Ϣ��Ӧ
LRESULT CFrameWndMain::OnAddPacketSeekList(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	SeekPacketFileInfo();
	return 0;
}

// CFrameWndMain ������ӷ���ļ��б���Ϣ��Ӧ
LRESULT CFrameWndMain::OnAddPacketListItem(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL & bHandled)
{
	CListTextElementUI* pListElement = (CListTextElementUI*)lParam;

	if (m_pPacketList)
	{
		m_pPacketList->Add(pListElement);
	}

	return 0;
}

// CFrameWndMain ����������������С������
void CFrameWndMain::OnLButtonClickedMinBtn()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
}

// CFrameWndMain ����������������󻯴���
void CFrameWndMain::OnLButtonClickedMaxBtn()
{
	//SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
}

// CFrameWndMain ���������������رմ���
void CFrameWndMain::OnLButtonClickedCloseBtn()
{
	::PostMessageA(this->GetHWND(), WM_CLOSE, (WPARAM)0, (LPARAM)0);
}

// CFrameWndMain �������������������ļ�����
void CFrameWndMain::OnLButtonClickedEnCryptImportBtn()
{
	OPENFILENAME file;
	WCHAR strfile[MAX_PATH] = { 0 };

	ZeroMemory(&file, sizeof(OPENFILENAME));

	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = _T("�����ļ�\0*.*\0\0");
	file.nFilterIndex = 1;
	file.lpstrFile = strfile;
	file.nMaxFile = sizeof(strfile);
	file.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	if (GetOpenFileName(&file))
	{
		WCHAR* pTemp = NULL;

		pTemp = wcsrchr(strfile, _T('.'));
		if(pTemp != NULL)
		{
			m_pOriginFileType->SetText(++pTemp);
		}
		else
		{
			m_pOriginFileType->SetText(_T(""));
		}

		m_pOriginFilePath->SetText(strfile);
	}

}

// CFrameWndMain �������������������ļ�����
void CFrameWndMain::OnLButtonClickedEnCryptExportBtn()
{
	CDuiString strType = _T("");
	CDuiString strImport = _T("");

	USES_CONVERSION;

	strImport = m_pOriginFilePath->GetText();
	if (!strcmp(T2A(strImport.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ��Ŀ���ļ�·��!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	strType = m_pEnCryptFileType->GetText();
	if (!strcmp(T2A(strType.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "����������ļ�����!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	if (strType.Find(_T(".")) != -1)
	{
		MessageBoxA(this->GetHWND(), "�����ļ������в��ܰ���'.'�ַ�!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	OPENFILENAME file;
	WCHAR strfile[MAX_PATH] = { 0 };
	char chType[MAX_PATH] = { 0 };
	char chFilter[MAX_PATH] = { 0 };
	char* pTemp = NULL;
	char* pStr = nullptr;
	int nSize = 0;

	strcpy_s(chType, T2A(strType.GetData()));
	sprintf_s(chFilter, "%s�ļ�*.%s", chType, chType);

	nSize = strlen(chFilter) + 3;
	pStr = new char[nSize];
	memset(pStr, 0, nSize);
	sprintf_s(pStr, nSize, "%s�ļ�", chType);

	for (pTemp = pStr; *pTemp != '\0'; ++pTemp);
	sprintf_s(++pTemp, nSize, "*.%s", chType);

	char chOriginFile[MAX_PATH] = { 0 };
	char chOriginName[MAX_PATH] = { 0 };
	char* pTemp2 = NULL;
	char* pTemp3 = NULL;

	strcpy_s(chOriginFile, T2A(strImport.GetData()));
	pTemp2 = strrchr(chOriginFile, '\\');
	strcpy_s(chOriginName, ++pTemp2);
	pTemp3 = strrchr(chOriginName, '.');
	if (pTemp3) *pTemp3 = '\0';
	strcat_s(chOriginName, ".");
	strcat_s(chOriginName, chType);
	wcscpy_s(strfile, A2T(chOriginName));

	ZeroMemory(&file, sizeof(OPENFILENAME));

	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = A2T(pStr);
	file.nFilterIndex = 1;
	file.lpstrFile = strfile;
	file.nMaxFile = sizeof(strfile);
	file.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

	if (GetSaveFileName(&file))
	{
		m_pEnCryptFilePath->SetText(strfile);
	}

	delete[] pStr;
	pStr = nullptr;

}

// CFrameWndMain �������������������ļ���ʼ
void CFrameWndMain::OnLButtonClickedEnCryptStartBtn()
{
	CDuiString strImport = _T("");
	CDuiString strExport = _T("");

	USES_CONVERSION;

	strImport = m_pOriginFilePath->GetText();
	if (!strcmp(T2A(strImport.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ��Ŀ���ļ�·��!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	strExport = m_pEnCryptFilePath->GetText();
	if (!strcmp(T2A(strExport.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ������ļ�·��!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	m_pEnCryptStatus->SetText(_T("������..."));

	DWORD dwLuckyNumberArr[4] =
	{
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
	};

	srand((unsigned int)time(NULL));

	for (auto &it : dwLuckyNumberArr)
	{
		it = rand();
	}

	CPlumCrypt* pCrypt = new CPlumCrypt;
	pCrypt->PlumEnCryptFileExA(T2A(strImport), T2A(strExport), dwLuckyNumberArr);

	m_pEnCryptStatus->SetText(_T("�����"));

	delete pCrypt;

}

// CFrameWndMain �������������������ļ�����
void CFrameWndMain::OnLButtonClickedDeCryptImportBtn()
{
	OPENFILENAME file;
	WCHAR strfile[MAX_PATH] = { 0 };

	ZeroMemory(&file, sizeof(OPENFILENAME));

	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = _T("�����ļ�\0*.*\0\0");
	file.nFilterIndex = 1;
	file.lpstrFile = strfile;
	file.nMaxFile = sizeof(strfile);
	file.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

	if (GetOpenFileName(&file))
	{
		m_pDeCryptFilePath->SetText(strfile);
	}

}

// CFrameWndMain �������������������ļ�����
void CFrameWndMain::OnLButtonClickedDeCryptExportBtn()
{
	CDuiString strImport = _T("");

	USES_CONVERSION;

	strImport = m_pDeCryptFilePath->GetText();
	if (!strcmp(T2A(strImport.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ��Ŀ���ļ�·��!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	OPENFILENAME file;
	WCHAR strfile[MAX_PATH] = { 0 };
	char chType[MAX_PATH] = { 0 };
	char chFilter[MAX_PATH] = { 0 };
	char* pTemp = NULL;
	char* pStr = nullptr;
	int nSize = 0;

	strcpy_s(chType, ".udf");
	sprintf_s(chFilter, "%s�ļ�*.%s", chType, chType);

	nSize = strlen(chFilter) + 3;
	pStr = new char[nSize];
	memset(pStr, 0, nSize);
	sprintf_s(pStr, nSize, "%s�ļ�", chType);

	for (pTemp = pStr; *pTemp != '\0'; ++pTemp);
	sprintf_s(++pTemp, nSize, "*.%s", chType);

	char chOriginFile[MAX_PATH] = { 0 };
	char chOriginName[MAX_PATH] = { 0 };
	char* pTemp2 = NULL;
	char* pTemp3 = NULL;

	strcpy_s(chOriginFile, T2A(strImport.GetData()));
	pTemp2 = strrchr(chOriginFile, '\\');
	strcpy_s(chOriginName, ++pTemp2);
	pTemp3 = strrchr(chOriginName, '.');
	if (pTemp3) *pTemp3 = '\0';
	strcat_s(chOriginName, ".");
	strcat_s(chOriginName, chType);
	wcscpy_s(strfile, A2T(chOriginName));

	ZeroMemory(&file, sizeof(OPENFILENAME));

	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = A2T(pStr);
	file.nFilterIndex = 1;
	file.lpstrFile = strfile;
	file.nMaxFile = sizeof(strfile);
	file.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;

	if (GetSaveFileName(&file))
	{
		m_pDestFilePath->SetText(strfile);
	}

	delete[] pStr;
	pStr = nullptr;

}

// CFrameWndMain �������������������ļ���ʼ
void CFrameWndMain::OnLButtonClickedDeCryptStartBtn()
{
	CDuiString strImport = _T("");
	CDuiString strExport = _T("");

	USES_CONVERSION;

	strImport = m_pDeCryptFilePath->GetText();
	if (!strcmp(T2A(strImport.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ��Ŀ���ļ�·��!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	strExport = m_pDestFilePath->GetText();
	if (!strcmp(T2A(strExport.GetData()), ""))
	{
		MessageBoxA(this->GetHWND(), "��ѡ������ļ�·��!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	char chExport[MAX_PATH] = { 0 };
	char* pTemp = NULL;

	strcpy_s(chExport, T2A(strExport));
	pTemp = strrchr(chExport, '\\');
	if (pTemp)
	{
		*pTemp = '\0';
	}

	m_pDeCryptStatus->SetText(_T("������..."));

	CPlumCrypt* pCrypt = new CPlumCrypt;
	pCrypt->PlumDeCryptFileNoExA(T2A(strImport), chExport);

	m_pDeCryptStatus->SetText(_T("�����"));

	delete pCrypt;

}

// CFrameWndMain ����������������ӷ���ļ�
void CFrameWndMain::OnLButtonClickedPacketAddBtn()
{
	OPENFILENAME file;
	WCHAR strfile[100 * MAX_PATH] = { 0 };
	WCHAR strpath[MAX_PATH] = { 0 };
	WCHAR strname[MAX_PATH] = { 0 };
	TCHAR* p = NULL;
	int nLen = 0;

	USES_CONVERSION;

	ZeroMemory(&file, sizeof(OPENFILENAME));

	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = _T("�����ļ�\0*.*\0\0");
	file.nFilterIndex = 1;
	file.lpstrFile = strfile;
	file.nMaxFile = sizeof(strfile);
	file.Flags = OFN_EXPLORER | OFN_ALLOWMULTISELECT;

	if (GetOpenFileName(&file))
	{
		lstrcpyn(strpath, strfile, file.nFileOffset);
		strpath[file.nFileOffset] = '\0';
		nLen = lstrlen(strpath);

		if (strpath[nLen - 1] != '\\')
		{
			lstrcat(strpath, _T("\\"));
		}

		p = strfile + file.nFileOffset;

		while (*p)
		{
			ZeroMemory(strname, sizeof(strname));
			lstrcat(strname, strpath);
			lstrcat(strname, p);

			char chOriginFile[MAX_PATH] = { 0 };
			char chOriginName[MAX_PATH] = { 0 };
			char* pTemp = NULL;

			strcpy_s(chOriginFile, T2A(strname));
			pTemp = strrchr(chOriginFile, '\\');
			strcpy_s(chOriginName, ++pTemp);

			bool bRepeat = false;

			for (auto iter = m_vecPacket.begin(); iter != m_vecPacket.end(); ++iter)
			{
				if (!strcmp(iter->chFilePath, T2A(strname)))
				{
					bRepeat = true;
					break;
				}
			}

			if (!bRepeat)
			{
				S_PACKETTYPE sPacketInfo = { 0 };

				sPacketInfo.nSerial = m_vecPacket.size() + 1;
				strcpy_s(sPacketInfo.chFileName, chOriginName);
				strcpy_s(sPacketInfo.chFilePath, T2A(strname));
				m_vecPacket.push_back(sPacketInfo);
			}
			
			p += lstrlen(p) + 1;
		}

		::PostMessageA(this->GetHWND(), WM_USER_MSG_ADDITEM_SEEKPACKET, (WPARAM)0, (LPARAM)0);
	}
}

// CFrameWndMain ��������������ɾ������ļ�
void CFrameWndMain::OnLButtonClickedPacketDelBtn()
{
	int nItem = 0;

	nItem = m_pPacketList->GetCurSel();

	if (nItem < 0)
	{
		MessageBoxW(this->GetHWND(), _T("��ѡ��һ���ļ���Ϣ!"), _T("��ʾ"), MB_OK | MB_ICONASTERISK);
		return;
	}

	m_vecPacket.erase(m_vecPacket.begin() + nItem);
	for (auto iter = m_vecPacket.begin(); iter != m_vecPacket.end(); ++iter)
	{
		iter->nSerial = iter - m_vecPacket.begin() + 1;
	}

	::PostMessageA(this->GetHWND(), WM_USER_MSG_ADDITEM_SEEKPACKET, (WPARAM)0, (LPARAM)0);
}

// CFrameWndMain ���������������������ļ�
void CFrameWndMain::OnLButtonClickedPacketMoreBtn()
{
	CFrameWndPacketMore cFrameWndPacketMore;
	UINT nRet = 0;

	cFrameWndPacketMore.SetPacketFileType(m_csPacketFileType);
	cFrameWndPacketMore.SetPacketFileName(m_csPacketFileName);
	cFrameWndPacketMore.SetPacketFilePath(m_csPacketFilePath);
	cFrameWndPacketMore.Create(this->GetHWND(), _T("PacketMore"), WS_POPUP, WS_EX_WINDOWEDGE);
	cFrameWndPacketMore.CenterWindow();
	nRet = cFrameWndPacketMore.ShowModal();
	if (nRet == 1)
	{
		m_csPacketFileType = cFrameWndPacketMore.GetPacketFileType();
		m_csPacketFileName = cFrameWndPacketMore.GetPacketFileName();
		m_csPacketFilePath = cFrameWndPacketMore.GetPacketFilePath();
	}

}

// CFrameWndMain ����������������ʼ����ļ�
void CFrameWndMain::OnLButtonClickedPacketStartBtn()
{
	if (m_vecPacket.empty())
	{
		MessageBoxA(this->GetHWND(), "��ѡ������һ������ļ�!", "��ʾ", MB_OK | MB_ICONASTERISK);
		return;
	}

	USES_CONVERSION;

	if (!strcmp("", T2A(m_csPacketFilePath.GetData())))
	{
		return;
	}

	m_pPacketProgress->SetMinValue(0);
	m_pPacketProgress->SetMaxValue(m_vecPacket.size());
	m_pPacketProgress->SetValue(0);

	::KillTimer(this->GetHWND(), FRAMEMAIN_TIMER_PROGRESS_PACKET_REFRESH);
	::SetTimer(this->GetHWND(), FRAMEMAIN_TIMER_PROGRESS_PACKET_REFRESH, FRAMEMAIN_PROGRESS_REFRESH_TIME, NULL);

	DWORD dwLuckyNumberArr[4] =
	{
		0x00000000,
		0x00000000,
		0x00000000,
		0x00000000,
	};

	srand((unsigned int)time(NULL));

	for (auto &it : dwLuckyNumberArr)
	{
		it = rand();
	}

	for (int i = 0; i < 4; ++i)
	{
		g_dwLuckyArr[i] = dwLuckyNumberArr[i];
	}

	int nSize = 0;
	int nLen = 0;

	nSize = m_vecPacket.size();
	g_nSrcSize = nSize;
	g_ppSrcArr = (char**)malloc(nSize * sizeof(char*));

	for (int i = 0; i < nSize; ++i)
	{
		nLen = strlen(m_vecPacket[i].chFilePath);
		*(g_ppSrcArr + i) = (char*)malloc((nLen + 1) * sizeof(char));
		memset(*(g_ppSrcArr + i), 0, (nLen + 1));
		strcpy_s(*(g_ppSrcArr + i), (nLen + 1), m_vecPacket[i].chFilePath);
	}

	nLen = WideCharToMultiByte(CP_ACP, 0, m_csPacketFilePath.GetData(), -1, NULL, 0, NULL, NULL);
	g_pDestArr = (char*)malloc((nLen + 1) * sizeof(char));
	WideCharToMultiByte(CP_ACP, 0, m_csPacketFilePath.GetData(), -1, g_pDestArr, nLen, NULL, NULL);

	if (m_pPlumPackerThread)
	{
		m_pPlumPackerThread->PlumThreadExit();
		delete m_pPlumPackerThread;
		m_pPlumPackerThread = NULL;
	}

	g_nPackerCheck = 0;

	m_pPlumPackerThread = new CPlumThread(&m_PackerThread);
	m_pPlumPackerThread->PlumThreadInit();

}

// CFrameWndMain ���������������������ļ�
void CFrameWndMain::OnLButtonClickedUnpackImportBtn()
{
}

// CFrameWndMain ����������������������ļ�
void CFrameWndMain::OnLButtonClickedUnpackExportBtn()
{
}

// CFrameWndMain ����������������ʼ����ļ�
void CFrameWndMain::OnLButtonClickedUnpackStartBtn()
{
}
