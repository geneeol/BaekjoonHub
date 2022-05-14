#include <bits/stdc++.h>

using	namespace std;

int	main(void)
{
	int	N;
	int	ys;
	int	ms;
	int	arr[25];
	int	i;

	ys = 0;
	ms = 0;
	cin >> N;
	i = 0;
	while (i < N)
	{
		cin >> arr[i];
		i++;
	}
	i = 0;
	while (i < N)
	{
		ys += (arr[i] / 30 + 1) * 10;
		ms += (arr[i] / 60 + 1) * 15;
		i++;
	}
	if (ys == ms)
		cout << "Y " << "M " << ys;
	else if (ys > ms)
		cout << "M " << ms;
	else
		cout << "Y " << ys;
	return (0);
}