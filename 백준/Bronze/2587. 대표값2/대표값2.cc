#include <bits/stdc++.h>

using namespace std;

int	main(void)
{
	int	arr[5];
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (i < 5)
	{
		cin >> arr[i];
		sum += arr[i];
		i++;
	}
	cout << sum / 5 << '\n';
	sort(arr, arr + 5);
	cout << arr[2];
	return (0);
}