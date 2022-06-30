#include <iostream>

using namespace std;

int	ft_idx(char ch, string& str)
{
	for (int i = 0; i < (int)str.length(); i++)
		if (str[i] == ch)
			return (i);
	return (-1);
}

int	main(void)
{
	string	str;

	cin >> str;
	for (char ch = 'a'; ch <= 'z'; ch++)
		cout << ft_idx(ch, str) << ' ';
	return (0);
}