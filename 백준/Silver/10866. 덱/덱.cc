#include <iostream>
#include <deque>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;
	int	data;
	string	cmd;
	deque<int>	deq;

	cin >> N;
	while (N--)
	{
		cin >> cmd;
		if ("push_front" == cmd)
		{
			cin >> data;
			deq.push_front(data);
		}
		else if ("push_back" == cmd)
		{
			cin >> data;
			deq.push_back(data);
		}
		else if ("pop_front" == cmd)
		{
			if (deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if ("pop_back" == cmd)
		{
			if (deq.empty())
				cout << "-1\n";
			else
			{
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if ("size" == cmd)
			cout << deq.size() << '\n';
		else if ("empty" == cmd)
			cout << deq.empty() << '\n';
		else if ("front" == cmd)
		{
			if (deq.empty())
				cout << "-1\n";
			else
				cout << deq.front() << '\n';
		}
		else if ("back" == cmd)
		{
			if (deq.empty())
				cout << "-1\n";
			else
				cout << deq.back() << '\n';
		}
	}
	return (0);
}