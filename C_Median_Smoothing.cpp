#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

bool vis[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];
    vis[0] = 1;
    vis[n - 1] = 1;
    queue<pair<pair<ll, ll>, ll>> q; // index,direction,height,
    q.push({{0, 1}, 0});
    q.push({{n-1, -1}, 0});
    for (int i = 1; i < n - 1; i++){
        if (a[i]==a[i+1] and a[i]==a[i-1]){
            vis[i] = 1;
            
        }
        if (a[i-1]==a[i] and a[i]!=a[i+1]){
            vis[i] = 1;
            q.push({{i, 1}, 0});
        }
        if (a[i+1]==a[i] and a[i-1]!=a[i]){
            vis[i] = 1;
            q.push({{i, -1}, 0});
        }
    }
    ll ans = 0;
    while (!q.empty()){
        ll ind = q.front().first.first;
        ll dir = q.front().first.second;
        ll height = q.front().second;
        q.pop();
        ans = max(height, ans);
        if (ind+dir>=0 and ind+dir<n and !vis[ind+dir]){
            vis[ind + dir] = 1;
            a[ind + dir] = a[ind];
            q.push({{ind+dir, dir}, height+1});
        }
    }
    cout << ans << '\n';
    for (auto i:a){
        cout << i << " ";
    }
}