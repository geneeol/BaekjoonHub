#include <bits/stdc++.h>

using namespace std;

int	arr[7][2];

int	main(void)
{
	int	n;
	int	k;
	int	i;
	int	j;
	int	sex;
	int	year;
	int	room;

	cin >> n >> k;
	room = 0;
	i = 0;
	while (i < n)
	{
		cin >> sex >> year;
		arr[year][sex]++;
		i++;
	}
	i = 1;
	while (i <= 6)
	{
		j = 0;
		while (j <= 1)
		{
			room += arr[i][j] / k;
			if (arr[i][j] % k != 0)
				room++;
			j++;
		}
		i++;
	}
	cout << room;
	return (0);
}