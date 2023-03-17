#include <bits/stdc++.h>

// 이 문제는 stl로도 풀어보자 ^_^
// stl로 되나? 모르겠다..

using namespace std;

int	n, s;
int	arr[22];
int	is_used[22];
int	ans;

void	solver(int depth, int total)
{
	if (depth == n)
	{
		if (total == s)
			ans++;
		return ;
	}
	solver(depth + 1, total);
	solver(depth + 1, total + arr[depth]);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	solver(0, 0);
	if (s == 0)
		ans--;
	cout << ans;
}