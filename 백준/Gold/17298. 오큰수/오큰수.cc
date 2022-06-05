#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//바킹독 로직이 더 간단한듯.. 내가 하려던 방식
//뒤에서 부터 검사하면 굳이 pair를 만들 필요가 없음
int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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