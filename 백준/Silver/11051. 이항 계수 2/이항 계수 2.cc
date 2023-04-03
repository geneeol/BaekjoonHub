#include <bits/stdc++.h>

using namespace std;

const int	divisor = 10007;
int			combs[1005][1005];

void	init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (i == j || j == 0)
				combs[i][j] = 1;
			else
				combs[i][j] = (combs[i - 1][j] + combs[i - 1][j - 1]) % divisor;
			//printf("(%d, %d): %d\n", i, j, combs[i][j]);
		}
	}
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	n, k;

	cin >> n >> k;
	init(n);
	cout << combs[n][k];
}