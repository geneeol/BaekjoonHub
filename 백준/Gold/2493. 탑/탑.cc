#include <bits/stdc++.h>

using namespace std;

int	main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	N;
	int	height;
	stack<pair<int, int>>	stk;; //왜 탭인데 위 아래 간격이 달라보이지?
								   //list, stack끼리는 같은 간격으로 들여쓰기 됨. vector는 들여쓰기시 간격이 다르더라

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> height;
		//스택내 원소의 높이가 height보다  높을 때까지 계속 pop
		//만약 스택이 비게 되면 현재 탑은 다른 탑에 닿지 않음
		//스택에는 항상 오름차순으로 값이 쌓이게 됨
		while (!stk.empty() && stk.top().first < height) //연산자 순서 중요함
			stk.pop();
		if (stk.empty())
			cout << "0 ";
		else
			cout << stk.top().second << ' ';
		stk.push(make_pair(height, i));
	}
	return (0);
}