#include <bits/stdc++.h>
using namespace std;

struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first; // Sort by first element in increasing order
        }
        else
        {
            return a.second > b.second; // If first elements are equal, sort by second element in decreasing order
        }
    }
};

// Solve Function
void solve()
{
    int n, k;
    cin >> n >> k;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push({a, i + 1});
    }
    vector<int> ans;
    while (!pq.empty())
    {
        int x = pq.top().first - k;
        if (x <= 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        else
        {
            int y = pq.top().second;
            pq.pop();
            pq.push({x, y});
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

// Main Function
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}