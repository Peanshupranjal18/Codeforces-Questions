#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long lcm(long long a, long long b)
{
    return (a / __gcd(a, b)) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        unordered_set<long long> elements(a.begin(), a.end());
        int max_len = 0;

        for (int i = 0; i < n; ++i)
        {
            long long current_lcm = 1;
            for (int j = i; j < n; ++j)
            {
                current_lcm = lcm(current_lcm, a[j]);
                if (elements.find(current_lcm) == elements.end())
                {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        cout << max_len << '\n';
    }

    return 0;
}
