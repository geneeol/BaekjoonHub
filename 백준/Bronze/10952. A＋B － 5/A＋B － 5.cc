#include <iostream>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int	A;
	int B;

	while (1)
	{
		cin >> A >> B;
		if (A == 0 && B == 0)
			return (0);
		cout << A + B << '\n';
	}
	return (0);
}