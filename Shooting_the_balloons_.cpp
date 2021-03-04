#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


// OMG best binary search problem till date...took lot of time and was a such a pain in ass...but finally aced it 😌

vector<ll> a;
ll n, m;

pair<ll,ll> check(ll val){
    int j = 0;
    ll curr = 0;
    ll f = 0;
    ll there = 0;
    for (int i = 0; i < n; i++){
        while (j<n and curr<=val){
            curr += a[j];
            if (curr == val)
                f += 1;
            j += 1;
        }
        if (curr>val)
            there += (n - j+1);
        curr -= a[i];
        if (curr == val)
            f += 1;
    }
    return {f, there};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll l = 0;
    ll r = 5e13;
    ll ans = 1e9+1;
    ll tot = n * (n + 1) >> 1;
    while (l <= r)
    {
        ll mid = (r - l) / 2 + l;
        pair<ll, ll> now = check(mid);
        if (tot-(now.second +now.first)<= m-1)
        {
            if (tot - (now.second)>=m)
            {
                ans = mid;
                break;
            }
            l = mid + 1;
            
        }
        else{
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}