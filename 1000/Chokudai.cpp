#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int solution(int i, int j, const string &s, const string &t, int n, vector<vector<int>> &dp)
{
    if (j == 8) // If all characters in "chokudai" are matched
        return 1;
    if (i == n) // If we have reached the end of string S
        return 0;

    // If the current characters match, we have two choices: either include or exclude it
    int &res = dp[i][j];
    if (res != -1)
        return res;

    res = solution(i + 1, j, s, t, n, dp); // Exclude the current character

    if (s[i] == t[j]) // If characters match, include the current character
        res = (res + solution(i + 1, j + 1, s, t, n, dp)) % MOD;

    return res;
}

// Solve Function
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    string t = "chokudai";
    vector<vector<int>> dp(n, vector<int>(8, -1));
    int ans = solution(0, 0, s, t, n, dp);
    cout << ans << "\n";
}

int main()
{
    solve();
    return 0;
}
