#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// https://titanwolf.org/Network/Articles/Article?AID=f7c2e7cd-6e89-459a-b72b-fbaf4dd5376d#gsc.tab=0
// solution ^
ll n, s1, v1, s2, v2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll c = 0;
    while(t--){
        c += 1;
        cout << "Case #" << c << ": ";
        cin >> n >> s1 >> v1 >> s2 >> v2;
        ll ans = 0;
        if (n / s1 <= 1e6)
        {
            for (int i = 0; i <= n / s1; i++){
                ans = max(ans, i * v1 + ((n - i * s1) / s2) * v2);
            }
        }
        else if (n/s2<=1e6){
            swap(s1, s2);
            swap(v1, v2);
            for (int i = 0; i <= n / s1; i++)
            {
                ans = max(ans, i * v1 + ((n - i * s1) / s2) * v2);
            }
        }
        else{
            if (s2*v1>s1*v2){
                swap(s1, s2);
                swap(v1, v2);
                for (int i = 0; i < s2; i++)
                {
                    ans = max(ans, i * v1 + ((n - i * s1) / s2) * v2);
                }
            }
            else{
                for (int i = 0; i < s2; i++)
                {
                    ans = max(ans, i * v1 + ((n - i * s1) / s2) * v2);
                }
            }
        }
        cout << ans << '\n';

    }
}