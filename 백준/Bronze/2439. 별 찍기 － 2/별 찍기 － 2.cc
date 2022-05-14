#include <iostream>

using	std::cin;
using	std::cout;

int	main(void)
{
	int	N;
	int	i;
	int	j;
	int	k;

	cin >> N;
	i = 0;
	while (i < N)
	{
		j = 0;
		k = 0;
		while (j < i + 1)
		{
			while (k < N - i - 1)
			{
				cout << ' ';
				k++;
			}
			cout << "*";
			j++;
		}
		cout << '\n';
		i++;
	}
	return (0);
}