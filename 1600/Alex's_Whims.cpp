#include <bits/stdc++.h>

using namespace std;
#define _test     \
    int _TEST;    \
    cin >> _TEST; \
    while (_TEST--)

int main()
{
    _test
    {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i < n; i++)
            cout << i << " " << i + 1 << "\n";

        int con = n - 1;

        while (q--)
        {
            int d;
            cin >> d;

            if (con == d)
                cout << "-1 -1 -1\n";
            else
            {
                cout << n << " " << con << " " << d << "\n";
                con = d;
            }
        }
    }
}