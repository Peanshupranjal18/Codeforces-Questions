#include <bits/stdc++.h>
using namespace std;

void solve()
{
    // m is a power of 2
    // n = 2 -> 0 1 2 layer
    int m;
    cin >> m;
    // sorting the leaves of the complete binary tree

    vector<int> v(m);

    for (int i = 0; i < m; i++)
        cin >> v[i];

    int cnt = 0;
    int j = 1;

    for (int i = 0; i < m - 1; i += 2)
    {
        if (v[i] > v[i + j])
        {
            swap(v[i], v[i + j]);
            cnt++;
        }
    }
}

int32_t main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}