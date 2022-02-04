#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")


bool check(ll n, ll k)
{
    ll l, r, mid, t;
    l = 1;
    r = n+1;
    //cout << r<<" "<<n+2<<" "<<k<<'\n';
    while(l<=r){
        mid = (r - l) / 2 + l;
        //cout << l << " " << r << " " << mid << " " << k << '\n';
        uint64_t t = 1;
        for (int i = 0; i < k; i++)
        {
            if (n /t < mid)
            {
                t = n + 1;
                break;
            }
            t *= mid;
        }
        //cout << mid << " " << k << " " << t << '\n';
        if (t==n)
            return 1;
        if (t<n)
            l = mid+1;
        else
            r = mid-1;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while(1)
    {
        cin >> n;
        if (!n) break;
        ll ans = 1;
        for (ll i = 32; i > 1; i--)
        {
            if (n>=0){
                if (check(n, i)){
                    ans = i;
                    break;
                }
            }
            else if (i%2)
            {
                if (check(-n, i))
                {
                    ans = i;
                    break;
                }
            }
        }
        //cout << n << '\n';
        cout<<ans<<'\n';
    }
    
}