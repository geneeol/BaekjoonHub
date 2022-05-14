#include <iostream>

using	namespace std;

int	is_fire(int arr[], int i, int N)
{
	int	idx;

	idx = 0;
	while (idx < N)
	{
		if (i % arr[idx] == 0)
			return (1);
		idx++;
	}
	return (0);
}

int	main(void)
{
	int	N;
	int	C;
	int	cnt;
	int	i;
	int	arr[105];

	cin >> N >> C;
	cnt = 0;
	i = 0;
	while (i < N)
	{
		cin >> arr[i];
		i++;
	}
	i = 1;
	while (i <= C)
	{
		if (is_fire(arr, i, N))
			cnt++;
		i++;
	}
	cout << cnt;
	return (0);
}