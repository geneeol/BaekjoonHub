#include <iostream>

using namespace std;

int	main(void)
{
	int	sum;
	int	min;
	int	i;
	int	input;

	sum = 0;
	min = 100;
	i = 0;
	while (i < 7)
	{
		cin >> input;
		if (input % 2 == 1)
		{
			sum += input;
			if (input < min)
				min = input;
		}
		i++;
	}
	if (sum == 0)
		cout << -1;
	else
	{
		cout << sum << '\n';
		cout << min;
	}
	return (0);
}