#include <iostream>
#include <cmath>

using namespace std;

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int	arr1[26];
	int	arr2[26];
	int	i;
	int	cnt;
	string	str1;
	string	str2;

	fill(arr1, arr1 + 26, 0);
	fill(arr2, arr2 + 26, 0);
	cnt = 0;
	cin >> str1 >> str2;
	for (auto ch : str1)
		arr1[ch - 'a']++;
	for (auto ch : str2)
		arr2[ch - 'a']++;
	for (i = 0; i < 26; i++)
		cnt += abs(arr1[i] - arr2[i]);
	cout << cnt;
	return (0);
}