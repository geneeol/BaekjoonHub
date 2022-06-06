#include <iostream>
#include <stack>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string	str;
	stack<char>	stk;
	int	status;
	int	ans;

	ans = 0;
	status = 0;
	cin >> str;
	for (auto ch : str)
	{
		if (ch == '(')
		{
			stk.push(ch);
			status = 1;
		}
		else
		{
			if (status == 1)
			{
				stk.pop();
				ans += stk.size();
			}
			else
			{
				stk.pop();
				ans += 1;
			}
			status = 0;
		}
	}
	cout << ans;
	return (0);
}