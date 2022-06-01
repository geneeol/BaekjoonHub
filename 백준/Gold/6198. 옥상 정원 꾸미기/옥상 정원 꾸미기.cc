#include <bits/stdc++.h>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;
	int	height;
	long long	sum; //long long으로 해야 안틀림
	stack<int>	stk;	

	sum = 0;
	cin >> N;
	while (N--)
	{
		cin >> height;
		while (!stk.empty() && stk.top() <= height)
			stk.pop();
		sum += stk.size();
		stk.push(height);
	}
	cout << sum;
	return (0);
}