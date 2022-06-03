#include <iostream>
#include <queue>

using namespace std;

class MyQueue
{
	int	head;
	int	tail;
	int	data[10005];
public:
	MyQueue();
	void push(int element);
	void pop();
	int size();
	bool empty();
	int front();
	int back();
};

MyQueue::MyQueue()
{
	head = 0;
	tail = 0;
}

void	MyQueue::push(int element)
{
	data[tail++] = element;
}

void	MyQueue::pop()
{
	head++;
}

int	MyQueue::size()
{
	return (tail - head);
}

bool	MyQueue::empty()
{
	if (head == tail)
		return (true);
	else
		return (false);
}

int	MyQueue::front()
{
	return (data[head]);
}

int	MyQueue::back()
{
	return (data[tail - 1]);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int	N;
	int	data;
	MyQueue	qu;
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