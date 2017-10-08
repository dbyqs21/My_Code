#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int num;
	printf("%x", &num);

	while (num<10000)
	{
		printf("%d", num++);
		Sleep(5000);
	}
}





void main5()
{
	char c = getchar();
	char x = getchar();


	printf("[%c][%c]", c, x);

	getchar();
}



void main4()
{
	int x;
	char str[50] = "color 4f";
	system(str);
	sscanf(str, "color %x", &x);
	printf("\n%x", x);

	system("pause");
}


void main3()
{
	char str[50] = "title yueyong";
	char str1[15];
	sscanf(str, "title %s", str1);
	printf("\n%s", str1);

	system("pause");

}


void main2()
{
	char str[50];
	sprintf(str, "this is %s, age is %d", "yueyong", 23);

	char str1[15];
	int num;

	sscanf(str, "this is %s, age is %d", &str1, &num);
	printf("\n%s,%d", str, num);

	system("pause");
}





int main1()
{
	int sum = 0;
	int ge = 0;
	int shi = 0;
	int bai = 0;
	int cnt = 0;
	for (int k = 100; k<1000; k++)
	{
		ge = k % 10;
		shi = k / 10 % 10;
		bai = k / 100 % 10;

		if (k == ge*ge*ge + shi*shi*shi + bai*bai*bai)
		{
			cnt++;
			printf("第%d个水仙花数：%d\n", cnt, k);
			sum += k;
		}
	}
	printf("水仙花数总和为：%d", sum);
	getchar();
	return 0;
}