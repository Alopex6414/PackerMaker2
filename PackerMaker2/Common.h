/*
*     COPYRIGHT NOTICE
*     Copyright(c) 2017~2018, Team Shanghai Dream Equinox
*     All rights reserved.
*
* @file		Common.h
* @brief	This Program is PackerMaker2 Project.
* @author	alopex
* @version	v1.00a
* @date		2018-09-01
*/
#pragma once

#ifndef __COMMON_H__
#define __COMMON_H__

// Include Windows Header File
#include <Windows.h>
#include <Shlwapi.h>

// Include C Running Header File
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <mmreg.h>
#include <wchar.h>
#include <tchar.h>
#include <time.h>
#include <mmsystem.h>

// Include C++ Running Header File
#include <iostream>
#include <vector>

// Inclue ATL Header File
#include <atlconv.h>

// Include Assert Header File
#include <assert.h>

// Include Prunus Header File
#include "PlumCipherA.h"
#include "PlumCommon.h"
#include "PlumConsole.h"
#include "PlumCrypt.h"
#include "PlumFile.h"
#include "PlumGraphics.h"
#include "PlumIni.h"
#include "PlumLog.h"
#include "PlumLogEx.h"
#include "PlumPack.h"
#include "PlumPath.h"
#include "PlumProcess.h"
#include "PlumThread.h"

//Include Frame Window Header File
#include "CommonWnd.h"
#include "FrameWndBase.h"
#include "FrameWndMain.h"
#include "FrameWndSingleFile.h"
#include "FrameWndMultipleFile.h"
#include "FrameWndTextFile.h"
#include "FrameWndAppsFile.h"
#include "FrameWndCipherConfig.h"
#include "FrameWndCipherInfo.h"
#include "FrameWndMoreInfo.h"
#include "FrameWndAboutInfo.h"
#include "FrameWndPacketMore.h"
#include "DialogBuilderCallbackEx.h"
#include "PacketThread.h"
#include "UnpackThread.h"

// Include Windows Library
#pragma comment(lib, "Shlwapi.lib")

// Include Prunus Library
#pragma comment(lib, "Prunus.lib")

#endif // !__COMMON_H__

