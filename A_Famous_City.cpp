#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll seg[1000001];
ll lazy[1000001];
vector<ll> a;
map<ll, vector<ll>> mp;
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
    seg[node] = min(seg[left] , seg[right]);
    return;
}


ll getmin(ll node, ll ql, ll qr, ll l, ll r ){
    if (r<ql||l>qr||l>r){
        return LLONG_MAX;
    }
    if (ql<=l and r<=qr){
        return seg[node];
    }
    ll lemft, rimght;
    lemft = getmin(2 * node, ql, qr, l, (l + r) / 2);
    rimght = getmin(2 * node + 1, ql, qr, 1+(l + r) / 2, r);
    return min(lemft,rimght);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll cas = 0;
    while(cin>>n){
        cas++;
        cout << "Case " << cas << ": ";
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < 5 * n; i++)
            seg[i] = INT_MAX;
        mp.clear();
        build(1, 0, n - 1);
        for (int i = 0; i < n; i++){
            if (mp.count(a[i])){
                mp[a[i]].push_back(i);
            }
            else{
                mp[a[i]] = {i};
            }
        }
        ll ans = 0;
        bool f = 0;
        for (auto i:mp){
            ll j = 0;
            if (!i.first) continue;
            while(j<i.second.size()){
                ans++;
                f = 0;
                for (int k = j+1; k<i.second.size(); k++){
                    if (getmin(1, i.second[j] + 1, i.second[k] - 1, 0, n - 1) < i.first)
                    {
                        j = k;
                        f = 1;
                        break;
                    }
                }
                if (f==0)
                    break;
            }
        }
        cout << ans << '\n';

    }
    cout << '\n';
}