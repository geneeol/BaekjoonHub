#include <iostream>

using namespace std;

int	main(void)
{
	int	mat_a[100][100];
	int	mat_b[100][100];
	int	N;
	int	M;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M ; j++)
			cin >> mat_a[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M ; j++)
			cin >> mat_b[i][j];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M ; j++)
			cout << mat_a[i][j] + mat_b[i][j] << ' ';
		cout << '\n';
	}
	return (0);
}