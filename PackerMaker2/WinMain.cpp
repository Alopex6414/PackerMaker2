/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		WinMain.cpp
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#include "WinMain.h"

/*
** WinMain(IN HINSTANCE hInstance, IN HINSTANCE hPrevInstance, IN LPSTR lpCmdLine, IN int nCmdShow)
** Purpose:  窗口主函数
** Para: IN HINSTANCE hInstance			// 窗口实例句柄(Win32)
** Para: IN HINSTANCE hPrevInstance		// 窗口实例句柄(Win16)
** Para: IN LPSTR lpCmdLine				// 窗口命令行参数数组<char*[]>
** Para: IN int nCmdShow				// 窗口命令行参数数量<int>
** Return: INT Msg						// 返回值(消息参数)
*/
int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath());

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return -1;

	CFrameWndMain cMainFrame;
	cMainFrame.Create(NULL, _T("PackerMaker"), WS_POPUP, WS_EX_WINDOWEDGE);
	cMainFrame.CenterWindow();
	cMainFrame.ShowModal();

	::CoUninitialize();

	return 0;
}