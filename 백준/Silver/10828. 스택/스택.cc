#include <iostream>
#include <stack>

using std::cin;
using std::cout;

int	main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int			N;
	int			data;
	int			tos;
	std::string		command;
	std::stack <int>	stk;

	cin >> N;
	tos = 0;
	while (N--)
	{
		cin >> command;
		if (command == "push")
		{
			cin >> data;
			stk.push(data);
			tos++;
		}
		else if (command == "pop")
		{
			if (tos == 0)
			{
				cout << -1 << '\n';
				continue ;
			}
			cout << stk.top() << '\n';
			stk.pop();
			tos--;
		}
		else if (command == "size")
			cout << stk.size() << '\n';
		else if (command == "empty")
			cout << (int)stk.empty() << '\n';
		else if (command == "top")
		{
			if (tos == 0)
			{
				cout << -1 << '\n';
				continue ;
			}
			cout << stk.top() << '\n';
		}
	}
	return (0);
}