#include <bits/stdc++.h>
using namespace std;
#define intt long long

void solve()
{
    string s;
    cin >> s;
    intt n = s.length();
    intt cnt = 1;
    intt curr_length = 0;

    for (intt i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
            cnt++;
        if (s[i] == '0' and s[i + 1] == '1')
            curr_length = 1;
    }

    cout << cnt - curr_length << "\n";
    return;
}

signed main()
{
    intt tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}