#include <iostream>

using namespace std;

template <class T>
class MyQueue
{
	int	head;
	int	tail;
	T	data[2000005];
public:
	MyQueue();
	void push(T elem);
	void pop();
	int size();
	bool empty();
	int front();
	int back();
};

template <class T>
MyQueue<T>::MyQueue()
{
	head = 0;
	tail = 0;
}

template <class T>
void	MyQueue<T>::push(T elem)
{
	data[tail++] = elem;
}

template <class T>
void	MyQueue<T>::pop()
{
	head++;
}

template <class T>
int	MyQueue<T>::size()
{
	return (tail - head);
}

template <class T>
bool	MyQueue<T>::empty()
{
	if (tail == head)
		return (true);
	else
		return (false);
}

template <class T>
int	MyQueue<T>::front()
{
	return (data[head]);
}

template <class T>
int	MyQueue<T>::back()
{
	return (data[tail - 1]);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int	N;
	int	data;
	//클래스 탬플릿 타입 지정 필요
	MyQueue<int>	qu;
	string	cmd;

	cin >> N;
	while (N--)
	{
		cin >> cmd;
		if ("push" == cmd)
		{
			cin >> data; 
			qu.push(data);
		}
		else if ("pop" == cmd)
		{
			if (!qu.empty())
			{
				cout << qu.front() << '\n';
				qu.pop();
			}
			else
				cout << "-1\n";
		}
		else if ("size" == cmd)
			cout << qu.size() << '\n';
		else if ("empty" == cmd)
			cout << qu.empty() << '\n';
		else if ("front" == cmd)
		{
			if (!qu.empty())
				cout << qu.front() << '\n';
			else
				cout << "-1\n";
		}
		else if ("back" == cmd)
		{
			if (!qu.empty())
				cout << qu.back() << '\n';
			else
				cout << "-1\n";
		}
	}
	return (0);
}