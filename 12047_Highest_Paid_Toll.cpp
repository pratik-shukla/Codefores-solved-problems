#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<ll> adj[10001], rev[10001];
map<pair<ll, ll>, ll> wei, rwei;
ll d[100001], dt[100001];
vector<pair<ll, ll>> edges;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ti;
    cin >> ti;
    while (ti--)
    {
        ll n, m, s, t, p, u, v, c;
        cin >> n >> m >> s >> t >> p;
        for (int i = 0; i <= n; i++)
            adj[i].clear(), rev[i].clear(), d[i] = 500000000, dt[i] = 500000000;
        wei.clear();
        rwei.clear();
        edges.clear();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> c;
            adj[u].push_back(v);
            rev[v].push_back(u);
            edges.push_back({u, v});
            wei[{u, v}] = c;
            rwei[{v, u}] = c;
        }
        d[s] = 0;
        priority_queue<pair<ll, ll>> pq;
        pq.push({0 ,s});
        while (!pq.empty())
        {
            ll node = pq.top().second;
            ll w = -1*pq.top().first;
            pq.pop();
            //if (w!=d[node]) continue;
            for (auto i : adj[node])
            {
                if (wei[{node, i}] + d[node] < d[i])
                {
                    d[i] = wei[{node, i}] + d[node];
                    pq.push({-1*d[i], i});
                }
            }
        }
        dt[t] = 0;
        pq.push({ 0,t});
        while (!pq.empty())
        {
            ll node = pq.top().second;
            ll w = -1 * pq.top().first;
            pq.pop();
            // if (w != dt[node])
            //     continue;
            for (auto i : rev[node])
            {
                if (rwei[{ node, i}] + dt[node] < dt[i])
                {
                    dt[i] = rwei[{node, i}] + dt[node];
                    pq.push({-1*dt[i], i});
                }
            }
        }
        ll ans = -1;
        for (auto i:edges){
            if (d[i.first]+wei[{i.first, i.second}]+dt[i.second]<=p)
                ans = max(ans, wei[{i.first, i.second}]);
           }
        cout << ans << '\n';

    }
}