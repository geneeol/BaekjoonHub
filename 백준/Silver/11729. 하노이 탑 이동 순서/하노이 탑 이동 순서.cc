#include <bits/stdc++.h>

using namespace std;

int	n;

void	move_disk(int from, int to, int n_disk)
{
	if (n_disk == 1)
	{
		cout << from << ' ' << to;
		cout << "\n";
		return ;
	}
	move_disk(from, 6 - from - to, n_disk - 1);
	cout << from << ' ' << to << "\n";
	move_disk(6 - from - to, to, n_disk - 1);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	cout << (1 << n) - 1 << "\n";
	move_disk(1, 3, n);
	return (0);
}