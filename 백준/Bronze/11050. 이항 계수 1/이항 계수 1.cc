#include <bits/stdc++.h>

using namespace std;

int	comb(int n, int k)
{
	int	ret;

	ret = 1;
	for (int i = n - k + 1; i <= n; i++)
		ret *= i;
	for (int i = 1; i <= k; i++)
		ret /= i;
	return (ret);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	n, k;

	cin >> n >> k;
	cout << comb(n, k);
}