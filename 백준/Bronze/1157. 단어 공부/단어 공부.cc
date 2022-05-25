#include <iostream>

using std::cin;
using std::cout;
using std::string;

int	occur[26];

int	is_lowercase(char ch)
{
	if ('a' <= ch && ch <= 'z')
		return (1);
	else
		return (0);
}

int	is_uppercase(char ch)
{
	if ('A' <= ch && ch <= 'Z')
		return (1);
	else
		return (0);
}

int	find_max_idx()
{
	int	i;
	int	max;
	int	idx_max;

	max = 0;
	for (i = 0; i < 26; i++)
	{
		if (occur[i] > max)
		{
			max = occur[i];
			idx_max = i;
		}
	}
	for (i = 0; i < 26; i++)
	{
		if (i == idx_max)
			continue ;
		if (occur[i] == max)
			return (-1);
	}
	return (idx_max);
}

int	main(void)
{
	string	str;
	int	idx_max;
	char	ch;

	cin >> str;
	for (auto ch : str)
	{
		if (is_lowercase(ch))
			occur[(int)ch - 'a']++;
		else if (is_uppercase(ch))
			occur[(int)ch - 'A']++;
	}
	idx_max = find_max_idx();
	ch = 'A' + idx_max;
	if (idx_max == -1)
		cout << '?';
	else
		cout << ch;
	return (0);
}