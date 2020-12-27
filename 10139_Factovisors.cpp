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
    ll n, m;
    while(cin>>n>>m)
    {
        ll i = 2;
        ll f = 1;
        ll z = m;
        while(i *i <= m ){
            ll t = 0;
            if (m % i == 0) {
                while (m % i == 0 ){
                    m /= i;
                    t += 1;
                }
                ll k = n;
                ll now = 0;
                while (k > 0)
                {
                    now += k / i;
                    k /= i;
                }
                now /= t;
                if (!now)
                {
                    f = 0;
                }
            }
            i++;
        }
        if (m>=2)
        {
            ll t = 1;
            ll k = n;
            ll now = 0;
            while (k > 0)
            {
                now += k / m;
                k /= m;
            }
            now /= t;
            if (!now)
            {
                f = 0;
            }
        }
        (f) ? cout << z << " divides " << n << '!' << '\n' : cout << z << " does not divide " << n << '!' << '\n';
}
}