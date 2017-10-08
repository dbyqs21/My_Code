template<class T>
#define MAXSIZE 20
class CSteak{
private :
	T Data[MAXSIZE];
	int top;
public :
	CSteak()
	{
		top = -1;
	}

// ��ջ�Ĳ���
	bool isFull()
	{
		return top == MAXSIZE - 1 ? true : false;
	}

	bool push(T value)  //��ջ
	{
		if (isFull())
		{
			return false;
		}
		else
		{
			Data[++top] = value;
		}
	}

	bool isEmpty()
	{
		return top == -1 ? true : false;
	}

	T pop()  //��ջ
	{
		if (!isEmpty())
			return Data[top--];
		else
			cout << "ջ�ѿ�" << endl;
	}
};