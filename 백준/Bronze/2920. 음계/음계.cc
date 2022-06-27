#include <iostream>

using namespace std;

int	note[8];

int	main(void)
{
	int	status;

	status = 0;
	for (int i = 0; i < 8; i++)
		cin >> note[i];
	for (int i = 0; i < 7; i++)
	{
		if (note[i] < note[i + 1])
		{
			if (status == 2)
			{
				cout << "mixed";
				return (0);
			}
			status = 1;
		}
		else if (note[i] > note[i + 1])
		{
			if (status == 1)
			{
				cout << "mixed";
				return (0);
			}
			status = 2;
		}
	}
	if (status == 1)
		cout << "ascending";
	else if (status == 2)
		cout << "descending";
	return (0);
}