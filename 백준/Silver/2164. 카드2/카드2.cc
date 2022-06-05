#include <bits/stdc++.h>

using namespace std;


//발로 짰음..
int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int	N;
	queue<int> que;

	cin >> N;
	for (int i = 1; i <= N; i++)
		que.push(i);
	while (que.size() != 1)
	{
		que.pop();
		if (que.size() != 1)
		{
			que.push(que.front());
			que.pop();
		}
	}
	cout << que.front();
	return (0);
}