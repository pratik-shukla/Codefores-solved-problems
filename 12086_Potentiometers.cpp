#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
ll bit[200005];

void update(ll ind, ll val, ll n)
{
    ind += 1;
    while (ind<=n)
    {
        bit[ind] += val;
        ind += (ind & (-ind));
    }
}

ll getsum(ll ind)
{
    ll curr = 0;
    ind += 1;
    while(ind>0)
    {
        curr+=bit[ind];
        ind -= (ind & (-ind));
    }
    return curr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 3;
    while (t--)
    {
        ll n;
        cin>> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        string s;
        ll x, y, r;
        memset(bit, 0, sizeof(bit));
        if (n==0) continue;
        if (3 - t > 1)
            cout << '\n';
        cout << "Case " << 3 - t << ":" << '\n';
        for (int i = 0; i < n; i++)
        {
            update(i, a[i], n);
        }
        while (1)
        {
            cin >> s;
            if (s == "END")
            {
                break;
            }
            else if (s == "S")
            {
                cin >> x >> r;
                x -= 1;
                update(x, r -a[x], n);
                a[x] = r;
            }
            else
            {
                cin >> x >> y;
                x -= 1;
                y -= 1;
                cout <<getsum(y)-getsum(x-1)<<'\n';
            }
        }

    }
}