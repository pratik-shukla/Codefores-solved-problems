#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define f first
#define s second
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

ll seg[200100][4];
vector<ll> a;
void build(ll node, ll l, ll r)
{
    if (r < l)
        return;
    if (r == l)
    {
        seg[node][0] = seg[node][1] = seg[node][2] = seg[node][3] = a[l]; // 0 -> sum, 1-> pref, 2-> suff, 3-> max;
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    build(left, l, (r + l) / 2);
    build(right, (l + r) / 2 + 1, r);
    seg[node][0] = seg[left][0] + seg[right][0];
    seg[node][1] = max(seg[left][0] + seg[right][1], seg[left][1]);
    seg[node][2] = max(seg[left][2] + seg[right][0], seg[right][2]);
    seg[node][3] = max(seg[left][3], max(seg[right][3], seg[left][2] + seg[right][1]));
    return;
}

pair<pair<ll, ll>, pair<ll, ll>> getsum(ll node, ll ql, ll qr, ll l, ll r)
{
    //cout << l << " " << r << '\n';
    if (r < ql || l > qr || l > r)
    {
        return {{-1000000, -1000000}, {-1000000, -1000000}};
    }
    if (ql <= l and r <= qr)
    {
        return {{seg[node][0], seg[node][1]}, {seg[node][2], seg[node][3]}};
    }
    pair<pair<ll, ll>, pair<ll, ll>> lemft, rimght, ret;
    lemft = getsum(2 * node, ql, qr, l, (l + r) / 2);
    rimght = getsum(2 * node + 1, ql, qr, 1 + (l + r) / 2, r);
    //cout << l << " " << r << " " << lemft.f.f << " " << lemft.f.s << " " << lemft.s.f << " " << lemft.s.s << '\n';
    ret.f.f = lemft.f.f + rimght.f.f;
    ret.f.s = max(lemft.f.f + rimght.f.s, lemft.f.s);
    ret.s.f = max(lemft.s.f + rimght.f.f, rimght.s.f);
    ret.s.s = max(lemft.s.s, max(rimght.s.s, lemft.s.f + rimght.f.s));
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, l, r;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    build(1, 0, n - 1);
    pair<pair<ll, ll>, pair<ll, ll>> ans;
    while (m--)
    {
        cin >> l >> r;
        l--;
        r--;
        ans = getsum(1, l, r, 0, n - 1);
        cout << ans.s.s << '\n';
    }
}