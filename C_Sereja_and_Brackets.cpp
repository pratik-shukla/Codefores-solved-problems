#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
ll seg[5000011][3];
string a;
void build(ll node, ll l, ll r)
{
    if (r<l)
        return;
    if (r==l){
        // ) -> 2, ( -> 1
        if (a[l]==')')
            seg[node][2] = 1;
        else
            seg[node][1] = 1;
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    build(left, l, (r + l) / 2);
    build(right, (l + r) / 2 + 1, r);
    ll x = min(seg[left][1], seg[right][2]);
    seg[node][0] = x + seg[left][0] + seg[right][0];
    seg[node][1] = seg[left][1] + seg[right][1] - x;
    seg[node][2] = seg[left][2] + seg[right][2] - x;
    return;
}

pair<pair<ll,ll>,ll> getsum(ll node, ll ql, ll qr, ll l, ll r ){
    if (r<ql||l>qr||l>r){
        return {{0,0}, 0};
    }
    if (ql<=l and r<=qr){
        return {{seg[node][1], seg[node][2]},seg[node][0]};
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    pair<pair<ll, ll>, ll> lemft, rimght, give;
    give = {{0, 0}, 0};
    lemft = getsum(2 * node, ql, qr, l, (l + r) / 2);
    rimght = getsum(2 * node + 1, ql, qr, 1+(l + r) / 2, r);
    ll x = min(lemft.first.first, rimght.first.second);
    give.first.first = lemft.first.first + rimght.first.first - x;
    give.first.second = lemft.first.second + rimght.first.second - x;
    give.second = lemft.second + rimght.second + x;

    return give;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    ll n = a.length();
    build(1, 0, n - 1);
    ll q,l,r;
    cin >> q;
    while (q--){
        cin >> l >> r;
        l--;
        r--;
        cout << 2*(getsum(1, l, r, 0, n - 1).second) << '\n';
    }
}