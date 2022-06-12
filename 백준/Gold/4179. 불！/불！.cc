#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

#define X first
#define Y second

using namespace std;

queue<pair<int,int>>	que;
pair<int,int>	curr;
string	board[1005];
int	dist1[1005][1005];
int	dist2[1005][1005];
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};
int	R;
int	C;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	pair<int,int>	start;
	int	nx;
	int	ny;

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> board[i];
	//초기 세팅, 필요한 정보 읽어서 변수값들 세팅
	for (int x = 0; x < R; x++)
		for (int y = 0; y < C; y++)
		{
			if (board[x][y] == 'F')
			{
				que.push({x,y});
				dist2[x][y] = -1;
			}
			else if (board[x][y] == 'J') 
			{
				start = make_pair(x,y);
				dist1[x][y] = -1;
			}
			else
			{
				dist1[x][y] = -1;
				dist2[x][y] = -1;
			}
		}
	//불에 대한 bfs
	while (!que.empty())
	{
		curr = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			nx = curr.X + dx[dir];
			ny = curr.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue ;
			if (dist1[nx][ny] != -1 || board[nx][ny] == '#')
				continue ;
			dist1[nx][ny] = dist1[curr.X][curr.Y] + 1;
			que.push({nx,ny});
		}
	}
	//지훈이에 대한 bfs
	//1. 지훈이 탈출 경로에 불이 안붙었다면?
	//dist1의 값이 -1이므로 부등식이 성립하지 않음.
	//따라서 해당 조건을 따로 추가해주어야함.
	//
	//2. 지훈이가 이미 가장자리에 서있다면?
	//nx값을 볼 게 아니라 curr에서 탈출 가능한지도 체크해야함.
	//따라서 nx값을 보되, nx가 경계를 벗어났는지 체크하는게 훨씬 간단함
	//첫번째 if문이 결국 탈출조건이므로 해당 조건을 이용하는 게 더 나아보임.
	que.push(start);
	while (!que.empty())
	{
		curr = que.front();
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			nx = curr.X + dx[dir];
			ny = curr.Y + dy[dir];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << dist2[curr.X][curr.Y] + 1;
				return (0);
			}
			if (dist2[nx][ny] != -1 || board[nx][ny] == '#')
				continue ;
			if (dist1[nx][ny] != -1 && dist2[curr.X][curr.Y] + 1 >= dist1[nx][ny])
				continue ;
			dist2[nx][ny] = dist2[curr.X][curr.Y] + 1;
			que.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE";
	return (0);
}