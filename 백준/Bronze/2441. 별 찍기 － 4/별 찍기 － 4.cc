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
		k = 0;
		while (k < i)
		{
			cout << ' ';
			k++;
		}
		j = 0;
		while (j < N - i)
		{
			cout << "*";
			j++;
		}
		cout << '\n';
		i++;
	}
	return (0);
}