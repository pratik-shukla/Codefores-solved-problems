#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

struct segT
{
    ll k; // size of seg tree
    vector<ll> tree; // segtree
    void init(ll n)
    {
        k = 1;
        while (k<n)
        {
            k *= 2;
        }
        tree.assign(2 * k, 0);
    }
    void setUtil(ll i,ll v, ll x, ll xl, ll xr)
    {
        if (xr-xl==1 or xr==2*k-1)
        {
            tree[x] = v;
            return;
        }
        ll m = (xl + xr) / 2;
        if (i<m)
        {
            setUtil(i, v, 2 * x + 1, xl, m);
        }
        else
        {
            setUtil(i, v, 2 * x + 2, m, xr);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
        return;
    }
    void set (ll i, ll v)
    {
        setUtil(i, v, 0, 0, k);
        return;
    }
    ll sumUtil (ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx>=r or rx<=l)
            return 0;
        if (lx>=l and rx<=r)
            return tree[x];
        ll mid = (lx + rx) / 2;
        ll s1 = sumUtil(l, r, 2 * x + 1, lx, mid);
        ll s2 = sumUtil(l, r, 2 * x + 2, mid, rx);
        return s1 + s2;
    }
    ll sum(ll l, ll r)
    {
        return sumUtil(l, r, 0, 0, k);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    segT seg;
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n, 0);
    seg.init(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        seg.set(i, a[i]);
    }
    ll typ;
    while(m--)
    {
        cin >>typ;
        if (typ==1)
        {
            int i, v;
            cin >> i >> v;
            seg.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << seg.sum(l, r) << '\n';
        }
        
    }
}

/*

left subtree from node x -> 2*x+1;
right subtree x-> 2*x+2;

tc ::

5 5
5 4 2 3 5
2 0 3
1 1 1
2 0 3
1 3 1
2 0 5
*/