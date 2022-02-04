#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
ll n;
vector<ll> a(101, 0);
ll dp[101][26000];
ll ans;
ll total;
ll c;
ll go(int ind, ll sum) 
{
    if (ind ==n)
    { 
        dp[ind][sum]=sum;
        return sum;
    }
    ll q1=0, q2=0;
    if (sum + a[ind] <= (total + 1) / 2 and dp[ind][sum+a[ind]]==-1)
        q1 = go(ind + 1, sum + a[ind]);
    if (sum <= (total + 1) / 2 and dp[ind][sum]==-1)
        q2 = go(ind + 1, sum);
    dp[ind][sum]=max(q1, q2);
    c+=1;
    return dp[ind][sum];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while (t--)
    {
        cin>>n;
        ans = INT_MAX;
        total=0;
        c=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            total+=a[i]; // calculate total value
            for (int j = 0; j < 26000; j++)
                dp[i][j] = -1;
        }
        ans=go(0, 0);
        cout<<abs(total-2*ans)<<'\n';
        //cout<<c<<'\n';
    }

}