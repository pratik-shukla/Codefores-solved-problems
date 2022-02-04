#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll seg[100001];
ll lazy[100001];
ll isprime[1000001];
vector<ll> a;

void build(ll node, ll l, ll r)
{
    if (r<l)
        return;
    if (r==l){
        seg[node] = a[l];
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    build(left, l, (r + l) / 2);
    build(right, (l + r) / 2 + 1, r);
    seg[node] = seg[left] + seg[right];
    return;
}

void updaterange(ll node, ll st, ll end, ll l , ll r, ll val ){
    if (lazy[node]){
        seg[node] = isprime[lazy[node]] * (r - l + 1);
        if (l!=r){
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if (st>r|| end<l ){
        return;
    }
    if (st<=l and r<=end){
        seg[node] = (r- l + 1) * isprime[val];
        if (l!=r){
            lazy[2 * node] = val;
            lazy[2 * node + 1] = val;
        }
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    updaterange(left, st, end, l, (r + l) / 2, val);
    updaterange(right, st, end, (l + r) / 2 + 1, r, val);
    seg[node] = seg[left] + seg[right];

}

ll getsum(ll node, ll ql, ll qr, ll l, ll r ){
    if (lazy[node])
    {
        seg[node] = isprime[lazy[node]] * (r - l + 1);
        if (l != r)
        {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if (r<ql||l>qr||l>r){
        return 0;
    }
    if (ql<=l and r<=qr){
        return seg[node];
    }
    ll lemft, rimght;
    lemft = getsum(2 * node, ql, qr, l, (l + r) / 2);
    rimght = getsum(2 * node + 1, ql, qr, 1+(l + r) / 2, r);
    return lemft+ rimght;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    isprime[1] = 0;
    for (int i = 2; i <= 1e6; i++){
        isprime[i] = 1;
    }
    for (ll i = 2; i <= 1e6; i++)
    {
        if (isprime[i])
        {
            for (ll j = i * i; j <= 1e6; j+=i){
                isprime[j] = 0;
            }
        }
    }
    ll cas = 1;
    while (t--)
    {
        memset(lazy, 0, sizeof(lazy));
        memset(seg, 0, sizeof(seg));
        cout << "Case " << cas << ": " << '\n';
        cas++;
        ll n, q;
        cin >> n >> q;
        a.resize(n);
        for (int i = 0; i < n; i++){
            cin >> a[i], a[i] = (isprime[a[i]]) ? 1 : 0;
        }
        build(1, 0, n - 1);
        ll type, l, r, val;
        while(q--){
            cin>>type>>l>>r;
            l--;
            r--;
            if (type){
                cout << getsum(1, l, r, 0, n - 1) << '\n';
            }
            else{
                cin >> val;
                updaterange(1, l, r, 0, n - 1, val);
            }
        }
    }
}