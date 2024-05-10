#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) implementation with path compression and union by rank
class DSU
{
    vector<int> par;
    vector<int> rank;

public:
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == par[node])
            return node;
        // Path compression
        return par[node] = findPar(par[node]);
    }

    void unionn(int a, int b)
    {
        a = findPar(a);
        b = findPar(b);

        if (a != b)
        {
            if (rank[a] > rank[b])
            {
                par[b] = a;
            }
            else
            {
                par[a] = b;
                if (rank[a] == rank[b])
                    rank[b]++;
            }
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> edges(m);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {{a - 1, b - 1}, c}; // Assuming 1-based indexing in input
    }

    int ans = 0;

    // Use a mask with all bits set to 1
    int ones = -1; // or 0xFFFFFFFF, equivalent to all bits set

    for (int bit = 31; bit >= 0; bit--)
    {
        DSU d(n);
        int cnt = 0;

        for (auto &x : edges)
        {
            int weight = x.second;
            int u = x.first.first, v = x.first.second;

            // This part is the intended behavior to keep certain bits fixed
            int maskedWeight = weight & (ones << bit);
            int orr = ans | maskedWeight;

            if (orr != ans) // Not a valid edge due to the modified mask
                continue;

            if (d.findPar(u) == d.findPar(v))
            {
                continue;
            }

            cnt++;
            d.unionn(u, v);
        }

        if (cnt != n - 1) // If it's not a spanning tree, set the bit
        {
            ans |= (1 << bit);
        }
    }

    cout << ans << "\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}