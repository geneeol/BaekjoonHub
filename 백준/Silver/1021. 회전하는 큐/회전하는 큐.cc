#include <iostream>
#include <deque>

using namespace std;

//어차피 an과 an-1 간격은 원형큐에서 일정함
//따라서 매번 각 원소를 최단시간내에 뽑아내면 됨(한 단계씩 끊어서 최선을 찾으면 됨)
//인덱스를 사용해야한다는 생각을 못했음..
//

int	ft_idx(deque<int> &deq, int num)
{
	int	i;
	
	i = 0;
	while (deq[i] != num)
		i++;
	return (i);
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	deque<int>	deq;
	int	N;
	int	M;
	int	cnt;
	int	num;
	unsigned int	idx;

	cnt = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		deq.push_back(i);
	while (M--)
	{
		cin >> num;
		idx = ft_idx(deq, num);
		if (2 * idx >= deq.size())
		{
			while (deq.front() != num)
			{
				deq.push_front(deq.back());
				deq.pop_back();
				cnt++;
			}
		}
		else
		{
			while (deq.front() != num)
			{
				deq.push_back(deq.front());
				deq.pop_front();
				cnt++;
			}
		}
		deq.pop_front();
	}
	cout << cnt;
	return (0);
}