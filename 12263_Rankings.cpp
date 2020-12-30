#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<ll> adj[501];
ll ind[501];
bool got[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, u, v;
        cin >> n;
        for (int i=0; i<=n; i++){
            ind[i] = 0, adj[i].clear();
            for (int j = 0; j <= n; j++)
                got[i][j] = 0;
        }
        vector<ll> a(n);
        map<ll, ll> rank;
        for (int i = 0; i < n; i++ )
            cin >> a[i], rank[a[i]]=i;
        ll m;
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> u >> v;
            got[u][v] = 1;
            if (rank[u]>rank[v]) adj[u].push_back(v), ind[v]++;
            else adj[v].push_back(u),ind[u]++;
        }
        for (int i = 0; i <n; i++){
            for (int j = i + 1; j < n; j++){
                if (!got[a[i]][a[j]] and !got[a[j]][a[i]]){
                    u = a[i];
                    v = a[j];
                    if (rank[u] < rank[v])
                        adj[u].push_back(v), ind[v]++;
                    else
                        adj[v].push_back(u), ind[u]++;
                }
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << i << " -> ";
        //     for (auto j : adj[i])
        //         cout << j << " ";
        //     cout << '\n';
        // }
        queue<ll> q;
        for (int i=1; i <= n; i++){
            if (!ind[i])
                q.push(i);
        }
        vector<ll> ans;
        while(!q.empty()){
            ll node=q.front();
            ans.push_back(node);
            q.pop();
            for (auto i:adj[node]){
                ind[i]--;
                if (!ind[i]) q.push(i);
            }
        }
        if (ans.size()==n){
        for (int i=0; i < n; i++){
            cout << ans[i];
            if (i!=n-1)
                cout << " ";
            else
                cout << '\n';
        }}
        else
            cout << "IMPOSSIBLE"<< '\n';
        //cout << '\n';

        //cout << "ok";
    }
}