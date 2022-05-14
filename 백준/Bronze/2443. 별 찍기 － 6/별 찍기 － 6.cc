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
	while (i < N)
	{
		j = 0;
		while (j < i)
		{
			cout << ' ';
			j++;
		}
		j = 0;
		while (j < N * 2 - i * 2 - 1)
		{
			cout << "*";
			j++;
		}
		cout << '\n';
		i++;
	}
	return (0);
}