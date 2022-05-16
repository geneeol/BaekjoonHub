#include <iostream>

using	namespace std;

char	arr[2187][2187];

void	draw_blank(int size, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < x + size)
	{
		j = y;
		while (j < y + size)
		{
			arr[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	draw_map(int size, int x, int y)
{
	int	sector;
	int	i;
	int	j;

	sector = 0;
	if (size == 1)
	{
		arr[x][y] = '*';
		return ;
	}
	size /= 3;
	i = x;
	while (i <= x + size * 2)
	{
		j = y;
		while (j <= y + size * 2)
		{
			sector++;
			if (sector == 5)
				draw_blank(size, i, j);
			else
				draw_map(size, i, j);
			j += size;
		}
		i += size;
	}
}

void	print_map(int N)
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			cout << arr[i][j];
			j++;
		}
		cout << '\n';
		i++;
	}
}

int	main(void)
{
	int	N;
	int	power;

	cin >> N;
	draw_map(N, 0, 0);
	print_map(N);
	return (0);
}