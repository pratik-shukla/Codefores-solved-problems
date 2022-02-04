#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
void DBG(string names)
{
}
template <class H, class... T>
void DBG(string names, H h, T... t)
{
    auto pos = names.find(',');
    auto first_name = names.substr(0, pos);
    auto rest = names.substr(pos + 1);
    // Strip space at the beginning
    while (rest.front() == ' ')
    {
        rest = rest.substr(1);
    }
    cerr << "[" << first_name << "] [" << ts(h) << "]" << endl;
    DBG(rest, t...);
}
ll power(ll x, ll y, ll p)
{
    ll res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
#ifdef LOCAL
#define dbg(...) DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll rem = 2000000011;
    ll k = 0;
    while (t--)
    {
        k++;
        ll n;
        cin >> n;
        cout << "Case #" << k << ": " << power(n, n - 2, rem) << '\n';
    }
    
}