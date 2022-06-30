#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

#define X first
#define Y second

//전역변수를 줄일 수 있나...?
//그리고 줄이는 게 의미가 있나
//전역변수가 많으니 놓치는 부분이 생기네..
//큐가 안비는 걸 고려하지 못했음

using namespace std;

pair<int,int>	curr;
int	T;
int	w;
int	h;
int	nx;
int	ny;
int	dist1[1005][1005];
int	dist2[1005][1005];
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};


//que를 안비우고 return하면 큐에 남아있게 됨...
//상근이에 대한 bfs
void	bfs_esc(string map[1005], queue<pair<int,int>>& que2)
{
	//탈출 시간은 그냥 거리 + 1, 변수 필요 없음
	while (!que2.empty())
	{
		curr = que2.front();
		que2.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			nx = curr.X + dx[dir];
			ny = curr.Y + dy[dir];
			if (nx >= h || nx < 0 || ny >= w || ny < 0)
			{
				cout << dist2[curr.X][curr.Y] + 1 << '\n';
				return ;
			}
			if (map[nx][ny] == '#' || dist2[nx][ny] != -1)
				continue ;
			if (dist1[nx][ny] != -1 && dist2[curr.X][curr.Y] + 1 >= dist1[nx][ny])
				continue ;
			dist2[nx][ny] = dist2[curr.X][curr.Y] + 1;
			que2.push({nx,ny});
		}
	}
	cout << "IMPOSSIBLE\n";
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		cin >> w >> h;
		string	map[1005];
		queue<pair<int,int>>	que1;
		queue<pair<int,int>>	que2;
		//dist배열 매 테케마다 초기화
		for (int i = 0; i < 1005; i++)
		{
			fill(dist1[i], dist1[i] + 1005, - 1);
			fill(dist2[i], dist2[i] + 1005, - 1);
		}
		for (int i = 0; i < h; i++)
			cin >> map[i];
		//시작점 큐에 푸쉬
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == '*')
				{
					dist1[i][j] = 0;
					que1.push({i,j});
				}
				else if (map[i][j] == '@')
				{
					dist2[i][j] = 0;
					que2.push({i,j});
				}
			}
		//불에 대한 bfs
		while (!que1.empty())
		{
			curr = que1.front();
			que1.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				nx = curr.X + dx[dir];
				ny = curr.Y + dy[dir];
				if (nx >= h || nx < 0 || ny >= w || ny < 0)
					continue ;
				if (map[nx][ny] == '#' || dist1[nx][ny] != -1)
					continue ;
				dist1[nx][ny] = dist1[curr.X][curr.Y] + 1;
				que1.push({nx,ny});
			}
		}
		bfs_esc(map, que2);
	}
	return (0);
}