#include "CNode.h"

class CManage{
	CNode **A=nullptr;
	int length;
	int N;
public :
	CManage()
	{
		length = 10;
		N = 0;
		A = new CNode*[length];
		for (int i = 0; i < length; ++i) A[i] = nullptr;
	}
	void append(CNode * pKey)
	{
		if (N == length)
		{
			CNode **p = new CNode*[length * 2 + 1];
			length = length * 2 + 1;
			for (int i = 0; i < N; ++i) p[i] = A[i];
			delete [] A;
		}
		A[++N] = pKey;
	}
};
