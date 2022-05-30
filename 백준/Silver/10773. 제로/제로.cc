#include <iostream>
#include <stack>

using std::cin;
using std::cout;

int	main(void)
{
	int	K;
	int	data;
	int	sum;
	std::stack<int> stk;

	sum = 0;
	cin >> K;
	while (K--)
	{
		cin >> data;
		if (data == 0)
			stk.pop();
		else
			stk.push(data);
	}
	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}
	cout << sum;
	return (0);
}