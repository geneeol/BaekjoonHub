#include <bits/stdc++.h>

using namespace std;

string	board[1005];
int		dist[1005][1005][2];
int		n, m;
int		ans = -1;
int		dx[4] = {1, -1, 0, 0};
int		dy[4] = {0, 0, 1, -1};

typedef struct s_node
{
	int	x;
	int	y;
	int	broken;
}	t_node;

int	bfs()
{
	int				nx, ny, nbroken;
	queue<t_node>	que;
	t_node			cur;

	que.push((t_node){0, 0, 0});
	while (!que.empty())
	{
		cur = que.front();
		if (cur.x == n - 1 && cur.y == m - 1)
			return (dist[cur.x][cur.y][cur.broken]);
		que.pop();
		nbroken = cur.broken;
		for (int dir = 0; dir < 4; dir++)
		{
			nx = cur.x + dx[dir];
			ny = cur.y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue ;
			if (board[nx][ny] == '0' && dist[nx][ny][nbroken] == -1)
			{
				dist[nx][ny][nbroken] = dist[cur.x][cur.y][nbroken] + 1;
				que.push((t_node){nx, ny, nbroken});
			}
			else if (board[nx][ny] == '1' && nbroken == 0 && dist[nx][ny][nbroken + 1] == -1)
			{
				dist[nx][ny][nbroken + 1] = dist[cur.x][cur.y][nbroken] + 1;
				que.push((t_node){nx, ny, nbroken + 1});
			}
		}
	}
	return (-1);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	dist[0][0][0] = dist[0][0][1] = 1;
	cout << bfs();
	return (0);
}