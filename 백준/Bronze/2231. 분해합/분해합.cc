#include <iostream>

using namespace std;

int	decompose_sum(int nb)
{
	int	sum;

	sum = nb;
	while (nb)
	{
		sum += nb % 10;
		nb /= 10;
	}
	return (sum);
}

int	find_gen(int n)
{
	for (int i = 1; i < n; i++)
	{
		if (n == decompose_sum(i))
			return (i);
	}
	return (0);
}

int	main(void)
{
	int	N;
	int	ans;

	cin >> N;
	ans = find_gen(N);
	cout << ans;
	return (0);
}