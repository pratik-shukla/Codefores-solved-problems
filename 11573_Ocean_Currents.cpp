#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

ll info[1001][1001];
ll dp[1001][1001];
vector < pair<ll, ll>>mov{{-1, 0},{-1,1}, {0, 1}, {1, 1}, {1,0}, {1,-1}, {0, -1}, {-1, -1}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll r, c;
    string s;
    cin >> r>>c;
    for (int i = 1; i <= r; i++)
    {
        cin >> s;
        for (int j = 1; j <= c; j++)
        {
            info[i][j] = s[j-1] - '0';
        }
    }
    ll t;
    cin >> t;
    while (t--){
        ll rs, cs, rd, cd;
        cin>>rs>>cs>>rd>> cd;
        deque<pair<ll, ll>> q;
        q.push_back({rs, cs});
        for (int i = 0; i <= r; i++)
        {
            for (int j = 0; j <= c; j++)
            {
                dp[i][j] = LLONG_MAX;
            }
        }
        dp[rs][cs] = 0;
        while (!q.empty())
        {
            pair<ll, ll> co = q.front();
            q.pop_front();
            //cout << co.first << " " << co.second << " " << dp[co.first][co.second] << '\n';
            for (int i = 0; i < 8; i++)
            {
                ll w = (i == info[co.first][co.second]) ? 0 : 1;
                if (co.first + mov[i].first > 0 and co.first + mov[i].first <= r and co.second + mov[i].second > 0 and co.second + mov[i].second <= c)
                {
                    if (dp[co.first][co.second] + w < dp[co.first + mov[i].first][co.second + mov[i].second])
                    {
                        dp[co.first + mov[i].first][co.second + mov[i].second] = dp[co.first][co.second] + w;
                        if (w)
                        {
                            q.push_back({co.first + mov[i].first, co.second + mov[i].second});
                        }
                        else
                        {
                            q.push_front({co.first + mov[i].first, co.second + mov[i].second});
                        }
                    }
                }
            }
        }
        cout << dp[rd][cd] << '\n';
        // for (int i = 0; i < r; i++){
        //     for (int j = 0; j <c; j++){
        //         cout << info[i][j] << ' ';
        //     }
        //     cout<<'\n';
        // }

    }
}