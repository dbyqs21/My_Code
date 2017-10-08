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

// ¶ÑÕ»µÄ²Ù×÷
	bool isFull()
	{
		return top == MAXSIZE - 1 ? true : false;
	}

	bool push(T value)  //ÈëÕ»
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

	T pop()  //µ¯Õ»
	{
		if (!isEmpty())
			return Data[top--];
		else
			cout << "Õ»ÒÑ¿Õ" << endl;
	}
};