#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<ll> adj[200002];
ll st[200002];
ll add[200002];
ll ans[200002];
ll neg[200002];
ll cnt;
ll nowadd;

void dfs1(ll node, ll par)
{
    st[node] = ++cnt;
    for (auto i:adj[node]){
        if (i!=par){
            dfs1(i, node);
        }
    }
}

void dfs2(ll node, ll par){
    nowadd += add[node];
    nowadd+=neg[node];
    ans[node] = nowadd;
    for (auto i:adj[node]){
        if (i!=par)dfs2(i, node);
    }
    nowadd -= neg[node];
    nowadd -= add[node];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, u, v,q, t, e ,x;
    cin >> n;
    vector < pair<ll, ll>> edges;
    cnt = 0;
    for (int i = 0; i < n - 1; i++){
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    ll final = 0;
    dfs1(1, -1);
    while(q--){
        cin >> t >> e >> x;
        e--;
        if (t==1){
            if (st[edges[e].first] > st[edges[e].second]){
                add[edges[e].first] += x;
            }
            else if (st[edges[e].first] < st[edges[e].second])
            {
                neg[edges[e].second] += -x;
                final += x;
            }
            
        }
        else{
            if (st[edges[e].first] > st[edges[e].second])
            {
                neg[edges[e].first] += -x;
                final += x;
            }
            else if (st[edges[e].first] < st[edges[e].second])
            {
                add[edges[e].second] += x;
            }
        }
    }
    nowadd = 0;
    dfs2(1, -1);
    for (int i = 1; i <= n; i++){
        cout << ans[i] + final<<'\n';
    }
}