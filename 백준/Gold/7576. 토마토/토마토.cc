#include <iostream>
#include <queue>
#include <utility>

using namespace std;

//배열 동적할당하는 법 궁금

//dist 배열은 포인터로 전달
//vector는 값의 복사 (따라서 참조자로 전달하는 것이 바람직함
//
//장애물의 dist는 당연히 -1임...
//매개변수로 board도 받아야 함.
bool	is_ripe(int dist[1005][1005], int board[1005][1005], int M, int N)
{
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			if (board[x][y] == 0 && dist[x][y] == -1)
				return (false);
	return (true);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<pair<int,int>>	que;
	pair<int,int>	curr;
	int	dx[4] = {1, 0, -1, 0};
	int	dy[4] = {0, 1, 0, -1};
	int	board[1005][1005];
	int	dist[1005][1005];
	int	max;
	int	M;
	int	N;
	int	nx;
	int	ny;

	max = 0;
	cin >> M >> N;
	//init && push starting point into que
	for (int i = 0; i < N; i++)
		fill(dist[i], dist[i] + M, -1);
	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
		{
			cin >> board[x][y];
			if (board[x][y] == 1)
			{
				dist[x][y] = 0;
				que.push({x,y});
			}
		}
	//bfs
	//find max dist
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
			if (dist[nx][ny] != -1 || board[nx][ny] != 0)
				continue ;
			dist[nx][ny] = dist[curr.first][curr.second] + 1;
			if (dist[nx][ny] > max)
				max = dist[nx][ny];
			que.push({nx,ny});
		}
	}
	//check it is ripe by dist
	if (is_ripe(dist, board, M, N))
		cout << max;
	else
		cout << -1;
	return (0);
}