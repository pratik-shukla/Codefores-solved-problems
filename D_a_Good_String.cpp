#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
ll getMin(string &s,ll l, ll r, ll curr)
{
    if (r - l == 1)
    {
        return 1 ^ (s[l] == curr);
    }
    ll left = 0, right = 0;
    for (ll i = l; i < r; i++)
    {
        if (i < (l + r) / 2)
        {
            if (s[i] != curr)
            {
                left++;
            }
        }
        else
        {
            if (s[i] != curr)
            {
                right++;
            }
        }
    }
    return min(left + getMin(s, (l + r) / 2, r, curr + 1), right + getMin(s, l, (l + r) / 2, curr + 1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll curr = 'a';
        cout << getMin(s, 0, n, curr) << '\n';
    }
}