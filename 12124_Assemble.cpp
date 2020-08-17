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
    ll t;
    cin >> t;
    while (t--)
    {
        string s, f;
        ll n, b, p, q;
        cin >> n >> b;
        map<string, vector<pair<ll,ll>>> hmp;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> f >> p >> q;
            if (hmp.find(s)==hmp.end())
            {
                vector<pair<ll, ll>> t;
                t.push_back({p, q});
                hmp[s] = t;
            }
            else
            {
                hmp[s].push_back({p, q});
            } 
        }
        ll l = 1;
        ll r = 1000000000;
        ll ans = -1;
        while (l<=r)
        {
            ll mid = (r - l) / 2 + l;
            //cout << mid << '\n';
            ll curr = 0;
            for (auto i:hmp)
            {
                ll now = INT_MAX;
                for (auto j:i.second)
                {
                    if (j.second>=mid)
                    {
                        now = min(now, j.first);
                    }
                }
                curr += now;
                if (curr>b)
                    break;
            }
            //cout << curr << '\n';
            if (curr<=b)
            {
                //cout << "Ha bhai"<<b << '\n';
                l = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                r = mid - 1;
            }
            
        }
        cout << ans << '\n';
    }
    
}