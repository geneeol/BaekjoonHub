#include <bits/stdc++.h>

typedef long long uint64;

using namespace std;

uint64	power_and_modulo(uint64 base, uint64 exp, uint64 divisor)
{
	uint64	res;

	if (exp == 0)
		return 1;
	if (exp % 2 == 0)
	{
		res = power_and_modulo(base, exp / 2, divisor);
		return (res * res) % divisor;
	}
	return ((power_and_modulo(base, exp - 1, divisor) * base)) % divisor;
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	a, b, c;

	cin >> a >> b >> c;
	cout << power_and_modulo(a, b, c);
}