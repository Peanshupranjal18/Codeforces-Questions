#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;

        vector<int> result;

        while (x > 0)
        {
            // Check the lowest bit
            if (x & 1)
            {
                result.push_back(1);
                x--;
            }
            else
            {
                result.push_back(0);
            }

            // Check if the next bit is set
            if (x & 2)
            {
                result.push_back(-1);
                x += 2;
            }

            // Shift x to the right
            x >>= 1;
        }

        // Output the result
        cout << result.size() << endl;
        for (int i = 0; i < result.size(); ++i)
        {
            if (i > 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;
    }

    return 0;
}
