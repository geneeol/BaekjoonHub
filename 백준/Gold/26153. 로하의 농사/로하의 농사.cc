#include <bits/stdc++.h>

using namespace std;

// 내일 맑은 정신으로 짜자..

int	n, m;
int	board[55][55];
pair<int, int>	pos;
int	p;
int	ans = INT_MIN;
bool	visited[55][55];
int	dx[4] = {0, 0, 1, -1};
int	dy[4] = {1, -1, 0, 0};

// 막 짜서 스파게티 그 잡채..
void	dfs(pair<int,int> v, int n_left, int sum, int prev_dir)
{
	// printf("x: %d, y: %d, before_dir: %d, n_left: %d\n", v.first, v.second, prev_dir, n_left);
	// printf("sum: %d\n", sum);
	if (n_left == 0)
	{
		ans = max(ans, sum);
		// printf("ans: %d\n\n", ans);
		return ;
	}
	if (n_left == 1 && pos != v)
	{
		ans = max(ans, sum + board[v.first][v.second]);
		// printf("ans: %d\n\n", ans);
		return ;
	}
	visited[v.first][v.second] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int	nx = v.first + dx[dir];
		int	ny = v.second + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue ;
		if (visited[nx][ny])
			continue ;
		if (prev_dir == -1)
			dfs({nx, ny}, n_left, sum, dir);
		else if (prev_dir != dir)
		{
			if (n_left - 2 >= 0)
				dfs({nx, ny}, n_left - 2, sum + board[v.first][v.second], dir);
		}
		else
			dfs({nx, ny}, n_left - 1, sum + board[v.first][v.second], dir);
		visited[nx][ny] = false;
	}
	if (n_left == 0 || pos == v)
		ans = max(ans, sum);
	else
		ans = max(ans, sum + board[v.first][v.second]);
}



int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	cin >> pos.first >> pos.second >> p;
	dfs(pos, p, board[pos.first][pos.second], -1);
	cout << ans;
}