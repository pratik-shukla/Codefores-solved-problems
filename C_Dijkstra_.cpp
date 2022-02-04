#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
void DBG(string names)
{
}
template <class H, class... T>
void DBG(string names, H h, T... t)
{
    auto pos = names.find(',');
    auto first_name = names.substr(0, pos);
    auto rest = names.substr(pos + 1);
    // Strip space at the beginning
    while (rest.front() == ' ')
    {
        rest = rest.substr(1);
    }
    cerr << "[" << first_name << "] [" << ts(h) << "]" << endl;
    DBG(rest, t...);
}
#ifdef LOCAL
#define dbg(...) DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, a, b, w;
    vector<pair<ll, ll>> adj[100001];
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<ll> dist(n + 1, -1);
    vector<ll> trace(n + 1, -1);
    dist[1] = 0;
    trace[1] = 1;
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        ll node = pq.top().second;
        ll len = -1 * pq.top().first;
        pq.pop();
        if (len != dist[node])
            continue;
        for (auto i : adj[node])
        {
            if (dist[i.first] > len + i.second or dist[i.first] == -1)
            {
                dist[i.first] = len + i.second;
                trace[i.first] = node;
                pq.push({-dist[i.first], i.first});
            }
        }
    }
    for (ll i = 1; i <= n; i++)
        adj[i].clear();
    vector<ll> ans;
    ll from = n;
    ll to = trace[from];
    ans.push_back(from);
    while (to != from)
    {
        ans.push_back(to);
        from = to;
        if (from == -1)
            break;
        to = trace[from];
    }
    if (to != 1)
        cout << -1 << '\n';
    else
    {
        reverse(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (auto j:adj[i]) cout<<j.first<<" "<<j.second<<'\n';
    // }
}