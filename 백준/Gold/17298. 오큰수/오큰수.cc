#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int	main(void)
{
	stack<pair<int,int>>	stk;
	vector<int>	ans;
	int	N;
	int	nb;
	int	i;

	cin >> N;
	ans.resize(N);
	i = 0;
	while (i < N)
	{
		cin >> nb;
		while (!stk.empty() && stk.top().first < nb)
		{
			ans[stk.top().second] = nb;
			stk.pop();
		}
		stk.push(make_pair(nb, i));
		i++;
	}
	while (!stk.empty())
	{
		ans[stk.top().second] = -1;
		stk.pop();
	}
	for (i = 0; i < N; i++)
		cout << ans[i] << ' ';
	return (0);
}