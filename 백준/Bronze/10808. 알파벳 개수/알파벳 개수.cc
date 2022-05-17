#include <bits/stdc++.h>

using namespace std;

int	alpha_cnt[255];

int	main(void)
{
	string	str;
	cin >> str;
	for (auto c : str) 
		alpha_cnt[c]++;
	for (char ch = 'a' ; ch <= 'z'; ch++)
		cout << alpha_cnt[ch] << ' ';
	return (0);
}