#include <iostream>

using namespace std;

int	main(void)
{
	int	N;
	int	X;
	int	tmp;

	cin >> N >> X;
	while (N)
	{
		cin >> tmp;
		if (tmp < X)
			cout << tmp << ' ';
		N--;
	}
	return (0);
}