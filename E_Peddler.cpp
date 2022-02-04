#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<ll> adj[200001];
ll a[200001];
ll dp[200001];
bool vis[200001];
ll ans;
vector<ll> t;
void dfs(ll node){
    vis[node] = 1;
    for (auto i:adj[node]){
        if (!vis[i])
            dfs(i);
        dp[node] = max(dp[node], dp[i]);
    }
    if (dp[node])
        ans = max(ans, dp[node] - a[node]);
    dp[node] = max(dp[node], a[node]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m, x, y;
    cin>>n>> m;
    ll ma, mi;
    for (int i=0; i<n; i++) cin>>a[i+1];
    for (int i=0; i<m; i++){
        cin >> x >> y;
        adj[x].push_back(y);
    }
    ans = -INT_MAX;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            vis[i] = 1;
            dfs(i);
        }

    }
    cout<<ans<<endl;
}
