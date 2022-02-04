#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
vector<vector<ll>> init, finaly;
ll n;

bool isequal(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (init[i][j]!=finaly[i][j])
                return 0;
        }
    }
    return 1;
}

void rightrotate(){
    vector<vector<ll>> t(n, vector<ll>(n, 0));
    for (int i = 0, jj =n-1; i < n, jj>=0; i++, jj--){
        for (int j = 0, ii=0; j < n, ii<n; j++, ii++){
            t[ii][jj] = init[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            init[i][j] = t[i][j];
            //cout << t[i][j] << " ";
        }
        //cout << '\n';
    }
}

void reflect(){
    vector<vector<ll>> t(n, vector<ll>(n, 0));
    for (int i = 0, ii = n - 1; i < n, ii >= 0; i++, ii--)
    {
        for (int j = 0, jj = 0; j < n, jj < n; j++, jj++)
        {
            t[ii][jj] = init[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            init[i][j] = t[i][j];
            //cout << t[i][j] << " ";
        }
        //cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll c = 0;
    while(cin>>n){
        c++;
        string s;
        init.clear();
        finaly.clear();
        vector<ll> t;
        for (int i = 0; i < n; i++){
            t.clear();
            cin >> s;
            for (auto i:s){
                if (i=='X'){
                    t.push_back(1);
                }
                else{
                    t.push_back(0);
                }
            }
            init.push_back(t);
            t.clear();
            cin >> s;
            for (auto i : s)
            {
                if (i == 'X')
                {
                    t.push_back(1);
                }
                else
                {
                    t.push_back(0);
                }
            }
            finaly.push_back(t);
        }
        if (isequal()){
            cout << "Pattern " << c << " was preserved." << '\n';
            continue;
        }
        rightrotate();
        if (isequal()){
            cout << "Pattern " << c << " was rotated 90 degrees." << '\n';
            continue;
        }
        rightrotate();
        if (isequal())
        {
            cout << "Pattern " << c << " was rotated 180 degrees." << '\n';
            continue;
        }
        rightrotate();
        if (isequal())
        {
            cout << "Pattern " << c << " was rotated 270 degrees." << '\n';
            continue;
        }
        rightrotate();
        reflect();
        if (isequal())
        {
            cout << "Pattern " << c << " was reflected vertically." << '\n';
            continue;
        }
        rightrotate();
        if (isequal())
        {
            cout << "Pattern " << c << " was reflected vertically and rotated 90 degrees." << '\n';
            continue;
        }
        rightrotate();
        if (isequal())
        {
            cout << "Pattern " << c << " was reflected vertically and rotated 180 degrees." << '\n';
            continue;
        }
        rightrotate();
        if (isequal())
        {
            cout << "Pattern " << c << " was reflected vertically and rotated 270 degrees." << '\n';
            continue;
        }
        cout << "Pattern " << c << " was improperly transformed." << '\n';
    }
    
}