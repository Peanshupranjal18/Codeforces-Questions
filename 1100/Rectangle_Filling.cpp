#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        bool rowUniform = true;
        bool colUniform = true;

        // Check if the first row is uniform
        for (int i = 1; i < m; i++)
        {
            if (v[0][i] != v[0][0])
            {
                rowUniform = false;
                break;
            }
        }

        // Check if the last row is uniform
        for (int i = 1; i < m; i++)
        {
            if (v[n - 1][i] != v[n - 1][0])
            {
                rowUniform = false;
                break;
            }
        }

        // Check if the first column is uniform
        for (int i = 1; i < n; i++)
        {
            if (v[i][0] != v[0][0])
            {
                colUniform = false;
                break;
            }
        }

        // Check if the last column is uniform
        for (int i = 1; i < n; i++)
        {
            if (v[i][m - 1] != v[0][m - 1])
            {
                colUniform = false;
                break;
            }
        }

        // If all borders are uniform, and the top-left and bottom-right corners are different, it's a "NO"
        if (rowUniform && v[0][0] != v[n - 1][m - 1])
        {
            cout << "NO" << endl;
        }
        else if (colUniform && v[0][0] != v[n - 1][m - 1])
        {
            cout << "NO" << endl;
        }

        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}