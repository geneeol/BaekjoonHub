#include <bits/stdc++.h>

using	namespace std;

void	rev_card(int arr[], int a, int b)
{
	int	size;
	int	i;
	int	tmp;
	
	size = b - a + 1;
	i = 0;
	while (i < size / 2)
	{
		tmp = arr[a + i];
		arr[a + i] = arr[b - i];
		arr[b - i] = tmp;
		i++;
	}
}

void	print(int arr[])
{
	int	i;

	i = 0;
	while (++i < 21)
		cout << arr[i] << ' ';
}

int	main(void)
{
	int	arr[21];
	int	a;
	int	b;
	int	i;

	i = -1;
	while (++i < 21)
		arr[i] = i;
	i = 0;
	while (i < 10)
	{
		cin >> a >> b;
		rev_card(arr, a, b);
		i++;
	}
	print(arr);
	return (0);
}