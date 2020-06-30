#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<pair<int, int>> to_do  {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    //int visited[129][129] = {0};
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        int mat[190][190],dp[190][190];
        vector<pair<int, int>> one;
        queue<pair<pair<int, int>, int>> q;
        int visited[190][190] = {0};
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                mat[i][j] =s[j]-'0';
                if (mat[i][j])
                    one.push_back({i, j}), q.push({{i, j}, 0}), visited[i][j] = 1;
                
                dp[i][j] = -1;
            }
        }
        while (!q.empty())
        {
            int height = q.front().second;
            int X = q.front().first.first;
            int Y = q.front().first.second;
            dp[X][Y] = height;
            q.pop();
            for (auto z:to_do)
            {
                if (X + z.first >= 0 and X + z.first < n and Y + z.second >= 0 and Y + z.second < m and !visited[X + z.first][Y + z.second])
                {
                    visited[X + z.first][Y + z.second] = 1;
                    q.push({{X + z.first, Y + z.second}, height + 1});
                }
            }
        }           
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << '\n';
        }
       // break;
    }
    
}