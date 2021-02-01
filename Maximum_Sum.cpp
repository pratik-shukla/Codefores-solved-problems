#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
pair<ll,ll> seg[1000001];
vector<ll> a;
void build(ll node, ll l, ll r)
{
    if (r<l)
        return;
    if (r==l){
        seg[node] = {l,a[l]};
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    build(left, l, (r + l) / 2);
    build(right, (l + r) / 2 + 1, r);
    if (seg[left].second>seg[right].second){
        seg[node] = seg[left];
    }
    else{
        seg[node] =seg[right];
    }
    return;
}


// Point UPDATES
void update(ll node, ll ind, ll val, ll l, ll r){
    if (l==r){
        seg[node] ={l, val};
        return;
    }
    ll mid=(l+r) / 2;
    if (ind<=mid){
        update(2 * node, ind, val, l, mid);
    }
    else
    {
        update(2 * node + 1, ind, val, mid + 1, r);
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    if (seg[left].second > seg[right].second)
    {
        seg[node] = seg[left];
    }
    else
    {
        seg[node] = seg[right];
    }
    return;
}

pair<ll,ll> getmax(ll node, ll ql, ll qr, ll l, ll r ){
    if (r<ql||l>qr||l>r){
        return {-1, -1};
    }
    if (ql<=l and r<=qr){
        return seg[node];
    }
    pair<ll,ll> lemft, rimght;
    lemft = getmax(2 * node, ql, qr, l, (l + r) / 2);
    rimght = getmax(2 * node + 1, ql, qr, 1+(l + r) / 2, r);
    if (lemft.second>rimght.second){
        return lemft;
    }
    return rimght;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll q;
    cin >> q;
    char typ;
    ll i, x, l, r;
    build(1, 0, n - 1);
    while(q--){
        cin >> typ;
        if (typ=='U'){
            cin >> i >> x;
            i--;
            update(1, i, x, 0, n - 1);
            a[i] = x;
        }
        else{
            cin >> l >> r;
            l--;
            r--;
            pair<ll,ll> f = getmax(1, l, r, 0, n - 1);
            update(1, f.first,-1, 0, n - 1);
            pair<ll, ll> s = getmax(1, l, r, 0, n - 1);
            cout << f.second + s.second << '\n';
            update(1, f.first, a[f.first], 0, n - 1);
        }
    }
}