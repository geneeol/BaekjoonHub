#include <bits/stdc++.h>

using namespace std;

int	is_used[10];
int	arr[10];
int	n, m;

void	perm_generator(int depth)
{
	if (depth == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		if (is_used[i])
			continue ;
		arr[depth] = i + 1;
		is_used[i] = true;
		perm_generator(depth + 1);
		is_used[i] = false;
	}

}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	perm_generator(0);
}