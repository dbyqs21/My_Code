// 2.3.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;
void Find(int ID[], int N);

int ID[20] = { 1, 1, 1, 3, 2, 1, 11, 2, 3, 3, 4, 2, 3, 6, 2, 2, 3, 1, 2, 1 };//代表发帖人的ID
//int ID[20]={1,1,1,1,1,1,3,4,5,6,7,8,9,10,11,12,13,14,15};

int main(int argc, char* argv[])
{
	Find(ID, 20);
	system("pause");
	return 0;
}

void Find(int ID[], int N)//有3个人发帖超过总数的0.25N
{
	int candidate[3];
	int i, j;

	double nTimes[3] = { 0, 0, 0 };   // 保存重复出现的次数

	bool label = true;

	for (i = 0; i<N; i++)
	{
		label = true;
		for (j = 0; j<3; j++)
		{
			if (nTimes[j] != 0 && candidate[j] == ID[i])
			{
				nTimes[j] += 4 / 3.0; //因为后面要统一减 1/3,所以这里要加4/3
				label = false; //如果下个数字与candidate重复则，不进行下面的循环。
				break;
			}
		}

		if (label)
		{
			for (j = 0; j<3; j++)
			{
				if (nTimes[j] <= 0)
				{
					candidate[j] = ID[i];
					nTimes[j] = 4 / 3.0;   //因为后面要统一减 1/3,所以这里要加4/3
					break;
				}
			}

		}

		for (j = 0; j<3; j++)
		{
			nTimes[j] -= 1 / 3.0;
		}
	}

	for (j = 0; j<3; j++)
		cout << candidate[j] << endl;

}