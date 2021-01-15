#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll tree[4 * 100001 + 100];

vector<ll> a;

void build(ll node, ll l, ll r){
    if (l==r){
        tree[node] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] * tree[2 * node + 1];
}


void update(ll node, ll ind, ll val, ll l, ll r){
    if (l==r){
        tree[node] = val;
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
    tree[node] = tree[2 * node] * tree[2 * node + 1];
    return;
}

ll getval(ll node, ll ql, ll qr, ll l, ll r){
    if (l>qr or r<ql){
        return 1;
    }
    if (l>=ql and r<=qr){
        return tree[node];
    }
    ll mid = (l + r) / 2;
    return getval(2*node, ql, qr, l, mid) * getval(2*node+1, ql, qr, mid + 1, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    while(cin>>n>>k){
        a.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i]){
                a[i] = (a[i] > 0) ? 1 : -1;
            }
        }
        build(1, 0, n - 1);
        char q;
        ll l, r;
        while(k--){
            cin >> q;
            if (q =='C'){
                cin >> l >> r;
                l--;
                if (r){
                    r = (r > 0) ? 1 : -1;
                }
                update(1, l, r, 0, n - 1);
            }
    
            else{
                cin >> l >> r;
                l--;
                r--;
                ll m= getval(1, l, r, 0, n - 1)<<'\n';
                if (m){(m>0)?cout << "+" : cout << "-";
                }
                else
                cout << m;

            }
        }
        cout << '\n';
    }
    
}