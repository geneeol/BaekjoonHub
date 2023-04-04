#include <bits/stdc++.h>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int	q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		unsigned long long	a, b;
		cin >> a >> b;
		if (b % a == 0 && b != a)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
	return (0);
}