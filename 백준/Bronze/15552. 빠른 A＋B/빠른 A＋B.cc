#include <bits/stdc++.h>

using	namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	T;
	int	A;
	int	B;
	int	i;

	cin >> T;
	i = 0;
	while (i < T)
	{
		cin >> A >> B;
		cout << A + B << '\n';
		i++;
	}
	return (0);
}