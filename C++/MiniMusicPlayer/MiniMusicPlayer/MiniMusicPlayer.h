
// MiniMusicPlayer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMiniMusicPlayerApp: 
// �йش����ʵ�֣������ MiniMusicPlayer.cpp
//

class CMiniMusicPlayerApp : public CWinApp
{
public:
	CMiniMusicPlayerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMiniMusicPlayerApp theApp;