#include <iostream>
#include <stack>

#define PUSH 1
#define POP  0

using std::cin;
using std::cout;

int	n;
int	seq[100005];
int	operation[2000005];

bool	is_stk_seq(void)
{
	std::stack<int> stk;
	int	curr;
	int	j;

	curr = 1;
	j = 0;
	for (int i = 0; i < n; i++)
	{
		for ( ; curr <= seq[i]; curr++, j++)
		{
			stk.push(curr);
			operation[j] = PUSH;
		}
		if (seq[i] == stk.top())
		{
			stk.pop();
			operation[j++] = POP;
		}
		else
			return (false);
	}
	return (true);
}
			

int	main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> seq[i];
	if (is_stk_seq())
	{
		for (int i = 0; i < n * 2; i++)
		{
			if (operation[i] == PUSH)
				cout << "+\n";
			else
				cout << "-\n";
		}
	}
	else
		cout << "NO";
	return (0);
}