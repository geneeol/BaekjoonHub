#include <iostream>

using std::cin;
using std::cout;

char	data[600500];
int	pre[600500];
int	nxt[600500];
int	unused;

void	insert(int addr, char ch)
{
	data[unused] = ch;
	pre[unused] = addr;
	nxt[unused] = nxt[addr];
	if (nxt[addr] != -1)
		pre[nxt[addr]] = unused;
	nxt[addr] = unused;
	unused++;
}

void	erase(int addr)
{
	nxt[pre[addr]] = nxt[addr];
	if (nxt[addr] != -1)
		pre[nxt[addr]] = pre[addr];
}

void	traverse(void)
{
	int	curr;

	curr = nxt[0]; //maybe error
	while (curr != -1)
	{
		cout << data[curr];
		curr = nxt[curr];
	}
}

int	main(void)
{
	//std::ios::sync_with_stdio(0);
	//cin.tie(0);

	int	cur;
	int	M;
	char	op;
	char	ch;
	std::string	str;

	cur = 0;
	std::fill(pre, pre + 600500, -1);
	std::fill(nxt, nxt + 600500, -1);
	unused = 1;

	cin >> str;
	for (char ch : str)
	{
		insert(cur, ch);
		cur++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> op;
		if (op == 'L')
		{
			if (pre[cur] != -1)
				cur = pre[cur]; //cur-- 하면 삭제 후 새로 연결하는 지점에서 에러
		}
		else if (op == 'D')
		{
			if (nxt[cur] != -1)
				cur = nxt[cur]; //cur++ 위와 동일
		}
		else if (op == 'B')
		{
			if (pre[cur] != -1)
			{
				erase(cur); 
				cur = pre[cur];
			}
		}
		else if (op == 'P')
		{
			cin >> ch;
			insert(cur, ch);
			cur = nxt[cur]; // 커서가 아직 새 원소에 놓이지 않음. 따라서 커서를 옮겨야 함(주소상으로 unused로)
		}
	}
	traverse();
	return (0);
}