#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll n, x;
ll dp[25][150];
ll test = 0;

ll doit(ll ind,  ll sum){
    
    if (dp[ind][sum]!=-1) return dp[ind][sum];
    if (ind ==n)
    {
        if (sum>=x)
            return dp[ind][sum] =1;
        else
            return dp[ind][sum] =0;
    }
    ll c = 0;
    for (int i = 1; i <= 6; i++){
        c += doit(ind + 1, sum+i);
    }
    return dp[ind][sum] =c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>x and (n or x)){
        memset(dp, -1, sizeof(dp));
        ll ans = doit(0, 0);
        ll total = 1;
        for (int i = 0; i < n; i++)
            total *= 6;
        ll k = __gcd(total, ans);
        ans /= k;
        total /= k;
        if (total!=1)
            cout<<ans<<"/"<<total<<endl;
        else
            cout << ans << '\n';
    }
}