#include <bits/stdc++.h>

using namespace std;


int	solver(int n, int r, int c)
{
	int	half;

	if (n == 0)
		return (0);
	half = 1 << (n - 1);
	if (r < half && c < half)
		return (solver(n - 1, r, c));
	if (r < half && c >= half)
		return (half * half + solver(n - 1, r, c - half));
	if (r >= half && c < half)
		return (2 * half * half + solver(n - 1, r - half, c));
	return (3 * half * half + solver(n - 1, r - half, c - half));
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	n, r, c;

	cin >> n >> r >> c;
	cout << solver(n, r, c);
	return (0);
}