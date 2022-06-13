#include <iostream>
#include <algorithm>
#include <queue>

#define X first
#define Y second

using namespace std;

//1926그림이랑 똑같은 문제임
//x,y축이 내가 쓰던 축과 달라서 틀린거였음..
//꼭 꼼꼼하게 확인할 것

void	bfs(bool vis[55][55], int map[55][55], pair<int,int> start, int M, int N)
{
	queue<pair<int,int>>	que;
	pair<int,int>	curr;
	int	dx[4] = {1, 0, -1, 0};
	int	dy[4] = {0, 1, 0, -1};
	int	nx;
	int	ny;
	
	que.push(start);
	while (!que.empty())
	{
		curr = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			nx = curr.X + dx[dir];
			ny = curr.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue ;
			if (vis[nx][ny] == true || map[nx][ny] != 1)
				continue ;
			vis[nx][ny] = true;
			que.push({nx,ny});
		}
	}
}

void	input_handler(void)
{
	int		map[55][55];
	bool	vis[55][55];
	int		M;
	int		N;
	int		K;
	int		x;
	int		y;
	int		cnt;

	cnt = 0;
	cin >> M >> N >> K;
	for (int i = 0; i < N; i++)
	{
		fill(map[i], map[i] + M , 0);
		fill(vis[i], vis[i] + M, false);
	}
	while (K--)
	{
		cin >> y >> x;
		map[x][y] = 1;
	}
	//여기까지 초기세팅

	//각각의 지점을 큐에 넣을 수 있는지 판별
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j] == false && map[i][j] == 1)
			{
				vis[i][j] = true;
				cnt++;
				bfs(vis, map, {i,j}, M, N);
			}
		}
	cout << cnt << '\n';
}


int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int	T;

	cin >> T;
	while (T--)
		input_handler();
	return (0);
}