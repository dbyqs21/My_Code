// zhiwudazhanjaingshiwaigua.cpp : �������̨Ӧ�ó������ڵ㡣
//����Ŀ�ģ�ֲ���ս��ʬ���

#include "stdafx.h"
#include "windows.h"
#include "stdlib.h"

void MainMenu()
{
	printf("\n=========== ֲ���ս��ʬ���==================\n");
	printf("=    1�� �޸�����\n");
	printf("=    2���޸Ľ�� \n");
	printf("=    3���˳� \n");
	printf("============================================\n");
}

int DisPlaySun()
{
	HWND hGame = ::FindWindow(NULL, L"ֲ���ս��ʬ���İ�");       //���ݴ��ڵ����ֵõ����ڵľ��
	DWORD ProcessID;
	::GetWindowThreadProcessId(hGame, &ProcessID);                         //�õ��߳�ID
	//�����߳�ID�������̾��
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
	printf("��ǰ���⣺%d \n", sun);
	return 0;
}

int ModifySun(int newsun)
{
	HWND hGame = ::FindWindow(NULL, L"ֲ���ս��ʬ���İ�");       //���ݴ��ڵ����ֵõ����ڵľ��
	DWORD ProcessID;
	::GetWindowThreadProcessId(hGame, &ProcessID);                         //�õ��߳�ID
	//�����߳�ID�������̾��
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

	//  printf("��ǰ���⣺%d \n", sun);
	LPVOID  wbuf = (LPVOID)&newsun;
	::WriteProcessMemory(hProcess, pBase, wbuf, 4, &bread);
	printf("�޸ĳɹ�\n");
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HWND hGame=::FindWindow(NULL,L"ֲ���ս��ʬ���İ�");       //���ݴ��ڵ����ֵõ����ڵľ��
	RECT WindowSize;
	::GetWindowRect(hGame, &WindowSize);
	printf("��Ϸ��Ϣ��%d��%d ��%d��%d", WindowSize.left, WindowSize.top, WindowSize.right, WindowSize.bottom);


	POINT point;
	::GetCursorPos(&point);
	printf("�����Ϣ��%d��%d", point.x,point.y);

	if (NULL == hGame)
	{
		printf("ֲ���ս��ʬδ�򿪣����ֲ���ս��ʬ");
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
				  printf("������������޸�ֵ��\n");
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

