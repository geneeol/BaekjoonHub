#include <bits/stdc++.h>

using std::cin;
using std::cout;

int	freq[10];

int	main(void)
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int	a;
	int	b;
	int	c;
	int	num;
	int	i;

	cin >> a >> b >> c;
	num = a * b * c;
	while (num)
	{
		freq[num % 10]++;
		num /= 10;
	}
	i = 0;
	while (i < 10)
	{
		cout << freq[i] << '\n';
		i++;
	}
	return (0);
}