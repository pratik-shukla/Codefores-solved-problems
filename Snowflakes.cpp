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
    vector<vector<ll>> a, p;
    vector<ll> t, now;
    for (int z = 0; z < n; z++){
        t.clear();
        t.resize(6);
        p.clear();
        for (int i = 0; i < 6; i++){
            cin >> t[i];
        }
        for (int i = 0; i < 6; i++){
            now.clear();
            for (int j = i; j < 6; j++)
                now.push_back(t[j]);
            for (int j = 0; j < i; j++)
                now.push_back(t[j]);
            p.push_back(now);
            // for (auto i : p[0])
            //     cout << i << " ";
            // cout << '\n';
        }
        reverse(t.begin(), t.end());
        for (int i = 0; i < 6; i++)
        {
            now.clear();
            for (int j = i; j < 6; j++)
                now.push_back(t[j]);
            for (int j = 0; j < i; j++)
                now.push_back(t[j]);
            p.push_back(now);
        }
        sort(p.begin(), p.end());
        a.push_back(p[0]);
        
    }
    sort(a.begin(), a.end());
    bool f = 0;
    for (int i = 1; i<a.size(); i++){
        if (a[i]==a[i-1]) {
            f = 1;
            break;
        }
    }
    if (f)
        cout << "Twin snowflakes found.";
    else
        cout << "No two snowflakes are alike.";
}