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
    ll n;
    cin>>n;
    vector<stack<ll>> a(n);
    map<ll, ll> pos;
    for (int i = 0; i < n; i++)
    {
        a[i].push(i);
        pos[i] = i;
    }
    string s,op;
    ll ini, fin;
    while(1)
    {
        cin>>s;
        if (s =="quit")
            break;
        cin >> ini>>op>> fin;
        if (pos[ini]==pos[fin] or ini==fin)
            continue;
        if (s=="move")
        {
            if (op=="onto")
            {
                while(a[pos[ini]].top()!=ini)
                {
                    pos[a[pos[ini]].top()] = a[pos[ini]].top();
                    a[a[pos[ini]].top()].push(a[pos[ini]].top());
                    a[pos[ini]].pop();
                }
                while (a[pos[fin]].top() != fin)
                {
                    pos[a[pos[fin]].top()] = a[pos[fin]].top();
                    a[a[pos[fin]].top()].push(a[pos[fin]].top());
                    a[pos[fin]].pop();
                }
                a[pos[ini]].pop();
                a[pos[fin]].push(ini);
                pos[ini] = pos[fin];
            }
            else
            {
                while (a[pos[ini]].top() != ini)
                {
                    pos[a[pos[ini]].top()] = a[pos[ini]].top();
                    a[a[pos[ini]].top()].push(a[pos[ini]].top());
                    a[pos[ini]].pop();
                }
                a[pos[ini]].pop();
                a[pos[fin]].push(ini);
                pos[ini] = pos[fin];
            }
            
        }
        else
        {
            if (op == "onto")
            {
                while (a[pos[fin]].top() != fin)
                {
                    pos[a[pos[fin]].top()] = a[pos[fin]].top();
                    a[a[pos[fin]].top()].push(a[pos[fin]].top());
                    a[pos[fin]].pop();
                }
                stack<ll> t;
                while(a[pos[ini]].top()!=ini)
                {
                    t.push(a[pos[ini]].top());
                    a[pos[ini]].pop();
                }
                t.push(a[pos[ini]].top());
                a[pos[ini]].pop();
                while(!t.empty())
                {
                    a[pos[fin]].push(t.top());
                    pos[t.top()] = pos[fin];
                    t.pop();
                }

            }
            else
            {
                stack<ll> t;
                while (a[pos[ini]].top() != ini)
                {
                    t.push(a[pos[ini]].top());
                    a[pos[ini]].pop();
                }
                t.push(a[pos[ini]].top());
                a[pos[ini]].pop();
                while (!t.empty())
                {
                    a[pos[fin]].push(t.top());
                    pos[t.top()] = pos[fin];
                    t.pop();
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        stack<ll> t;
        while (!a[i].empty())
        {
            t.push(a[i].top());
            a[i].pop();
        }
        while (!t.empty())
        {
            cout << t.top() << " ";
            t.pop();
        }
        if (i!=n-1)cout << '\n';
    }
    //cout << '\n';
}
