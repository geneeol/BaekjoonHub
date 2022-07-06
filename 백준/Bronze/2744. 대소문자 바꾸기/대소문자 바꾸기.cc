#include <iostream>

using namespace std;

int	is_uppercase(char ch)
{
	if ('A' <= ch && ch <= 'Z')
		return (1);
	else
		return (0);
}

int	main(void)
{
	int		diff;
	string	str;
	
	diff = 'a' - 'A';
	cin >> str;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (is_uppercase(str[i]))
			str[i] += diff;
		else
			str[i] -= diff;
	}
	cout << str;
	return (0);
}