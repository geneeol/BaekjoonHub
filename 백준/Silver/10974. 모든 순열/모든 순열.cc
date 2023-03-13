#include <bits/stdc++.h>

using namespace std;

int		arr[10];
bool	is_used[10];
int		len;

void	perm_generator(int idx)
{
	if (idx == len)
	{
		for (int i = 0; i < len; i++)
			cout << arr[i] << ' ';
		cout << "\n";
		return ;
	}
	for (int num = 0; num < len; num++)
	{
		if (is_used[num])
			continue ;
		is_used[num] = true;
		arr[idx] = num + 1;
		perm_generator(idx + 1);
		is_used[num] = false;
	}

}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> len;
	perm_generator(0);
}