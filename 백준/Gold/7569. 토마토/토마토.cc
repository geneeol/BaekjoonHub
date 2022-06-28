#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

queue<tuple<int,int,int>>	que;
tuple<int,int,int>	cur;
int	dx[6] = {1, -1, 0, 0, 0, 0};
int	dy[6] = {0, 0, 1, -1, 0, 0};
int	dz[6] = {0, 0, 0, 0, 1, -1};
int	map[105][105][105];
int	dist[105][105][105];

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	M;
	int	N;
	int	H;
	int	nx;
	int	ny;
	int	nz;
	int	curX;
	int	curY;
	int	curZ;
	int	max;

	max = 0;
	cin >> M >> N >> H;
	//z, x, y
	for (int z = 0; z < H; z++)
		for(int x = 0; x < N; x++)
			for(int y = 0; y < M; y++)
			{
				cin >> map[x][y][z];
				if (map[x][y][z] == 1)
					que.push({x,y,z});
				else
					dist[x][y][z] = -1;
			}
	while (!que.empty())
	{
		cur = que.front();
		tie(curX, curY, curZ) =cur;
		que.pop();
		for (int dir = 0; dir < 6; dir++)
		{
			nx = get<0>(cur) + dx[dir];
			ny = get<1>(cur) + dy[dir];
			nz = get<2>(cur) + dz[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
				continue ;
			if (map[nx][ny][nz] == -1 || dist[nx][ny][nz] != -1)
				continue ;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			if (dist[nx][ny][nz] > max)
				max = dist[nx][ny][nz];
			que.push({nx,ny,nz});
		}
	}
	for (int z = 0; z < H; z++)
		for (int x = 0; x < N; x++)
			for (int y = 0; y < M; y++)
			{
				if (map[x][y][z] == 0 && dist[x][y][z] == -1)
				{
					cout << -1;
					return (0);
				}
			}
	cout << max;
	return (0);
}