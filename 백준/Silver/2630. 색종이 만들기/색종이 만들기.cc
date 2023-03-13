#include <bits/stdc++.h>

using namespace std;

int	paper[130][130];
int	white_cnt;
int	blue_cnt;
int	n;

void	cut_recursive(int y1, int y2, int x1, int x2)
{
	int		xm;
	int		ym;
	bool	all_white = true;
	bool	all_blue = true;

	for (int y = y1; y <= y2; y++)
	{
		for(int x = x1; x <= x2; x++)
		{
			if (paper[y][x] == 1)
				all_white = false;
			if (paper[y][x] == 0)
				all_blue = false;
		}
	}
	if (all_white)
	{
		white_cnt++;
		return ;
	}
	if (all_blue)
	{
		blue_cnt++;
		return ;
	}
	xm = (x1 + x2) / 2;
	ym = (y1 + y2) / 2;
	cut_recursive(y1, ym, x1, xm);
	cut_recursive(y1, ym, xm + 1, x2);
	cut_recursive(ym + 1, y2, x1, xm);
	cut_recursive(ym + 1, y2, xm + 1, x2);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> paper[y][x];
	cut_recursive(0, n - 1, 0, n -1);
	cout << white_cnt << "\n";
	cout << blue_cnt;
	return (0);
}