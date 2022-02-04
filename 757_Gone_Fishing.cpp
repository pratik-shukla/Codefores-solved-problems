#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll n, h;
vector<ll> f, d, tt;

map<pair<ll,ll>,pair<vector<ll>, ll>> dp;
ll ans[40];

pair<vector<ll>, ll> doit(ll ind, ll time)
{

    if (dp.find({ind,time})!=dp.end()) return dp[{ind,time}];
    if (ind==n or time==h){
        vector<ll> t(n, 0);
        return {t,0};
    }
    if (time>h)
        return {{},-INT_MAX};
    pair<vector<ll>, ll> now = doit(ind + 1, time + tt[ind]);
    ll cot = 0;
    for (int t = 1; t <= 192; t++)
    {
        if (time+t<=h)
        {
            cot += max((ll)0, f[ind] - d[ind] * (t-1));
            pair<vector<ll>, ll> k = doit(ind + 1, time + t + tt[ind]);
            k.second += cot;
            pair<vector<ll>, ll> z = doit(n, time + t);
            z.second += cot;
            if (k.second<=z.second)
                k = z;
            if (k.second>=now.second){
                now = k;
                now.first[ind] = t;
            }
        }
        else break;
    }
    dp[{ind,time}] = now;
    return now;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        cin >> n;
        dp.clear();
        f.resize(n), d.resize(n), tt.resize(n);
        if (!n) break;
        cin >> h;
        h *= 12;
        for (int i = 0; i < n;i++)
            cin >> f[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        for (int i = 0; i < n-1; i++) cin >> tt[i];
        pair<vector<ll>, ll> fans= doit(0, 0) ;
        ll cnt = 0;
        for (auto i : fans.first)
        {
            cout << 5 * i;
            if (cnt!=fans.first.size()-1)
                cout << ", ";
            else
                cout << '\n';
            cnt++;
        }
        cout << "Number of fish expected: "<< fans.second << '\n';
        cout << '\n';
    }
    
}