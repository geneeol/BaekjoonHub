#include <bits/stdc++.h>

using namespace std;

void hex_to_int(string &password, int len, int idx)
{
    long long ans = 0;

    for (int i = 0; i < len; i++)
    {
        ans *= 16;
        if ('0' <= password[idx] && password[idx] <= '9')
            ans += password[idx] - '0';
        else
            ans += 10 + password[idx] - 'a';
        idx++;
    }
    cout << ans << ' ';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string password;
    string format;
    int n;
    int len;
    int idx = 0;

    cin >> password >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> format;
        if (format == "char")
            len = 2;
        else if (format == "int")
            len = 8;
        else if (format == "long_long")
            len = 16;
        else
            len = -1;
        hex_to_int(password, len, idx);
        idx += len;
    }
}