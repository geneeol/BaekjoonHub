#include <bits/stdc++.h>

using namespace std;

//입력을 굳이 int로 파싱할 필요 없음.

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	queue<pair<int,int>>	que;
	int	dist[105][105];
	int	dx[4] = {1, 0, -1, 0};
	int	dy[4] = {0, 1, 0, -1};
	pair<int,int>	curr;
	string	map[102];
	int	N;
	int	M;
	int	nx;
	int	ny;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		fill(dist[i], dist[i] + M, -1);
	for (int x = 0; x < N; x++)
		cin >> map[x];
	dist[0][0] = 1;
	que.push({0,0});
	while (!que.empty())
	{
		curr = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			nx = curr.first + dx[dir];
			ny = curr.second + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue ;
			//and 연산시 (0,0)이 큐에 또 들어가서 무한 루프
			if (dist[nx][ny] != -1 || map[nx][ny] != '1')
				continue ;
			dist[nx][ny] = dist[curr.first][curr.second] + 1;
			que.push({nx,ny});
		}
	}
	cout << dist[N - 1][M - 1];
	return (0);
}