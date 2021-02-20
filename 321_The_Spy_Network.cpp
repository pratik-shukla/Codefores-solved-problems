#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<ll> adj[200001];
ll store[200001];
map<pair<ll, ll>, ll> wei;
map<pair<ll, ll>, ll> inds;
vector<pair<ll, ll>> ans;

ll dfs1(ll node, ll par, ll curr, ll len){
    ll now = 0;

    if (curr < len / 2 + len % 2)
    {
        now= (len / 2 + len % 2 - curr);
    }
    else
    {
        now= 0;
    }
    for (auto i: adj[node]){
        if (i!=par){
            store[i] = dfs1(i, node, curr + wei[{node, i}], len + 1);
            now = max(store[i], now);
        }
    }
    return now;
}

void dfs2(ll node, ll par, ll done){
    for (auto i: adj[node]){
        if (store[i]-done>0 and wei[{node, i}]==0){
            ans.push_back({node, i});
            dfs2(i, node, done + 1);
        }
        else{
            dfs2(i, node, done);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,u,v;
    string s,t;
    cin >> n;
    for (int i = 0; i < n-1; i++){
        cin >> u >> v>>s;
        if (s=="protected"){
            wei[{v, u}] = wei[{u, v}] = 1;
        }
        else{
            cin >> t;
            wei[{u, v}] = wei[{v, u}] = 0;
        }
        adj[v].push_back(u);
        inds[{u, v}] = inds[{v, u}] = i + 1;
    }
    store[1] = dfs1(1, -1, 0, 0);
    dfs2(1, -1, 0);
    cout << ans.size() << '\n';
    //sort(ans.begin(), ans.end());
    for (auto i:ans){
        cout << inds[i] << " ";
    }
}