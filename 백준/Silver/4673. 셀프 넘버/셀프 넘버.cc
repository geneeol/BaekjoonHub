#include <iostream>

using namespace std;

int	ft_gen(int n)
{
	int	ret;

	ret = n;
	while (n)
	{
		ret += n % 10;
		n /= 10;
	}
	return (ret);
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	table[10500];
	int	i;

	fill(table, table + 10500, 0);
	i = 1;
	while (i <= 10000)
	{
		table[ft_gen(i)] = 1;
		i++;
	}
	i = 1;
	while (i <= 10000)
	{
		if (!table[i])
			cout << i << '\n';
		i++;
	}
	return (0);
}