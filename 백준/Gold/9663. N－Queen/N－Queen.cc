#include <bits/stdc++.h>

using namespace std;

int	board[15];
int	n;
int	ans;

bool	is_promising(int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (board[i] == row 
			|| board[i] - row == i - col 
			|| board[i] + i == row + col)
			return (false);
	}
	return (true);
}

static void	sovle_n_queen(int col)
{
	if (col == n)
	{
		ans++;
		return ;
	}
	for (int row = 0; row < n; row++)
	{
		if (is_promising(col, row))
		{
			board[col] = row;
			sovle_n_queen(col + 1);
		}
	}
}

int	main(void)
{
	cin >> n;
	sovle_n_queen(0);
	cout << ans;
}