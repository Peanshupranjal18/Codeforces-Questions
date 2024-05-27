#include <bits/stdc++.h>
using namespace std;
#define intt long long

intt n, m;
vector<vector<intt>> adj;
vector<intt> vis;
vector<intt> cats;

intt dfs(intt node, intt cat_count)
{
    vis[node] = 1;

    if (cats[node] == 1)
    {
        cat_count++;
    }
    else
    {
        cat_count = 0;
    }

    if (cat_count > m)
    {
        return 0;
    }

    bool isLeaf = true;
    intt cnt = 0;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            isLeaf = false;
            cnt += dfs(it, cat_count);
        }
    }

    if (isLeaf)
    {
        return 1;
    }

    return cnt;
}

void solve()
{
    cin >> n >> m;

    cats.resize(n + 1);
    for (intt i = 1; i <= n; i++)
    {
        cin >> cats[i];
    }

    adj.resize(n + 1);
    for (intt i = 0; i < n - 1; i++)
    {
        intt a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vis.resize(n + 1, 0);

    intt ans = dfs(1, 0);
    cout << ans << "\n";
    return;
}

signed main()
{
    solve();
    return 0;
}