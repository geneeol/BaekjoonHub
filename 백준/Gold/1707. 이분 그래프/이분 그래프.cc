#include <bits/stdc++.h>

using namespace std;

int	k, nv, ne;
vector<int>	edges[20005];
int			color[20005];
vector<int>	all_v;
bool		is_bipartite;

bool	bipartite_graph(int cur)
{
	for (auto &nxt: edges[cur])
	{
		if (color[nxt] == 0)
		{
			color[nxt] = 3 - color[cur];
			if (bipartite_graph(nxt) == false)
				return (false);
		}
		else if (color[nxt] == color[cur])
		{
			is_bipartite = false;
			return (false);
		}
	}
	return (true) ;
}

int	main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int	v1, v2;

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> nv >> ne;
		is_bipartite = true;
		for (int i = 1; i <= ne; i++)
		{
			cin >> v1 >> v2;
			edges[v1].push_back(v2);
			edges[v2].push_back(v1);
			all_v.push_back(v1);
			all_v.push_back(v2);
		}

		for (auto &v : all_v)
		{
			if (color[v] == 0)
			{
				color[v] = 1; 
				// 방향 그래프라면 무작정 1로 초기화 하면 안됨. 인접한 녀석을 따져야함.
				// 그냥 무방향 그래프로 가정하고 풀었어야 되네 아...
				bipartite_graph(v);
			}
			if (is_bipartite == false)
				break ;
		}
		if (is_bipartite)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";

		for (auto &v: all_v)
			edges[v].clear();
		all_v.clear();
		memset(color, 0, sizeof(color));
	}
	return (0);
}