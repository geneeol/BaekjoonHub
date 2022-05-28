#include <iostream>
#include <list>

using namespace std;

int	main(void)
{
	list <char> 	L;
	string		str;
	int		M;
	char		op;
	char		ch;

	cin >> str;
	for (char ch : str)
		L.push_back(ch);
	list <char>::iterator cur = L.end();
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> op;
		if (op == 'L')
		{
			if (cur != L.begin())
				cur--;
		}
		else if (op == 'D')
		{
			if (cur != L.end())
				cur++;
		}
		else if (op == 'B')
		{
			if (cur != L.begin())
				cur = L.erase(--cur); //L.erase(--cur) error
		}
		else if (op == 'P')
		{
			cin >> ch;
			L.insert(cur, ch);
		}
	}
	for (char ch : L)
		cout << ch;
	return (0);
}