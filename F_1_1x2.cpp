// problem : https://atcoder.jp/contests/abc188/tasks/abc188_f
// solution: https://codeforces.com/blog/entry/86642
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

map<ll, ll> dp;

ll doit(ll f, ll s){ 
    if (dp.find(s)!=dp.end()){
        return dp[s];
    }
    ll k = s-f;
    if (f>=s)
    {
        k= f-s;
    }
    else if (s%2){
        k= min(k,min(2+doit(f, (s+1)/2), 2+doit(f, (s-1)/2)));
    }
    else{
        k= min(k,1 +  doit(f, s / 2));
    }
    dp[s] = k;
    return k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>> m;
    cout << doit(n, m);
}