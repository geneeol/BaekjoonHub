#include <bits/stdc++.h>

using	namespace std;

int	main(void)
{
	int	arr[9];
	int	total;
	int	i;
	int	j;
	int	k;

	total = 0;
	i = 0;
	while (i < 9)
	{
		cin >> arr[i];
		total += arr[i];
		i++;
	}
	sort(arr, arr + 9);
	i = 0;
	while (i < 9)
	{
		j = i + 1;
		while (j < 9)
		{
			if (total - 100 == arr[i] + arr[j])
				break;
			j++;
		}
		if (total - 100 == arr[i] + arr[j])
				break;
		i++;
	}
	k = -1;
	while (++k < 9)
	{
		if (k == i || k == j)
			continue ;
		cout << arr[k] << '\n';
	}
	return (0);
}