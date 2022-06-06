#include <iostream>
#include <stack>

//코드가 더러워..

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	stack<char>	stk;
	string	str;
	int	mult;	
	int	ans;

	mult = 1;
	ans = 0;
	cin >> str;
	if (str[0] == ')' || str[0] == ']')
	{
		cout << '0';
		return (0);
	}
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (str[i] == '(')
		{
			stk.push(str[i]);
			mult *= 2;
		}
		else if (str[i] == '[')
		{
			stk.push(str[i]);
			mult *= 3;
		}
		else if (str[i - 1] == '(' && str[i] == ')')
		{
			mult /= 2;
			stk.pop();
			ans += mult * 2;
		}
		else if (str[i - 1] == '[' && str[i] == ']')
		{
			mult /= 3;
			stk.pop();
			ans += mult * 3;
		}
		else
		{
			if (!stk.empty())
			{
				if (stk.top() == '(' && str[i] == ')')
				{
					mult /= 2;
					stk.pop();
				}
				else if (stk.top() == '[' && str[i] == ']')
				{
					mult /= 3;
					stk.pop();
				}
			}
			else
			{
				cout << "0";
				return (0);
			}
		}
	}
	if (stk.empty())
		cout << ans;
	else
		cout << "0";
	return (0);
}