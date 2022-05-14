#include <iostream>

using	std::cin;
using	std::cout;

int	main(void)
{
	int	N;
	int	i;
	int	j;

	cin >> N;
	i = 0;
	while (i < N - 1)
	{
		j = 0;
		while (j < i + 1)
		{
			cout << '*';
			j++;
		}
		j = 0;
		while (j < N * 2 - (i + 1) * 2)
		{
			cout << ' ';
			j++;
		}
		j = 0;
		while (j < i + 1)
		{
			cout << '*';
			j++;
		}
		cout << '\n';
		i++;
	}
	i = 0;
	while (i < N * 2)
	{
		cout << '*';
		i++;
	}
	cout << '\n';
	i = 0;
	while (i < N - 1)
	{
		j = 0;
		while (j < N - i - 1)
		{
			cout << '*';
			j++;
		}
		j = 0;
		while (j < (i + 1) * 2)
		{
			cout << ' ';
			j++;
		}
		j = 0;
		while (j < N - i - 1)
		{
			cout << '*';
			j++;
		}
		cout << '\n';
		i++;
	}
	return (0);
}