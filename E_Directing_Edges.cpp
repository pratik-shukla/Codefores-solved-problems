#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

vector<int> adj[200002];
vector<int> topo;
ll indegree[200002];
vector<tuple<ll, ll, ll>> info;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m,t, u, v;
        cin >> n >> m;
        topo.clear();
        info.clear();
        for (int i = 1; i <= n; i++)
        {
            indegree[i] = 0;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            cin >> t >> u >> v;
            info.push_back({t, u, v});
            if (t)
            {
                adj[u].push_back(v);
                indegree[v]++;
            }
        }
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= n; i++)
        {
            if (!indegree[i])
                q.push(i);
        }
        while (!q.empty())
        {
            ll node = q.top();
            topo.push_back(node);
            q.pop();
            for (auto i:adj[node])
            {
                indegree[i]--;
                if (!indegree[i])
                {
                    q.push(i);
                }
            }
        }
        if (topo.size()<n)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            vector<ll> pos (n+2,0);
            for (int i = 0; i < n; i++)
            {
                pos[topo[i]] = i;
            }
            for (auto i:info)
            {
                if (get<0>(i))
                {
                    cout << get<1>(i) << " " << get<2>(i) << '\n';
                }
                else
                {
                    if (pos[get<1>(i)] > pos[get<2>(i)])
                    {
                        cout << get<2>(i) << " " << get<1>(i) << '\n';
                    }
                    else
                    {
                        cout << get<1>(i) << " " << get<2>(i) << '\n';
                    }
                    
                }
                
            }
         }
        
        
    }
    
}