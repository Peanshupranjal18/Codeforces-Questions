#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 10;

struct dsu
{
    vector<int> p, s;
    void init(int n)
    {
        p = vector<int>(n);
        iota(p.begin(), p.end(), 0);
        s = vector<int>(n, 1);
    }

    dsu(int n)
    {
        init(n);
    }

    int find_set(int x)
    {
        return x == p[x] ? x : p[x] = find_set(p[x]);
    }

    bool union_sets(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);

        if (u == v)
        {
            return false;
        }

        if (s[u] < s[v])
        {
            swap(u, v);
        }

        s[u] += s[v];
        s[v] = 0;
        p[v] = u;
        return true;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    dsu d(n);

    int not_used = 0;
    for (int i = 0; i < q; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (d.union_sets(x - 1, y - 1) == false)
        {
            ++not_used;
        }
        vector<int> comps = d.s;
        sort(comps.rbegin(), comps.rend());
        cout << accumulate(comps.begin(), comps.begin() + not_used + 1, 0LL) - 1 << '\n';
    }
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1; // cin >> T;
    for (int _ = 0; _ < T; ++_)
    {
        solve();
    }
}
