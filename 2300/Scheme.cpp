#include <bits/stdc++.h>
using namespace std;

// connecting the strongly connected components with each other

const int N = 1e5 + 5;

int n, i, x, s, t, to[N], r[N], q1[N], q2[N], f[N];

int dfs(int x)
{
    // visiting
    f[x] = 1;
    if (!f[to[x]])
        return f[x] = dfs(to[x]);
    return f[x] = x;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        // kis person ko current ith person ko batana hai
        cin >> to[i];
        // r uss person ka indegree hai
        r[to[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        // no incoming edges
        if (!r[i])
        {
            // q1 means the ending node
            q1[s] = dfs(i);
            // starting node
            q2[s++] = i;
            // s will give the total count of edges
        }
    }
    t = s;
    for (int i = 1; i <= n; i++)
    {
        if (!f[i])
        {
            q1[s] = dfs(i);
            q2[s++] = i;
        }
    }
    if (s == 1 and !t)
        s = 0;
    cout << s << "\n";
    for (int i = 0; i < s; i++)
        cout << q1[i] << " " << q2[(i + 1) % s] << "\n";
    return 0;
}