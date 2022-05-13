#include <bits/stdc++.h>

using std::cin;
using std::cout;

int	main(void)
{
	int	arr[3][4];
	int	i;
	int	j;
	int	cnt;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			cin >> arr[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		j = 0;
		cnt = 0;
		while (j < 4)
		{
			if (arr[i][j] == 0)
				cnt++;
			j++;
		}
		if (cnt == 1)
			cout << "A\n";
		else if (cnt == 2)
			cout << "B\n";
		else if (cnt == 3)
			cout << "C\n";
		else if (cnt == 4)
			cout << "D\n";
		else
			cout << "E\n";
		i++;
	}
	return (0);
}