#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

//  [minx][miny][minz][maxx][maxy][maxz]

ll cuboid[6];
ll cube[6];

void solve()
{
    for (int j = 0; j < 3; j++)
    {
        //cube[j + 3] += cube[j];
        cuboid[j] = max(cuboid[j], cube[j]);
        cuboid[j + 3] = min(cuboid[j + 3], cube[j + 3]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < 3; i++)
        {
            cuboid[i] = -LLONG_MAX;
            cuboid[i + 3] = LLONG_MAX;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> cube[j];
            }
            cube[5] = cube[4] = cube[3];
            for (int j = 0; j < 3; j++)
            {
                cube[j + 3] += cube[j];
            }
            solve();
        }
        ll ans = 1;
        for (int i = 0; i < 3; i++)
        {
            ans *= max(0ll, cuboid[i + 3] - cuboid[i]);
        }
        cout << ans << '\n';
    }
}