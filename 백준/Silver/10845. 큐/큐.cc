#include <iostream>
#include <queue>

using namespace std;

int	main(void)
{
	int	N;
	int	data;
	queue<int>	qu;
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