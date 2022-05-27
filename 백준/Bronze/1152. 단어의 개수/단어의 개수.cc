#include <iostream>

using namespace std;

int	is_space(char ch)
{
	if (ch == ' ')
		return (1);
	else
		return (0);
}

int	main(void)
{
	int	i;
	int	word_cnt;
	string str;

	word_cnt = 0;
	getline(cin, str);
	for (i = 0; i < str.length(); i++)
	{
		if (!is_space(str[i]))
		{
			word_cnt++;
			while (!is_space(str[i]) && i < str.length())
				i++;
		}
	}
	cout << word_cnt;
	return (0);
}