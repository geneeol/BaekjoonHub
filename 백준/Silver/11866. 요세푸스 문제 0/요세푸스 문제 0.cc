#include <iostream>
#include <list>

using std::cout;
using std::cin;

int	data[5050];
int	prev[5050];
int	next[5050];

int	main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;
	int	K;
	int	curr;
	int	arr[5005];

	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		prev[i] = (i == 1) ? N : i - 1;
		next[i] = (i == N) ? 1 : i + 1;
	}
	curr = 1;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < K - 1; j++)
			curr = next[curr];
		arr[i] = curr;
		next[prev[curr]] = next[curr];
		prev[next[curr]] = prev[curr];
		curr = next[arr[i]];
	}
	cout << '<';
	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			cout <<", ";
		cout << arr[i];
	}
	cout << '>';
	return (0);
}