#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
const int N = 20000000;
ll lp[N + 1];
int main()
{
    vector<ll> primes;
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            primes.push_back(i);
        }
        for (ll j = 0; j < primes.size() and primes[j] <= lp[i] and i * primes[j] <= N; j++)
        {
            lp[i * primes[j]] = primes[j];
        }
    }
    for (ll i = 1; i < primes.size(); i++)
    {
        if (primes[i]-primes[i-1]==2)
            ans.push_back({primes[i - 1], primes[i]});
    }
        ll n;
        //cout << ans.size() << '\n';
        // for (auto i:primes)
        //     cout << i << " ";
        while(cin>>n)
        {
            cout << "(" << ans[n - 1].first << ", " << ans[n - 1].second << ")"<<'\n';
        }
 }
