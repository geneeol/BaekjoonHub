#include <iostream>
#include <algorithm>
#include <cmath>

using std::cin;
using std::cout;

int	main(void)
{
	int	leg[3];
	while (1)
	{
		cin >> leg[0] >> leg[1] >> leg[2];
		std::sort(leg, leg + 3);
		if (leg[2] == 0)
			break ;
		if (pow(leg[2], 2)  == pow(leg[0], 2) + pow(leg[1], 2))
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return (0);
}