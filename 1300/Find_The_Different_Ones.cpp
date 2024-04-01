#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> p(n, -1);
    for (int i = 1; i < n; ++i)
    {
        p[i] = p[i - 1];
        if (a[i] != a[i - 1])
            p[i] = i - 1;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (p[r] < l)
            cout << "-1 -1\n";
        else
            cout << p[r] + 1 << " " << r + 1 << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
        if (i + 1 != t)
            cout << endl;
    }
    return 0;
}
