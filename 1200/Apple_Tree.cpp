#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1000000007
#define f(i, n) for (intt i = 0; i < n; i++)
#define ff(i, a, b) for (intt i = a; i < b; i++)
#define pb push_back
#define ii pair<intt, intt>
#define vi vector<intt>
#define vvi vector<vector<intt>>
#define vpi vector<pair<intt, intt>>
#define fi first
#define sec second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define minv *min_element
#define maxv *max_element
#define rt return
#define um unordered_map
#define acc accumulate
#define sz(x) x.size()
#define ub upper_bound
#define lb lower_bound
#define mt multiset
#define rs resize
#define mah priority_queue<intt>
#define mih priority_queue<intt, vector<intt>, greater<intt>>
#define mahp priority_queue<pair<intt, intt>>
#define mihp priority_queue<pair<intt, intt>, vector<pair<intt, intt>>, greater<pair<intt, intt>>>
using namespace std;
using namespace __gnu_pbds;

// Right Left Up Down
intt dx[] = {0, 0, 1, -1};
intt dy[] = {1, -1, 0, 0};
// intt a, b, n, m;

// bool possible(int x, int y)
// {
//     return (x < n && x >= 0 && y < m && y >= 0);
// }

vi v, v1, v2, v3, v4;
vi dp(200001);

bool isPrime(intt n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (intt i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

// oset<int>s:s.find_by_order(k):Kth element in s,s.order_of_key(k):Number of item strictly lessthan k
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const intt maxN = 2e5 + 5;
vvi adj;
intt cnt[maxN];

void dfs(intt node, intt parent)
{
    if (adj[node].size() == 1 and adj[node][0] == parent)
    {
        cnt[node] = 1;
    }
    else
    {
        for (auto it : adj[node])
        {
            if (it != parent)
            {
                dfs(it, node);
                // root mein children ka value jodne ka tarika
                cnt[node] += cnt[it];
            }
        }
    }
}

void solve()
{
    intt n, m;
    cin >> n;
    adj.assign(n, vector<intt>());
    for (intt i = 0; i < n - 1; i++)
    {
        intt a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(cnt, 0, sizeof(cnt));
    dfs(0, -1);

    cin >> m;
    f(i, m)
    {
        intt x, y;
        cin >> x >> y;
        x--;
        y--;
        intt res = cnt[x] * cnt[y];
        cout << res << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    intt tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}
