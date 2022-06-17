#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

#define X first
#define Y second

//조건문만 함수 포인터로 구분해서 처리하자
//전역변수 덜 쓰고 짤 수 있나..?

using namespace std;

queue<pair<int,int>>	que;
pair<int,int>	curr;
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};
string	board[105];
int	vis[105][105];
int	N;

bool	normal(int nx, int ny, char color)
{
	if (vis[nx][ny] != -1 || board[nx][ny] != color)
		return (true);
	else
		return (false);
}

bool	abnormal(int nx, int ny, char color)
{
	if (color == 'R' || color == 'G')
	{
		if (vis[nx][ny] != -1 || board[nx][ny] == 'B')
			return (true);
		else
			return (false);
	}
	else
	{
		if (vis[nx][ny] != -1 || board[nx][ny] != color)
			return (true);
		else
			return (false);
	}
}

int	bfs(bool (*is_invalid)(int, int, char))
{
	char	color;
	int		ret;
	int		nx;
	int		ny;

	ret = 0;
	for (int x = 0; x < N; x++)
		fill (vis[x], vis[x] + N, -1);
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
		{
			if (vis[x][y] == -1)
			{
				//아래 부분을 다르게 분리할 수 있을까?
				color = board[x][y];
				vis[x][y] = 1;
				que.push({x,y});
				while (!que.empty())
				{
					curr = que.front();
					que.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						nx = curr.X + dx[dir];
						ny = curr.Y + dy[dir];
						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue ;
						if (is_invalid(nx, ny, color))
							continue ;
						vis[nx][ny] = 1;
						que.push({nx,ny});
					}
				}
				ret++;
			}
		}
	return (ret);
}

int	main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	cout << bfs(normal) << ' ';
	cout << bfs(abnormal);
}