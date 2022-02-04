#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll seg[1000001];
ll lazy[1000001];
vector<ll> a;
void build(ll node, ll l, ll r)
{
    if (r < l)
        return;
    if (r == l)
    {
        seg[node] = a[l];
        return;
    }
    ll left = 2 * node;
    ll right = 2 * node + 1;
    build(left, l, (r + l) / 2);
    build(right, (l + r) / 2 + 1, r);
    seg[node] = min(seg[left], seg[right]);
    return;
}

// Point UPDATES
void update(ll node, ll ind, ll val, ll l, ll r)
{
    if (l == r)
    {
        seg[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (ind <= mid)
    {
        update(2 * node, ind, val, l, mid);
    }
    else
    {
        update(2 * node + 1, ind, val, mid + 1, r);
    }
    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
    return;
}

ll getmin(ll node, ll ql, ll qr, ll l, ll r)
{
    if (r < ql || l > qr || l > r)
    {
        return LLONG_MAX;
    }
    if (ql <= l and r <= qr)
    {
        return seg[node];
    }
    ll lemft, rimght;
    lemft = getmin(2 * node, ql, qr, l, (l + r) / 2);
    rimght = getmin(2 * node + 1, ql, qr, 1 + (l + r) / 2, r);
    //cout << node << " " << ql << " " << qr << " " << l << " " << r << " ?? " << min(lemft, rimght)<<'\n';
    return min(lemft, rimght);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        //cout << a[i] << " ";
    }
    //cout << '\n';
    build(1, 0, n - 1);
    string s;
    while (q--)
    {
        cin >> s;
        vector<ll> inds;
        ll l = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                l = i + 1;
                break;
            }
        }
        for (int j = l; j < s.length(); j++)
        {
            if (!(s[j] - '0' >= 0 and s[j] - '0' <= 9))
            {
                inds.push_back(stoi(s.substr(l, j)));
                l = j + 1;
            }
        }
        if (s[0]=='q'){
            //cout << inds[0] - 1 << " " << inds[1] - 1 << '\n';
            cout << getmin(1, inds[0] - 1, inds[1] - 1, 0, n - 1) << '\n';
        }
        else{
            vector<ll> changes;
            for (int i = 1; i<inds.size(); i++){
                changes.push_back(a[inds[i] - 1]);
            }
            changes.push_back(a[inds[0] - 1]);
            for (int i = 0; i<inds.size(); i++){
                a[inds[i] - 1] = changes[i];
                update(1, inds[i] - 1, changes[i], 0, n - 1);
            }
            
        }
    }
}