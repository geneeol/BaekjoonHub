#include <iostream>

using	namespace std;

int	is_prime(int nb)
{
	int	i;

	if (nb == 1)
		return (0);
	//in case of nb == 2 or 3, the if statement isn't needed
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	int	m;
	int	n;
	int	i;

	cin >> m >> n;

	while (m <= n)
	{
		if (is_prime(m))
			cout << m << '\n';
		m++;
	}
	return (0);
}