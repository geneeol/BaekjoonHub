#include <bits/stdc++.h>

using namespace std;

int	paper[2200][2200];
int	ans1;
int	ans2;
int	ans3;

bool	all_same_color(int n, int x, int y)
{
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (paper[i][j] != paper[y][x])
				return (false);
		}
	}
	return (true);
}

void	cut_paper_recursive(int n, int x, int y)
{
	if (all_same_color(n, x, y))
	{
		if (paper[y][x] == -1)
			ans1++;
		if (paper[y][x] == 0)
			ans2++;
		if (paper[y][x] == 1)
			ans3++;
		return ;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cut_paper_recursive(n / 3, x + (n / 3) * i, y + (n / 3) * j);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int	n;

	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> paper[y][x];
	cut_paper_recursive(n, 0, 0);
	cout << ans1 << "\n";
	cout << ans2 << "\n";
	cout << ans3;
	return (0);
}