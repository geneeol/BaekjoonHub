#include <iostream>

using namespace std;

int	main(void)
{
	int	num;
	int	max;
	int	idx;

	max = 0;
	for (int i = 1; i <= 9; i++)
	{
		cin >> num;
		if (num > max)
		{
			max = num;
			idx = i;
		}
	}
	cout << max << '\n';
	cout << idx;
	return (0);
}