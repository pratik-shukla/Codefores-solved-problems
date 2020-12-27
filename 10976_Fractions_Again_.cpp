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
    while(cin >> n)
    {
        vector<ll> ans;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if ((n*i)%(i-n)==0)
            {
                ans.push_back(i);
            }
        }
        cout << ans.size() << '\n';
        for(auto i:ans)
        {
            cout << "1/"<<n<<" = 1/" << i * (n) / ( i-n) << " + 1/" << i << '\n';
        }
    }
}