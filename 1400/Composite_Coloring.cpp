#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> color = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        int frq[11] = {0};
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            for (int j = 0; j < 11; j++)
            {
                if (v[i] % color[j] == 0)
                {
                    if (!frq[j])
                        frq[j] = ++cur;
                    v[i] = frq[j];
                    break;
                }
            }
        }
        cout << cur << endl;
        for (int i = 0; i < n; i++)
            cout << v[i] << " \n"[i == n - 1];
    }
    return 0;
}