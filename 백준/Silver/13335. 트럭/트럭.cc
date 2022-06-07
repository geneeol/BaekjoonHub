#include <bits/stdc++.h>

using namespace std;

//고민... 어렵네 실버1 맞나 ㅠ
//접근 자체를 이상하게 함
//큐에 0인 원소를 푸쉬하는 아이디어!
//
//코드 진짜 개더러움

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int>	on_brg;
	vector<int>	truck;
	int	n;
	int	w;
	int	L;
	int	total;
	int	ans;
	int	i;

	i = 0;
	total = 0;
	ans = 0;
	cin >> n >> w >> L;
	truck.resize(n);
	for (int i = 0; i < n; i++)
		cin >> truck[i];
	while (1)
	{
		while ((int)on_brg.size() < w && truck[i] + total <= L && i < n)
		{
			total += truck[i];
			on_brg.push(truck[i++]);
			ans++;
		}
		if (i == n)
		{
			ans += w; //아무 생각없이 다리 길이만큼 더해주면 끝!
					  //현재 맨 끝에 마지막 차가 있으므로
			break ;
		}
		while ((int)on_brg.size() < w)
		{
			on_brg.push(0);
			ans++;
		}
		total -= on_brg.front();
		on_brg.pop();
	}
	cout << ans;
	return (0);
}