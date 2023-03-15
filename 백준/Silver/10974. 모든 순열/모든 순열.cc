#include <bits/stdc++.h>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	arr[10] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	n;

	cin >> n;
	do
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << "\n";
	} while (next_permutation(arr, arr + n));
}