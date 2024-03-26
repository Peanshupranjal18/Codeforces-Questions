#include <bits/stdc++.h>
using namespace std;

int depth[300001];

void dfs(int node, vector<pair<int, int>> &left, vector<pair<int, int>> &right)
{
    if (left[node].first == 0 and right[node].first == 0)
        return;

    if (left[node].first != 0)
    {
        depth[left[node].first] = depth[node] + left[node].second;
        dfs(left[node].first, left, right);
    }

    if (right[node].first != 0)
    {
        depth[right[node].first] = depth[node] + right[node].second;
        dfs(right[node].first, left, right);
    }
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, int>> left(n + 1);
    vector<pair<int, int>> right(n + 1);
    vector<int> dp(n + 1, 0);

    memset(depth, sizeof(depth), 0);

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (s[i - 1] == 'L')
        {
            left[i] = {a, 0};
            right[i] = {b, 1};
        }
        else if (s[i - 1] == 'R')
        {
            left[i] = {a, 1};
            right[i] = {b, 0};
        }
        else
        {
            left[i] = {a, 1};
            right[i] = {b, 1};
        }

        if (a != 0 and b != 0)
            dp[i] += 2;
        if ((a == 0 and b != 0) or (a != 0 and b == 0))
            dp[i]++;
        dp[a]++;
        dp[b]++;
    }

    dfs(1, left, right);

    int ans = INT_MAX;

    for (int i = 2; i <= n; i++)
    {
        if (dp[i] == 1)
        {
            ans = min(ans, depth[i]);
        }
    }

    cout << ans << "\n";
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}