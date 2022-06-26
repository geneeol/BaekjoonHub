#include <iostream>

using namespace std;

int	ft_score(string str)
{
	int	sum;
	int	tmp;

	sum = 0; 
	for (int i = 0; i < (int)str.length(); i++)
	{
		tmp = 1;
		while (str[i] == 'O' && i < (int)str.length())
		{
			sum += tmp;
			tmp++;
			i++;
		}
	}
	return (sum);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string	str;
	int	T;

	cin >> T;
	while (T--)
	{
		cin >> str;
		cout << ft_score(str) << '\n';
	}
	return (0);
}