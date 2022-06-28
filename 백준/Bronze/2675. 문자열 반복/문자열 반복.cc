#include <iostream>
#include <string>

using namespace std;

int	main(void)
{
	int	T;
	int	R;
	string	str;
	string	print;

	cin >> T;
	while (T--)
	{
		cin >> R;
		cin >> str;
		print.clear();
		for (auto ch : str)
			for (int i = 0; i < R; i++)
				print += ch;
		cout << print << '\n';
	}
	return (0);
}