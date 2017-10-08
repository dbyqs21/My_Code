#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


//自定义字符串拷贝函数
char * myStrCpy(char *strDes, const char *strSrc)
{
	assert((strDes != nullptr) && (strSrc != nullptr));
	while ((*strDes++ = *strSrc++) != '\0');
	return strDes;
}

//自定义将字符串转换为整数
int myAtoI(char * str)
{
	if (str == nullptr)
	{
		printf("Invalid input!!");
		return 0;
	}
	while (*str == ' ' || *str == '  ')
		str++;
	int nSign = (*str == '-') ? -1 : 1;    //确定符号位
	if (*str == '+' || *str == '-')
		str++;
	int nResult = 0;
	while (*str >= '0' && *str <= '9')
	{
		nResult = nResult * 10 + (*str - '0');
		str++;
	}
	return nSign*nResult;
}

//自定义内存拷贝函数
void * myMemCpy(void * dest, const void * src, size_t count)
{
	char * pDest = static_cast<char *>(dest);
	const char *pSrc = static_cast<const char *>(src);

	if (pDest > pSrc && pDest < (pSrc + count))
	{
		for (size_t i = count - 1; i != -1; --i)
			pDest[i] = pSrc[i];
	}
	else
	{
		for (size_t i = 0; i < count; ++i)
			pDest[i] = pSrc[i];
	}
	return dest;
}


//自定义将整数转化为字符串
char * myItoA(int num)
{
	char str[12];
	int nSign = num;
	int i = 0; 
	int j = 0;

	char tmp[11];

	if (nSign < 0)
	{
		num = -num;
	}

	do
	{
		tmp[i] = num % 10 + '0';
		num=num / 10;
		i++;
	} while (num>0);
	if (nSign < 0)
	{
		tmp[i++] = '-';
	}
	tmp[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = tmp[i];
		j++;
		i--;
	}
	str[j] = '\0';
	return str;
}


/*****************测试代码******************/
int main()
{
	char a[] = "        -569";
	char b[20];
	myStrCpy(b, a);
	printf("%s\n", (char *)myMemCpy((void *)b,(void *)a,13));

	printf("%d", myAtoI(a));


	system("pause");
	return 0;
}