#include <iostream>

using namespace std;

int	main(void)
{
	int	H, M;
	
	cin >> H >> M;
	if (M >= 45)
		cout << H << ' ' << M - 45;
	else
	{
		if (H == 0)
			cout << 23 << ' ' << 60 - 45 + M;
		else
			cout << --H << ' ' << 60 - 45 + M;
	}
	return (0);
}