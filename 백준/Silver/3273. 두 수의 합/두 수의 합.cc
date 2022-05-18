#include <bits/stdc++.h>

using namespace std;

int	occur[2000001];

int	main(void)
{
	int	cnt;
	int	n;
	int	arr[100001];
	int	x;
	int	i;

	cnt = 0;
	cin >> n;
	i = 0;
	while (i < n)
	{
		cin >> arr[i];
		i++;
	}
	cin >> x;
	i = -1;
	while (++i < n)
	{
		if (arr[i] > x)
			continue ;
		if (occur[x - arr[i]])
		{
			cnt++;
			occur[arr[i]] = 0;
		}
		else
			occur[arr[i]] = 1;
	}
	cout << cnt;
	return (0);
}