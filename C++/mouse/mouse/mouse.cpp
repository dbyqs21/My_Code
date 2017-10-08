#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void openbaidu()
{
	system("\"C:\\Program Files(x86)\\Internet Explorer\\iexplore.exe\" http://hao.360.cn/?src=lm&ls=n077c1cd59a");
	system("pause");

}
void close()
{
	system("taskkill /f /im iexplore");
}
void main()
{

	openbaidu();
	Sleep(2000);
	close();

	//Sleep(100);
	//SetCursorPos(0, 0);
	//Sleep(500);
	//Sleep(500);
	//SetCursorPos(500, 500);

	////keybd_event(0x5b, 0, 0, 0);  //°´ÏÂWindows¼ü
	////keybd_event('D', 0, 0, 0);

	////keybd_event('D', 0, 2, 0);
	////keybd_event(0x5b, 0, 2, 0);  //ËÉ¿ªWindows¼ü

	//mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	//mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



}