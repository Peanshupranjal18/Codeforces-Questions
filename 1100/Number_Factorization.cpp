#include <bits/stdc++.h>
using namespace std;
#define intt long long

void primeFactors(intt n, vector<intt> &v)
{
    while (n % 2 == 0)
    {
        v.push_back(2);
        n = n / 2;
    }

    for (intt i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        v.push_back(n);
}

void solve()
{
    intt n;
    cin >> n;

    vector<intt> v;
    primeFactors(n, v);

    // sahi

    vector<intt> v1(100001, 0);

    for (intt i = 0; i < v.size(); i++)
        v1[v[i]]++;

    intt a = LLONG_MAX;

    for (intt i = 0; i < v1.size(); i++)
    {
        if (v1[i] != 0)
        {
            a = min(a, v1[i]);
        }
    }

    intt prod = 1;

    for (intt i = 0; i < v1.size(); i++)
    {
        if (v1[i] == 0)
            continue;
        else
        {
            prod *= i;
            v1[i] -= a;
        }
    }

    intt ans = 0;

    for (intt i = 0; i < v1.size(); i++)
    {
        ans += v1[i] * i;
    }

    ans += prod * a;

    cout << ans << "\n";
}

int32_t main()
{
    intt tc;
    cin >> tc;
    while (tc--)
        solve();
    return 0;
}