#include <iostream>

using	namespace std;

int	main(void)
{
	int	N;
	int	i;
	int	j;
	
	cin >> N;
	i = 1;
	while (i <= N * 2 - 1) 
	{
		j = 1;
		while (j <= i - 1)
		{
			if (j % 2 == 1)
				cout << '*';
			else
				cout << ' ';
			j++;
		}
		j = 1;
		while (j <= (N - 1) * 4 - (i - 1) * 2 + 1)
		{
			if (i % 2 == 1)
				cout << '*';
			else
				cout << ' ';
			j++;
		}
		j = 1;
		while (j <= i - 1)
		{
			if ((i + j) % 2 == 1)
				cout << '*';

			else
				cout << ' ';
			j++;
		}
		cout << '\n';
		i++;
	}
	i = N * 2 - 2;
	while (i >= 1) 
	{
		j = 1;
		while (j <= i - 1)
		{
			if (j % 2 == 1)
				cout << '*';
			else
				cout << ' ';
			j++;
		}
		j = 1;
		while (j <= (N - 1) * 4 - (i - 1) * 2 + 1)
		{
			if (i % 2 == 1)
				cout << '*';
			else
				cout << ' ';
			j++;
		}
		j = 1;
		while (j <= i - 1)
		{
			if ((i + j) % 2 == 1)
				cout << '*';

			else
				cout << ' ';
			j++;
		}
		cout << '\n';
		i--;
	}
	return (0);
}