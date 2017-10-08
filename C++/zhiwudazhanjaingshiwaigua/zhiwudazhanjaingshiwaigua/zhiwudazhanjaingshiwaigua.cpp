// zhiwudazhanjaingshiwaigua.cpp : 定义控制台应用程序的入口点。
//代码目的：植物大战僵尸外挂

#include "stdafx.h"
#include "windows.h"
#include "stdlib.h"

void MainMenu()
{
	printf("\n=========== 植物大战僵尸外挂==================\n");
	printf("=    1、 修改阳光\n");
	printf("=    2、修改金币 \n");
	printf("=    3、退出 \n");
	printf("============================================\n");
}

int DisPlaySun()
{
	HWND hGame = ::FindWindow(NULL, L"植物大战僵尸中文版");       //根据窗口的名字得到窗口的句柄
	DWORD ProcessID;
	::GetWindowThreadProcessId(hGame, &ProcessID);                         //得到线程ID
	//根据线程ID的鳌进程句柄
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);

	LPVOID pBase = (LPVOID)6987456;
	int sun = 0;

	LPVOID rbuffer = (LPVOID)&sun;
	DWORD bread;
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4,&bread);

	pBase = (LPVOID)(sun + 1896);
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &bread);
	pBase = (LPVOID)(sun + 21856);
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &bread);
	printf("当前阳光：%d \n", sun);
	return 0;
}

int ModifySun(int newsun)
{
	HWND hGame = ::FindWindow(NULL, L"植物大战僵尸中文版");       //根据窗口的名字得到窗口的句柄
	DWORD ProcessID;
	::GetWindowThreadProcessId(hGame, &ProcessID);                         //得到线程ID
	//根据线程ID的鳌进程句柄
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);

	LPVOID pBase = (LPVOID)6987456;
	int sun = 0;

	LPVOID rbuffer = (LPVOID)&sun;
	DWORD bread;
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &bread);

	pBase = (LPVOID)(sun + 1896);
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &bread);
	pBase = (LPVOID)(sun + 21856);
	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &bread);

	//  printf("当前阳光：%d \n", sun);
	LPVOID  wbuf = (LPVOID)&newsun;
	::WriteProcessMemory(hProcess, pBase, wbuf, 4, &bread);
	printf("修改成功\n");
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HWND hGame=::FindWindow(NULL,L"植物大战僵尸中文版");       //根据窗口的名字得到窗口的句柄
	RECT WindowSize;
	::GetWindowRect(hGame, &WindowSize);
	printf("游戏信息：%d，%d ，%d，%d", WindowSize.left, WindowSize.top, WindowSize.right, WindowSize.bottom);


	POINT point;
	::GetCursorPos(&point);
	printf("鼠标信息：%d，%d", point.x,point.y);

	if (NULL == hGame)
	{
		printf("植物大战僵尸未打开，请打开植物大战僵尸");
		Sleep(500);
		return 0;
	}

	int op = 0;
	while (1)
	{
		MainMenu();
		scanf("%d", &op);

		int temp = 0;
		switch (op)
		{
		case 1:
		{
				  temp=DisPlaySun();
				  int a = 0;
				  printf("请输入阳光的修改值：\n");
				  scanf("%d", &a);
				  temp = ModifySun(a);
				  break;
		}
		case 2:
		{
				  
				  break;
		}
		case 3:
			break;
		default :
			break;
		}


	}




	MainMenu();






	return 0;
}

