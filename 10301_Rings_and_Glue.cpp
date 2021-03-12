#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<ll> adj[100001];
bool vis[100001];
ll curr = 0;

void dfs(ll node){
    curr += 1;
    for (auto i:adj[node]){
        if (!vis[i]) vis[i] =1, dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        ll n;
        cin >> n;
        if (n==-1) break;
        vector<pair<pair<double, double>, double> >  a(n);
        for (int i=0; i<n; i++){
            adj[i].clear();
            vis[i] = 0;
            cin >> a[i].first.first >> a[i].first.second >> a[i].second;
        }
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                double r = a[i].second + a[j].second;
                r = r * r;
                double r2 = fabs(a[i].second - a[j].second) * fabs(a[i].second - a[j].second);
                double dist = (a[i].first.first - a[j].first.first) * (a[i].first.first - a[j].first.first) + (a[i].first.second - a[j].first.second) * (a[i].first.second - a[j].first.second);
                if (dist <= r and dist>=r2)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        ll maxx = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                vis[i] = 1;
                curr = 0;
                dfs(i);
                maxx = max(maxx, curr);
            }
        }
        if (maxx!=1)
            cout << "The largest component contains "<<maxx<<" rings." << '\n';
        else
            cout << "The largest component contains " << maxx << " ring." << '\n';

    }
    
}