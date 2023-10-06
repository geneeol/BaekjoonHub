#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    int flag, score, time;
    stack<pair<int, int>> stk;
    pair<int, int> work;
    int total = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> score >> time;
            stk.push(make_pair(score, time));
        }
        if (!stk.empty())
        {
            stk.top().second -= 1;
            work = stk.top();
            if (work.second == 0)
            {
                total += work.first;
                stk.pop();
            }
        }
    }
    cout << total;
}