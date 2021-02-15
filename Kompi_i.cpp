#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll pow2[11];
    pow2[0] = 1;
    for (int i = 1; i <= 10; i++){
        pow2[i] = pow2[i - 1] * 2;
    }
    map<ll, ll> fin;
    bool vis[10];
    ll curr;
    for (auto i:a){
        string s = to_string(i);
        curr = 0;
        memset(vis, 0, sizeof(vis));
        for (auto j:s){
            if (!vis[j -'0'])
                curr += pow2[j - '0'], vis[j - '0'] = 1;
        }
        fin[curr] += 1;
    }
    vector<pair<ll, ll>> countnow;
    for (auto i:fin){
        countnow.push_back({i.first, i.second});
    }
    ll ans = 0;
    for (int i = 0; i<countnow.size(); i++){
        ans += (countnow[i].second) * (countnow[i].second - 1) / 2;
        for (int j = i + 1; j < countnow.size(); j++){
            if (countnow[i].first & countnow[j].first){
                ans += (countnow[i].second * countnow[j].second);
            }
        }
    }
    cout << ans;
}