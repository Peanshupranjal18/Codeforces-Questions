#include <bits/stdc++.h>
#define intt long long int
#define ll long long
#define ld long double
#define MOD 1e9 + 7
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int y = max(a, b);
        int z = max(c, d);

        if ((c > y and c != z) or (d > y and d != z))
            cout << "NO"
                 << "\n";
        else if ((a > z and a != y) or (b > z and b != y))
            cout << "NO"
                 << "\n";
        else
            cout << "YES"
                 << "\n";
    }
    return 0;
}