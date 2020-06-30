#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
void DBG(string names)
{
}
template <class H, class... T>
void DBG(string names, H h, T... t)
{
    auto pos = names.find(',');
    auto first_name = names.substr(0, pos);
    auto rest = names.substr(pos + 1);
    // Strip space at the beginning
    while (rest.front() == ' ')
    {
        rest = rest.substr(1);
    }
    cerr << "[" << first_name << "] [" << ts(h) << "]" << endl;
    DBG(rest, t...);
}
#ifdef LOCAL
#define dbg(...) DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t, k;
    while (1)
    {
        cin >> n >> t;
        if (n == 0 and t == 0)
            break;
        vector<ll> coinThick, tableHeit, minVal, maxVal;
        for (ll i = 0; i < n; i++)
        {
            cin >> k;
            coinThick.push_back(k);
        }
        for (ll i = 0; i < t; i++)
        {
            cin >> k;
            tableHeit.push_back(k);
            minVal.push_back(0);
            maxVal.push_back(-1);
        }
        ll curr;
        for (ll a = 0; a < n; a++)
        {
            for (ll b = a + 1; b < n; b++)
            {
                for (ll c = b + 1; c < n; c++)
                {
                    for (ll d = c + 1; d < n; d++)
                    {
                        for (ll i = 0; i < t; i++)
                        {
                            curr = (coinThick[a] * coinThick[b]) / __gcd(coinThick[a], coinThick[b]);
                            curr = (curr * coinThick[c]) / __gcd(curr, coinThick[c]);
                            curr = (curr * coinThick[d]) / __gcd(curr, coinThick[d]);
                            minVal[i] = max(minVal[i], (tableHeit[i] / curr) * curr);
                            bool rem = 0;
                            if (tableHeit[i] % curr)
                                rem = 1;
                            if (maxVal[i] == -1)
                                maxVal[i] = (tableHeit[i] / curr + rem) * curr;
                            else
                                maxVal[i] = min(maxVal[i], (tableHeit[i] / curr + rem) * curr);
                        }
                    }
                }
            }
        }
        for (ll i = 0; i < t; i++)
        {
            cout << minVal[i] << " " << maxVal[i] << '\n';
        }
    }
}