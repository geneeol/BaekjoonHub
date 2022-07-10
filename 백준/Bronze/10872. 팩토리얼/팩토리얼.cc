#include <iostream>

using namespace std;

int	main(void)
{
	int	N;
	int	fct;

	cin >> N;
	fct = 1;
	for (int i = 1; i <= N; i++)
		fct *= i;
	cout << fct;
	return (0);
}