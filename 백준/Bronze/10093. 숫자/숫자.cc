#include <bits/stdc++.h>

using	namespace std;

int	main(void)
{
	long long	A;
	long long	B;

	cin >> A >> B;
	if (B > A)
	{
		cout << B - A - 1 << '\n';
		while (++A < B)
			cout << A << ' ';
	}
	else if (A > B)
	{
		cout << A - B - 1 << '\n';
		while (++B < A)
			cout << B << ' ';
	}
	else
		cout << 0;
	return (0);
}