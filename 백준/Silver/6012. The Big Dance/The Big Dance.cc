#include <bits/stdc++.h>

using namespace std;

int	g_sum;

void	solver(int from, int to)
{
	int	half_len;

	if (to - from == 1)
	{
		g_sum += from * to;
		return ;
	}
	if (to == from)
		return ;
	half_len = (to - from) / 2; 
	solver(from, from + half_len);
	solver(from + half_len + 1, to);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	n;

	cin >> n;
	solver(1, n);
	cout << g_sum;
}