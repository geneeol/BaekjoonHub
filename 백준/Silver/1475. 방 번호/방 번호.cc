#include <bits/stdc++.h>

using std::cin;
using std::cout;

int	main(void)
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	int	freq[10] = {};
	int	N;
	int	i;
	int	max;
	int	sp;

	cin >> N;
	max = 0;
	while (N)
	{
		freq[N % 10]++;
		N /= 10;
	}
	sp = freq[6] + freq[9];
	i = -1;
	while (++i < 10)
	{
		if (i == 6 || i == 9)
			continue ;
		if (freq[i] > max)
			max = freq[i];
	}
	cout << std::max(max, sp / 2 + sp % 2);
	return (0);
}