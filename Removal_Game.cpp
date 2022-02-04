#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
ll n;
vector<ll> a;
int ans;
ll dp[5005][5005];
ll help( int i, int j)
{
    //cout << x << '\n';
    if (dp[i][j] != 0)
        return dp[i][j];
    if (i > j)
        return 0;
    return dp[i][j] = max(a[i] + min(help( i + 1, j - 1), help( i + 2, j)), a[j] + min(help( i + 1, j - 1), help( i, j - 2)));
    ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll x;
    a.clear();
    for (int i = 0; i < n; i++)
        cin >> x, a.push_back(x);
    cout << help( 0, n - 1)<< '\n';
}