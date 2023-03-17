#include <bits/stdc++.h>

using namespace std;

int	n;
int	arr[105];
int	n_op[4];
int	freq_of_op[4];
int	_max = INT_MIN;
int	_min = INT_MAX;

void	solver(int depth, int sum)
{

	if (depth == n - 1)
	{
		if (sum > _max)
			_max = sum;
		if (sum < _min)
			_min = sum;
		return ;
	}
	if (freq_of_op[0] != n_op[0])
	{
		freq_of_op[0]++;
		solver(depth + 1, sum + arr[depth + 1]);
		freq_of_op[0]--;
	}
	if (freq_of_op[1] != n_op[1])
	{
		freq_of_op[1]++;
		solver(depth + 1, sum - arr[depth + 1]);
		freq_of_op[1]--;
	}
	if (freq_of_op[2] != n_op[2])
	{
		freq_of_op[2]++;
		solver(depth + 1, sum * arr[depth+ 1]);
		freq_of_op[2]--;
	}
	if (freq_of_op[3] != n_op[3])
	{
		freq_of_op[3]++;
		solver(depth + 1, sum / arr[depth + 1]);
		freq_of_op[3]--;
	}
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < 4; i++)
		cin >> n_op[i];
	solver(0, arr[0]);
	cout << _max << "\n";
	cout << _min;
}