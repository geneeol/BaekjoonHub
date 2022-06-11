#include <iostream>
#include <algorithm>

using namespace std;

//런타임 에러

int	ft_redraw(string board[55], int x, int y)
{
	int	cnt1;
	int	cnt2;

	//cnt1 wbwb로 채우는 경우
	//cnt2 bwbw로 채우는 경우
	cnt1 = 0;
	cnt2 = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0) 
			{
				if (board[x + i][y + j] == 'B')
					cnt1++;
				else
					cnt2++;
			}
			else
			{
				if (board[x + i][y + j] == 'W')
					cnt1++;
				else
					cnt2++;
			}
		}
	}
	/*
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0) 
			{
				if (board[x + i][y + j] == 'W')
					cnt2++;
			}
			else
				if (board[x + i][y + j] == 'B')
					cnt2++;
		}
	*/
	return min(cnt1, cnt2);
}
					

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string	board[55];
	int	N;
	int	M;
	int	ans;

	ans = 2147483647;
	cin >> N >> M;
	//아 여기를 이중 반복문해서 틀린듯.
	//틀렸는데 왜 된거지?
	for (int x = 0; x < N; x++)
		cin >> board[x];
	for (int x = 0; x <= N - 8; x++)
		for (int y = 0; y <= M - 8; y++)
			ans = min(ans, ft_redraw(board, x, y));
	cout << ans;
	return (0);
}