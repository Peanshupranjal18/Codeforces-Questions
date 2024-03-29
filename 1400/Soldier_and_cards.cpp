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
intt a, b, n, m, k1, k2;

bool possible(int x, int y)
{
    return (x < n && x >= 0 && y < m && y >= 0);
}

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

void solve()
{
    cin >> n;
    cin >> k1;
    v.rs(k1);
    f(i, k1) cin >> v[i];
    cin >> k2;
    v1.rs(k2);
    f(i, k2) cin >> v1[i];

    deque<intt> q1, q2;

    f(i, k1) q1.push_front(v[i]);
    f(i, k2) q2.push_front(v1[i]);

    deque<intt> q3(all(q1));
    deque<intt> q4(all(q2));

    intt cnt = 0;

    while (true)
    {
        if (q1.back() < q2.back())
        {
            q2.push_front(q1.back());
            q2.push_front(q2.back());
            q1.pop_back();
            q2.pop_back();
            cnt++;

            if (q1 == q3 and q2 == q4)
            {
                cout << -1;
                rt;
            }

            if (q1.empty())
            {
                cout << cnt << " " << 2;
                rt;
            }
        }
        else
        {
            q1.push_front(q2.back());
            q1.push_front(q1.back());
            q2.pop_back();
            q1.pop_back();
            cnt++;

            if (q1 == q3 and q2 == q4)
            {
                cout << -1;
                rt;
            }

            if (q2.empty())
            {
                cout << cnt << " " << 1;
                rt;
            }
        }
        if (cnt > 1000)
        {
            cout << -1;
            rt;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // intt tc;cin>>tc;while(tc--)
    solve();
    return 0;
}