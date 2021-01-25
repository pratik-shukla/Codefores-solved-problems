#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

map<char, ll> ind;
map<ll, char> getchr;
vector<ll> adj[30];
bool vis[30];
ll color[30];
ll curr;
ll key;
string vars, cons;
void doit(string now ){
    if (now.size() == 2 * (curr + 1))
    {
        //cout << now;
        for (int i = 0; i < now.size(); i++){
            if (i!=now.size()-1)
                cout << now[i];
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i<=curr; i++){
        if (!vis[i]){
            stack<ll> st;
            st.push(i);
            while(!st.empty()){
                ll node=st.top();
                st.pop();
                if (node!=i and vis[node]) return;
                for (auto i:adj[node]){
                    st.push(i);
                }
            }
            vis[i] = 1;
            doit(now + getchr[i]+" ");
            vis[i] = 0;
        }
    }
    return;
}

bool dfs(ll node){
    color[node] = 1;
    for(auto i:adj[node]){
        if (color[i]==1)
            return 1;
        if (color[i]==0 and dfs(i))
            return 1;
    }
    color[node] = 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    getline(cin, vars);
    while(t--){
        for (int i = 0; i < 30; i++){
            adj[i].clear();
            vis[i] = 0;
            color[i] = 0;
        }
        ind.clear();
        getline(cin, vars);
        getline(cin, vars);
        curr = 0;
        for (int i = 0; i < vars.length(); i++){
            if (vars[i]!=' '){
                getchr[curr] = vars[i];
                ind[vars[i]] = curr++;
            }
            
        }
        curr--;
        // for (int i = 0; i <= curr; i++){
        //     cout << i << " " << getchr[i] << '\n';
        // }
        getline(cin, cons);
        for (int i = 0; i < cons.length(); i+=4){
            //cout << cons[i] << " " << cons[i + 2] << '\n';
            adj[ind[cons[i]]].push_back(ind[cons[i + 2]]);
        }
        bool f = 0;
        for (int i = 0; i <= curr; i++){
            if (!color[i]){
                if (dfs(i)){
                    f = 1;
                    break;
                }
            }
        }
        key = 0;
        if (f)
            cout << "NO" << '\n';
        else{
            //cout << "possible" << '\n';
            doit("");
        }
        cout << '\n';
    }
}