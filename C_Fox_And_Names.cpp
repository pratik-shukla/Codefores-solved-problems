#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
set<int> adj[100];
int indgree[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    string s;
    cin >> n;
    vector<string> author;
    for (int i = 0; i < 26; i++)
        indgree[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        author.push_back(s);
    }
    bool f = 1;
    bool poss = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            f = 1;
            for (int k = 0; k < min(author[i].length(), author[j].length()); k++)
            {
                //cout << author[i][k] << " " << author[j][k] << '\n';
                if (author[i][k] != author[j][k])
                {
                    f = 0;
                    int now = adj[author[i][k] - 'a'].size();
                    adj[author[i][k] - 'a'].insert(author[j][k] - 'a');
                    indgree[author[j][k] - 'a'] += (now != adj[author[i][k] - 'a'].size());
                    break;
                }
            }
            if (f == 1 and author[i].length()>= author[j].length())
                poss = 1;
        }
    }
    if (poss)
        cout << "Impossible" << '\n';
    else
    {
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++)
        {
            // cout << i << " " << indgree[i] << '\n';
            if (!indgree[i])
                pq.push(-1 * i);
        }
        vector<int> ans;
        while (!pq.empty())
        {
            int node = (-1 * pq.top());
            ans.push_back(node);
            pq.pop();
            for (auto i : adj[node])
            {
                indgree[i]--;
                if (!indgree[i])
                {
                    pq.push(-1 * i);
                }
            }
        }
        if (ans.size() != 26)
        {
            cout << "Impossible" << '\n';
        }
        else
        {
            for (auto i : ans)
                cout << char('a' + i);
        }
    }
    

    
    
}