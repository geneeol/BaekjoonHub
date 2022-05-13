#include <bits/stdc++.h>

using namespace std;

int	main(void)
{
	int	arr[3];
	int	i;

	i = -1;
	while (++i < 3)
		cin >> arr[i];
	if (arr[0] == arr[1] && arr[1] == arr[2])
		cout << 10000 + arr[0] * 1000;
	else if (arr[0] == arr[1] || arr[0] == arr[2])  
		cout << 1000 + arr[0] * 100;
	else if (arr[1] == arr[2])
		cout << 1000 + arr[1] * 100;
	else
		cout << *max_element(arr, arr + 3) * 100;
	return (0);
}