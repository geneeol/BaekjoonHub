#include <iostream>

using namespace std;

int	ft_dist(int N)
{
	int	bv;
	int	cnt;

	cnt = 1;
	bv = 1;
	//등호 신경쓸 것
	//cnt 값도 잘 따져줘야함
	while (N > bv)
	{
		bv += 6 * cnt;
		cnt++;
	}
	return (cnt);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;
	
	cin >> N;
	cout << ft_dist(N);
	return (0);
}