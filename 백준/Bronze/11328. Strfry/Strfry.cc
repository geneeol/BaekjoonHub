#include <iostream>

using namespace std;

int	main(void)
{
	int	N;
	int	arr[26];
	bool	possible;
	string	str1;
	string	str2;

	cin >> N;
	while (N)
	{
		fill(arr, arr + 26, 0);
		cin >> str1 >> str2;
		for (auto c : str1)
			arr[c - 'a']++;
		possible = true;
		for (auto c : str2)
			arr[c - 'a']--;
		for (auto i : arr)
		{
			if (i != 0) 
				possible = false;
		}
		if (possible)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
		N--;
	}
	return (0);
}