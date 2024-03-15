// for the optimum solution jitna ho sake utna leaf node utha lena h aur
// jiska children nhi h usko utha lena h more formally agar kisi node ko
// tourism ke liye choose kar rhe h to uska parent bhi tourism ke liye hi
// choose hona chahiye tabhi maximum value milega

// suppose depth of node u is du -> number of nodes on path 1->u, size of
// subtree rooted on u is szu if tourism the total happiness += (szu-du)
// uske baad u ko envoy bana denge

#include <bits/stdc++.h>
#define maxn 200005
std::vector<int> conj[maxn];
int n, k, u, v, depth[maxn] = {0}, size[maxn] = {0}, det[maxn];
long long ans = 0;
int cmp(int a, int b) { return a > b; }
int dfs(int u, int f)
{
    // is node ka depth mark kar rahe h mtlb ki root se kitna distance h
    // iss node ka tree depth calculation
    depth[u] = depth[f] + 1;
    // abhi iska size ko one mark kar diye
    size[u] = 1;

    for (int i = 0; i < conj[u].size(); ++i)
    {
        // ye jo condition h ye ensure kar rha h ki wapas se parent mein dfs
        // nahi hone lag jaye
        if ((v = conj[u][i]) == f)
            continue;
        // niche ka jitna bhi node h wo add ho jayega u ka size mein
        size[u] += dfs(v, u);
    }
    // answer store ho rha h
    det[u] = size[u] - depth[u];
    return size[u];
}
int main()
{
    scanf("%d%d", &n, &k);
    // adjacency list graph representation
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        conj[u].push_back(v);
        conj[v].push_back(u);
    }
    // dfs start
    dfs(1, 0);
    // ye jo function h naya sikhe h
    // In the code, std::nth_element(det + 1, det + n - k, det + n + 1, cmp); is sorting the array det in such a way that the elements from index det + 1 to det + n - k - 1 are less than or equal to the element at index det + n - k, and elements from index det + n - k to det + n are greater than or equal to it.

    // ye big to small ka rha h

    std::nth_element(det + 1, det + n - k, det + n + 1, cmp);

    for (int i = 1; i <= n - k; ++i)
        ans += det[i];
    std::cout << ans;

    return 0;
}

// understood the problem
