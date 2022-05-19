#include <iostream>

using	namespace std;

char	map[8000][8000];

void	draw_star(int N, int y, int x)
{
	int	i;

	if (N == 3)
	{
		map[y][x] = '*';
		map[y + 1][x - 1] = '*';
		map[y + 1][x + 1] = '*';
		i = x - 2;
		while (i <= x + 2)
		{
			map[y + 2][i] = '*';
			i++;
		}
		return ;
	}
	draw_star(N / 2, y, x);
	draw_star(N / 2, y + N / 2, x - N / 2);
	draw_star(N / 2, y + N / 2, x + N / 2);
}

void	print_star(int N)
{
	int	y;
	int	x;

	y = 0;
	while (y < N)
	{
		x = 0;
		while (x < N * 2 - 1)
		{
			if (map[y][x] == '*')
				cout << '*';
			else
				cout << ' ';
			x++;
		}
		cout << '\n';
		y++;
	}
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	N;

	cin >> N;
	draw_star(N, 0, N - 1);
	print_star(N);
	return (0);
}