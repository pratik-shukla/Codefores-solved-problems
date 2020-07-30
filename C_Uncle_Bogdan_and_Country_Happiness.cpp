#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
// the little guy below helps me to create unordered set of vectors
// just declare it like this ---> unordered_set<vector<int>, VectorHash>>
// credits:: https://stackoverflow.com/users/2069064/barry
struct VectorHash
{
    size_t operator()(const std::vector<int> &v) const
    {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v)
        {
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
vector<string> vec_splitter(string s)
{
    s += ',';
    vector<string> res;
    while (!s.empty())
    {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM)
{
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T)
{
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__),
0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

ll n, m,u,v;
vector<ll> adj[100002];
ll popTogo[100002];
ll g[100002];
bool visited[100002];
vector<ll> p, h;
bool f;
ll dfs1(ll node)
{
    visited[node] = 1;
    ll k = p[node - 1];
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            k += dfs1(i);
        }
    }
    popTogo[node] = k;
    return popTogo[node];
}

void dfs2(int node)
{
    visited[node] = 1;
    ll sum_g = 0;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs2(i);
            sum_g += g[i];
        }
    }
    //cout << popTogo[node] << " " << h[node - 1] << '\n';
    if ((popTogo[node] + h[node - 1]) % 2 or abs(popTogo[node] - h[node - 1]) % 2 or popTogo[node] - h[node - 1] < 0 or popTogo[node] + h[node - 1] < 0)
    {
        f = 1;
    }
    g[node] = (popTogo[node] + h[node - 1]) / 2;
    if (g[node]<0 or g[node]>popTogo[node] or sum_g>g[node])
    {
        f = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        h.clear();
        p.clear();
        for (int i = 0; i < n; i++)
        {
            adj[i + 1].clear();
            visited[i + 1] = 0;
            popTogo[i + 1] = 0;
            cin >> u;
            p.push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            cin >> u;
            h.push_back(u);
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        popTogo[1] = dfs1(1);
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << popTogo[i] << " ";
        // }
        // cout << '\n';
        f = 0;
        for (int i = 1; i <= n; i++)
        {
            visited[i] = 0;
        }
        dfs2(1);
        if (f)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }
}